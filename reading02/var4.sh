#!/bin/sh

while [ "$#" -gt "0" ]
do
    echo "\$1 is $1"
    shift
done

# this allows us to accept more than 9 input arguments and still be able to
# address all of them using $1 - $9.  'Shift' moves each variable down a
# number, so the tenth input becomes addressable as $9 
