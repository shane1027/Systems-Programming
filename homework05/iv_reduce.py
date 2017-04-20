#!/usr/bin/env  python2.7
# -*- coding: utf-8 -*-

import sys
import string

counts = {}
for line in sys.stdin:
    k, v  = line.rstrip().split('\t', 1)
    new_list = counts.get(k, list())
    new_list.append(v)
    counts[k] = new_list

for k, v in sorted(counts.items()):
    print '{}\t'.format(k),
    pool = set()
    for t in v:
        if t not in pool:
            print '{}'.format(t),
            pool.add(t)
    print ''
