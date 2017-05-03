#!/usr/bin/env python2.7

import socket
import sys

# Parse command line options
try:
    HOST = sys.argv[1]
    PORT = int(sys.argv[2])
except IndexError:
    print >>sys.stderr, "Usage: {} HOST PORT".format(sys.argv[0])
    sys.exit(1)

# Create socket and connect to specified HOST and PORT
csocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
csocket.connect((HOST, PORT))
cstream = csocket.makefile('w+')

# Read from stdin and write to socket
for line in sys.stdin:
    cstream.write(line)

# Cleanup
csocket.close()
