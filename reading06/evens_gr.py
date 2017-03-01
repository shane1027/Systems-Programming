#!/usr/bin/env python2.7

import sys

def evens(stream):
    for line in stream:
        line = line.strip()
        if int(line) % 2 == 0:
            yield line


print ' '.join(evens(sys.stdin))
