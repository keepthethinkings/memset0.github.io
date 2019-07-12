#!/usr/bin/python
# -*- coding: UTF-8 -*-

import re

menu = re.split(" ", open("ini/menu.txt", "r+").read())
print(menu)

name_ = re.split("\n", open("ini/name.txt", "r+").read())
print(name_)
name = []
for i in name_ :
    name.append(re.split(" ", i))
print(name)

nl = len(name)
ml = len(menu)
nav = open("ini/nav.txt", "w+", encoding='utf-8')
for i in range(1, ml) :
    nav.write("<a class=\"collapsed waves-attach waves-effect\" data-toggle=\"collapse\" href=\"#%d\"><strong>%s</strong></a>\n" % (i, menu[i]))
    nav.write("<ul class=\"menu-collapse collapse in\" id=\"%d\">\n" % i)

    for j in range(nl) :
        if name[j][2] == menu[i] :
            nav.write("<li><a class=\"waves-attach\" href=\"/a/%s/\">%s</a></li>\n" % (name[j][0], name[j][1]))
    nav.write("</ul>\n")
nav.close()

nav_ = open("ini/nav.txt", "rb")
nav = nav_.read()
nav_.close()

p1_ = open("ini/p1.txt", "rb")
p1 = p1_.read()
p1_.close()

p2_ = open("ini/p2.txt", "rb")
p2 = p2_.read()
p2_.close()

p3_ = open("ini/p3.txt", "rb")
p3 = p3_.read()
p3_.close()

for i in range(0, nl - 1) :
    r = open("a/%s/%s.short" % (name[i][0], name[i][1]), "rb")
    if name[i][2] == "homepage" :
        w = open("%s.html" % (name[i][1]), "wb")
    elif name[i][2] == "tools" :
        w = open("tools/%s/index.html" % (name[i][1]), "wb")
    else :
        w = open("a/%s/index.html" % (name[i][0]), "wb")
    rr = r.read()
    w.write(p1)
    w.write(nav)
    w.write(p2)
    w.write(rr)
    w.write(p3)
    r.close()
    w.close()