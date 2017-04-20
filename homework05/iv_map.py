#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

import sys
import string
from unicodedata import category

line_num = 0
punctuation_exclude = [t for t in string.punctuation]
punctuation_exclude.append(unicode('“'))
punctuation_exclude.append('’')
for line in sys.stdin:
    line_num += 1
    for word in line.strip().split():
        filtered = "".join(c.lower() for c in word if c not in punctuation_exclude)
        print '{}\t{}'.format(filtered, line_num)

