#!/usr/bin/env python2.7

import os, subprocess

COMMAND_MSORT = 'shuf -i1-{} -n {} | ./measure ./lsort -n > /dev/null'
COMMAND_QUICK = 'shuf -i1-{} -n {} | ./measure ./lsort -n -q > /dev/null'

print '| NITEMS |  SORT  |  TIME |  SPACE |'
print '|--------|--------|-------|--------|'

for item in range(7):
    print '| {} |  MERGE |'.format(10**item),
    os.popen(COMMAND_MSORT.format(10**item, 10**item))

    print '{} |  QUICK |'.format(10**item)
    os.popen(COMMAND_QUICK.format(10**item, 10**item))

