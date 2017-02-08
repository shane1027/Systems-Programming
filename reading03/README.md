Reading 03
==========

**1.)** Convert all the input text to upper case:

`echo "All your base are belong to us" | tr '[:lower:]' '[:upper:]'`


**2.)** Find and replace all instances of monkeys to gorillaz:

`echo "monkeys love bananas" | sed s/monkeys/gorillaz/`


**3.)** Remove any leading whitespace from a string of text:

`echo "     monkeys love bananas" | sed "s/^[ ]*//"`


**4.)** Parse the /etc/passwd file for the shell of the root user:

`cat /etc/passwd | grep -e "root" | awk '{print $7}' FS=":"`


**5.)** Find and replace all instances of /bin/bash, /bin/csh, and /bin/tcsh to
/usr/bin/python in /etc/passwd:

`cat /etc/passwd | sed -r "s/(bash|csh|tcsh)$/python/" | grep python`

    (note the use of -r for extended regular expressions --> allows '( | )' )


**6.)** Find all the records in /etc/passwd that have a number that begins with
a 4 and ends with a 7:

`cat /etc/passwd | grep -e "4.*7"`


**7.)** Given two text files, show all the lines that are present in both
files.

`comm -12 file1.txt file2.txt`


**8.)** Given two text files, show which lines are different.

`comm -3 file1.txt file2.txt | sed "s/^[\t]*//"`




