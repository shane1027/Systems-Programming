#!/usr/bin/env python2.7

# simply print out the arguments to the script, if they are given
import sys
import os.path

if len(sys.argv) > 1 :
    while sys.argv[-1]:
        if len(sys.argv) < 2:
            break
        current = sys.argv.pop()
        if os.path.exists(current):
            print('%s exists!' % current)
        else:
            print('%s does not exist!' % current)
else:
    print('No Arguments Given!')
    exit()
