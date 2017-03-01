#!/usr/bin/env python2.7

import sys

print ' '.join(filter(lambda x: int(x) % 2 == 0, map(lambda x: x.strip(), sys.stdin)))
