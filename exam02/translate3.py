#!/usr/bin/env python2.7

import re
import sys

for line in sys.popen('ps -aux'):
    firstvar = re.findall('(.*)\t', line)

