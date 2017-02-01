#!/bin/sh

# This script explores changing the IFS - Internal Field Separator

old_IFS="$IFS"  # save the current IFS to restore upon exit
IFS=:   # change the IFS to a colon just for fun
echo "Please input three data separated by colons..."
read x y z
IFS=$old_IFS
echo "x is $x y is $y z is $z"
