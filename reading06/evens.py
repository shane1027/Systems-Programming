#!/usr/bin/env python2.7

import sys

results = []
for number in sys.stdin:        # read stdin line by line
    number = number.strip()     # remove whitespace @ begin and end
    if int(number) % 2 == 0:    # modulo 2 == 0, true if even
        results.append(number)  # add result to list

print ' '.join(results)
