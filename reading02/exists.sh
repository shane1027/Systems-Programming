#!/bin/sh

exists()
{
    if [ -e "$1" ]; then
        echo "$1 exists!"
    else
        echo "$1 does not exist!"
        return 1
    fi
}


if [ -n "$1" ]; then
    for i in $(seq 1 $#)
    do
        exists ${!i}
#        EXISTS_RETURN_CODE=$?
#        if [ "$EXISTS_RETURN_CODE" -eq "1" ]; then
#            echo "Error! Not found!"
#        fi
    # at first I thought the assignment wanted us to act on this error code.
    done
else
    echo "Error: you should gimme some arguments."
    exit 1
fi
