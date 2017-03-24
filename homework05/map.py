#!/usr/bin/env python2.7

import sys

for line in sys.stdin:
    for word in line.strip().split():
        print '{}\t{}'.format(word, 1)

