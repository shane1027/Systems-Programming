#!/usr/bin/env python2.7

import requests
import re

URL='http://yld.me/aJt?raw=1'

requests = requests(URL)
data = request.text

matching = re.findall('[0-9]{3}-[0-9]{3}-[0-9]{3}[13579]', data)

for num in matching:
    print matching




#s aux awk print 1 sort uniq wc -l


