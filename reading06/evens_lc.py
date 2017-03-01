#!/usr/bin/env python2.7

import sys

print ' '.join([x.strip() for x in sys.stdin if int(x) % 2 == 0])
