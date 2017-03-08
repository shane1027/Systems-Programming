#!/bin/sh
#
# usage: ./pass_script (length of passwords) (directory to save)

num=$(($1-1))

for letter in $(echo "abcdefghijklmnopqrstuvwxyz0123456789" | grep -o .)
do
    echo "Cracking $1 letter passwords starting with $letter..."
    python hulk.py -l $num -p $letter -c 12 > $2/pass$1_$letter.txt
done
