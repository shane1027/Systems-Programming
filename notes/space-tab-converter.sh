#!/bin/sh

TARGET='space'
WIDTH=4

usage() {

    cat << EOF

    Usage: $(basename $0)

    -t TARGET       Specifies the target conversion (spaces or tabs)
    -w WIDTH        Specifies how many spaces per tab

EOF

    exit $1

}

while [ $# -gt 0 ]; do
    case $1 in
        -t)     TARGET=$2 shift ;; 
        -w)     WIDTH=$2 shift ;;
        -h)     usage 0 ;;
        *)      usage 1 ;;
    esac
    shift
done

SPACES=""
for i in $(seq $WIDTH)

    ###  look in the pbui public folder for lecture 8 for more

