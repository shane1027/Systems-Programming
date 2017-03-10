#!/usr/bin/env python2.7

import os
import sys
import re

usernames = []

for line in open('/etc/passwd'):
    print line
    info = ":".join(line.split())
    try:
        usernames.append(re.findall('(.*):.*', info)[0])
    except IndexError as e:
        pass

    print usernames
