#!/usr/bin/env python2.7

import os

for name in os.listdir('.'):
    if os.path.isfile(name):
        print name, os.path.getsize(name)
