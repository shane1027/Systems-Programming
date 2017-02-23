#!/usr/bin/env python2.7


import os
import sys

# Global Variables

ENDING = ''

# Usage function

def usage(status=0):
    print '''Usage: {} files...

    -E  display $ at end of each line'''.format(os.path.basename(sys.argv[0]))
    sys.exit(status)

# Parse command line options

args = sys.argv[1:]
while len(args) and args[0].startswith('-') and len(args[0]) > 1:
#   ^^^args list has an item, which starts with hyphen, and is of non-zero len
    arg = args.pop(0)
    if arg == '-E':
        ENDING = '$'
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

    for line in stream:
        line = line.rstrip()
        print line + ENDING

    stream.close()
