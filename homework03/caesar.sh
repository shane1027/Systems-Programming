#!/bin/sh

if [ "$1" = "-h" ]; then
    echo "Usage: caesar.sh [rotation]"
    echo
    echo "This program will read from stdin and rotate (shift right) the text
    by the specified rotation.  If none is specified, then the default value is
    13."

    exit 1


elif [ "$#" = "0" ]; then

    a=$(echo {a..z} | sed 's/ //g'| cut -c 1-13)
    A=$(echo {A..Z} | sed 's/ //g'| cut -c 1-13)
    b=$(echo {a..z} | sed 's/ //g'| cut -c 14-)
    B=$(echo {A..Z} | sed 's/ //g'| cut -c 14-)

    # switch the first 13 with the last thirteen, use as a mapping

    map=$b$a
    MAP=$B$A

    tr a-z $map | tr A-Z $MAP

else 

    input=$(($1%26))
    shift=$(($input+1))

    aa=$(echo {a..z} | sed 's/ //g' | cut -c 1-$shift )
    AA=$(echo {A..Z} | sed 's/ //g' | cut -c 1-$shift)
    bb=$(echo {a..z} | sed 's/ //g' | cut -c $shift-)
    BB=$(echo {A..Z} | sed 's/ //g' | cut -c $shift-)

    map=$bb$aa
    MAP=$BB$AA

    tr a-z $map | tr A-Z $MAP

fi

