# -*- coding: utf-8 -*-
import os

print "Content-type: text/html; charset=utf-8\n\n"
print "<h1>Segue abaixo todas as variáveis de ambiente deste servidor.</h1><br/>"
for param in os.environ.keys():
   print "<b>%20s</b>: %s<br/>" % (param, os.environ[param])