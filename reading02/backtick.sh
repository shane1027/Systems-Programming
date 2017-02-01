#!/bin/sh

# example of two approaches to the same problem that illustrates effective use
# of the backtick when entering commands into the shell

# slow example:
time %e "find ~/scratch/ -name "*.txt" -print | grep "/file1.txt";find
~/scratch/ -name "*.txt" -print | grep "/hello.txt""
# the above has to run the 'find' external program twice

# faster way, using backtick and variable to run the find external prog once
time %e "TXT_FILES=`find ~/scratch/ -name "*.txt" -print` \\
echo "$TXT_FILES" | grep "/file1.txt" \\
echo "$TXT_FILES" | grep "/hello.txt""
# now we should be a bit faster


