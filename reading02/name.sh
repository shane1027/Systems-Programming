#!/bin/sh

echo -en "What is your name [ `whoami` ] "  # -en means no newline char printed
    # the above command asks for user input but displays a default value to be
    # used if there is no user input.
read myname     # read the user input if there is any.
if [ -z "$myname" ]; then
    myname=`whoami`
    # check if user input was a zero length string
fi
echo "Your name is : $myname"


# A better implementation uses shell default variable value feature:

echo -en "Please enter your name again [ `whoami` ] "
read myname
echo "Your name is : ${myname:-`whoami`}"   # if myname is unset, use `whoami`
# the syntax ${myname:=`whoami`} sets the variable to `whoami` if its undefined

