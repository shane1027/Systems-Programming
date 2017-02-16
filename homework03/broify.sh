#!/bin/sh

# function to remove desired comments and lines

strip () {

    INPUT=$1
    DELIM=$3

    if [ $REMOVE_LINES -eq 1 ];then
        # strip the whitespace
        sed "/^\s*$/d"
    else
        cat
    fi
    
}

DELIM='#'
REMOVE_LINES=1

while [ $# -gt 0 ]; do

    case $1 in
        -d) DELIM=$2
            shift;;
        -W) REMOVE_LINES=0
            ;;
        -h)
            echo "Usage: broify.sh"
            echo "-d DELIM  Use this as the comment delimiter."
            echo "-W        Don't strip empty lines."
            exit 1
            ;;
        *)
            echo "Usage: broify.sh"
            echo "-d DELIM  Use this as the comment delimiter."
            echo "-W        Don't strip empty lines."
            exit 2
            ;;
    esac

    shift

done

sed -e "s|$DELIM.*$||" -e "s|\s*$||" | strip
