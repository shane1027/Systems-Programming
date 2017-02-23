#!/usr/bin/env python2.7

# print out the first 'n' lines of an input
import os
import sys

# Global Variables

NUM_LINES = 10

# Usage function

def usage(status=0):
    print '''Usage: {} files...

        -n  NUM      print the first NUM lines instead of the first
        10'''.format(os.path.basename(sys.argv[0]))
    sys.exit(status)

# Parse command line options

args = sys.argv[1:]
while len(args) and args[0].startswith('-') and len(args[0]) > 1:
#   ^^^args list has an item, which starts with hyphen, and is of non-zero len
    arg = args.pop(0)
    if arg == '-n':
        NUM_LINES = int(args.pop(0))
    elif arg == '-h':
        usage(0)
    else:
        usage(1)

if len(args) == 0:
    args.append('-')

# Main execution

for path in args:
    if path == '-':
        stream = sys.stdin
    else:
        stream = open(path)

    # Read the lines of the file into a list of strings
    output = stream.readlines()

    # now iteratively print the desired strings (first NUM_LINES)
    for num in output[0:NUM_LINES]:
        line = num.rstrip()
        print line

    stream.close()
