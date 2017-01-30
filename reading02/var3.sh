#!/bin/sh

echo "I was called with $# parameters"
echo "My name is $0"

if [ $# -gt "0" ];then
    for i in $(seq 1 $#)    # generate a sequence 1 - variable #
    do
        echo "Parameter $i is ${!i}"     # this took way too long to figure out
        # the above is an example of indirect parameter expansion
    done
else
    echo "No parameters passed."
fi 

echo "All parameters are $@"
echo
echo "Using '$*' gives: $*"
