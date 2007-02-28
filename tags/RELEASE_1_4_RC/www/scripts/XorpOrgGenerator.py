#!/usr/bin/env python

import getopt, re, sys, time

# nav bar tree
xorp_links = [
# --
    ("XORP Project", ""),
    ("Home", "index.html"),
    ("The XORP Vision", "xorp_vision.html"),
    ("Roadmap", "roadmap.html"),
    ("News", "news.html"),
# --
    ("Getting XORP", ""),
    ("Download Live CD", "livecd.html"),
    ("Download Code", "downloads.html"),
    ("Mirror Sites", "mirrors.html"),
    ("Browse Code", "http://xorpc.icir.org/cgi-bin/cvsweb.cgi/xorp/"),
    ("Software Status", "status.html"),
    ("Security Advisories", "advisories.html"),

# --
    ("Documentation", ""),
    ("Getting Started", "getting_started.html"),
    ("User Manual (PDF)", "releases/current/docs/user_manual/user_manual.pdf"),
    ("Frequently Asked Questions", "faq.html"),
    ("Design Documentation", "design_docs.html"),
    ("Papers", "papers.html"),
    ("API Documentation", "releases/current/docs/kdoc/html/index.html"),
    ("Porting Guide", "porting.html"),

# --
    ("Community", ""),
    ("Contributing", "contributing.html"),
    ("Operating a mirror", "mirror_operation.html"),
    ("Developers", "people.html"),
    ("Source Repository", "cvs.html"),
    ("Mailing Lists", "mailing_lists.html"),
    ("Bug Reporting", "http://www.xorp.org/bugzilla/index.cgi")
    ]

def usage():
    print "www.xorp.org-gen.py -d <directory> <source_html>file>"
    sys.exit(0)

def write_navbar(filename):
    open_div("navbar")
    write_navbar_depth(filename, 1, xorp_links)
    close_div("navbar")

def listify(links, type="ul"):
    if len(links) == 0:
        return
    links.insert(0, "<%s>" % type)
    links.append('</%s>' % type)
    for l in links:
        print l
    links = []

def write_navbar_depth(filename, depth, links):
    lx = []
    for l in links:
        desc, url = l
        if filename == url:
            style = ' id="selected"'
        else:
            style = ''

        if len(url) == 0:
            listify(lx, 'dl')
            lx = [ "<dt>%s</dt>" % desc ]
        else:
            lx.append("<dd %s><a href=\"%s\">%s</a></dd>" % (style, url, desc))
    listify(lx, 'dl')

def open_div(name):
    print "<div id=\"%s\">" % name

def close_div(name):
    print "</div> <!-- end of div id=\"%s\" -->" % name

def write_main_begin():
    open_div("main");

def write_main_end():
    print "<hr noshade>"
    open_div("feedback")
    print "<p><em>Document id $XORP: www/scripts/XorpOrgGenerator.py,v 1.13 2006/03/18 20:11:55 atanu Exp $."
    print "<br>Generated on %s.</em>" \
          % time.strftime('%d/%b/%Y at %H:%M:%S')
    print "<em>Feedback, comments, flames to feedback&#64;xorp&#46;org</em>"
    close_div("feedback")
    close_div("main")

def write_header(headextras = []):
    print """<!-- $XORP: www/scripts/XorpOrgGenerator.py,v 1.13 2006/03/18 20:11:55 atanu Exp $ -->
    <!-- DO NOT EDIT THIS FILE . IT IS GENERATED BY A SCRIPT -->

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd">
<html>

<head>
<meta content="text/html; charset=iso-8859-1" http-equiv="Content-Type">
<link rel="stylesheet" type="text/css" href="xorp.css">
"""
    for item in headextras:
        print item
    print"""</head>

<body>
"""
    open_div("container")
    open_div("header")
    print """<a href="http://www.xorp.org"><img src="images/xorp-logo-medium.jpg" ALT="XORP Logo" border=0></a>"""
    close_div("header")
    open_div("middle")

def write_footer():
    close_div("middle")
    close_div("container")
    print"""
</body>
</html>"""

if __name__ == '__main__':
    srcdir = "."

    try:
        opts, args = getopt.getopt(sys.argv[1:], "d:")
    except getopt.GetoptError:
        usage()

    if len(args) == 0:
        usage()

    for o in opts:
        if o[0] == '-d':
            srcdir = o[1].rstrip('/')

    title_matcher = re.compile(r'<[Hh]1>(.*)</[hH]1>')

    for filename in args:
        src_filename = "%s/%s" % (srcdir, filename)
        dst_filename = filename

        lines = []
        header_extras = []
        input = open(src_filename, 'r')
        for line in input:
            lines.append(line)
            m = title_matcher.match(line)
            if m:
                header_extras.append("<title>%s</title>" % m.group(1))
        input.close()

        saveout = sys.stdout
        out = open(dst_filename, 'w')

        sys.stdout = out
        write_header(header_extras)
        write_navbar(dst_filename)
        write_main_begin()
        for line in lines:
            print line,
        write_main_end()
        write_footer()

        out.close()
        sys.stdout = saveout


