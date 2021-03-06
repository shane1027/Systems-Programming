Reading 01
==========


### Question 1

**a.)** The purpose of the pipe symbol in the given command is to redirect the output of 'du -h /etc/' to the input of the sort command rather than to stdout.

**b.)** '2> /dev/null' redirects the errors on stderr from 'du -h /etc' to the bit bucket, effectively destroying / suppressing them.

**c.)** '> output.txt' creates output.txt (or overwrites it from the beginning if it already exists) and redirects stdout from the 'sort -h' command to write to the output.txt file instead. 

**d.)** '-h' formats the output in a human-friendly manner.

**e.)** The command given here is NOT the same as the original, because now we are using the '2> /dev/null' after the sort command.  The errors from 'du -h /etc' will now be displayed on stdout, and the errors from 'sort -h' will be suppressed.


### Question 2

**a.)** 'cat 2002-\*\* > combined2002' 

**b.)** 'cat 200\*-12 > combined12' 

**c.)** 'cat 200\*-0{1...10}'

**d.)** 'cat 200{2,4,6}-{01,03,05,07,09,11}'

**e.)** 'cat 200{2...4}-{09...12}'


### Question 3

**a.)** Huxley and Tux

**b.)** Huxley

**c.)** None

**d.)** 'chmod 755 Tux'

**e.)** 'chmod 600 Tux'


### Question 4

**a.)** Suspend the process with ctrl+z.

**b.)** Resume the process by executing 'fg'.

**c.)** Send the EOF character / command using ctrl+d.

**d.)** Switch to bc using 'fg', and send the interrupt signal with ctrl+c.

**e.)** Run 'ps ux', note the PID of 'bc', and then run 'kill -kill {PID}'




