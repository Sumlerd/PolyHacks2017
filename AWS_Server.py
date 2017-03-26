import socket
import threading
import time
bind_ip = "0.0.0.0"
bind_port = 5014
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((bind_ip,bind_port))
server.listen(1)
print "[*] Listening on %s:%d" % (bind_ip,bind_port)
# this is our client-handling thread

flagtoSend = 0
flagAlex = 1
data = ""

def handle_client(client_socket):
        # print out what the client sends

        request = client_socket.recv(1024)

        if(flagtoSend == 1):
           time.sleep(1)
           global data
           print "math data %s" % data
           client_socket.send(data)
           global flogtoSend
           flagtoSend = 0
           global flagAlex
           flagAlex = 0

        print "[*] Received: %s" % request
        print "flag = %s " % flagtoSend
        if (request[0]=='1'):
          data = request[1:]
          print data
          global flagtoSend
          flagtoSend = 1
          print "flag in if %s"  % flagtoSend
        # send back a packet
          global flagAlex
