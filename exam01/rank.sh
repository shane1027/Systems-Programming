#!/bin/sh

# rank.sh   -   rank items from STDIN numerically, and output the first N items

usage() {

    cat << EOF
Usage: rank.sh [-n N -D]

    -n N    Returns N items (default is 5).
    -D      Rank in descending order.
EOF

    exit 1

}

NUM_ITEMS=5
DIRECTION=1

while [ $# -gt 0 ]; do
    case $1 in
        -n) NUM_ITEMS="$2" 
            shift
            ;;
        -D) DIRECTION=0
            ;;
        *)  usage
            ;;
    esac
    shift
done


if [ $DIRECTION -eq 1 ]; then
    sort -n | head -n $NUM_ITEMS
else 
    sort -nr | head -n $NUM_ITEMS
fi





