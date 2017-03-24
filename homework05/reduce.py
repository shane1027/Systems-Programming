#!/usr/bin/env python2.7

import sys

counts = {}
for line in sys.stdin:
    k, v  = line.split('\t', 1)
    counts[k] = counts.get(k, 0) + int(v)

for k, v in sorted(counts.items()):
    print '{}\t{}'.format(k, v)
