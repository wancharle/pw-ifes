#!C:\python27\python
 
import BaseHTTPServer
import CGIHTTPServer
import cgitb; cgitb.enable()  ## This line enables CGI error reporting
 		
server = BaseHTTPServer.HTTPServer
handler = CGIHTTPServer.CGIHTTPRequestHandler
server_address = ("", 80)
handler.cgi_directories = ["/actions"]
 
httpd = server(server_address, handler)
httpd.serve_forever()