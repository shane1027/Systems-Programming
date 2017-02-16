#!/bin/sh

# function to find every zipcode on the page

all_zips() {

    if [ -n "$CITY" ]; then
        sed -En "s|.*www\.zipcodestogo\.com/$CITY/\w+/(.*)/\".*|\1|p"
    else
        sed -En 's|.*www\.zipcodestogo\.com/.*/\w+/(.*)/".*|\1|p'
    fi

    # Note - Use double quotes in order to get variable to expand
    #   Single quotes pass their content literally!

}

# print out usage message

usage() {

    cat << EOF
Usage: zipcode.sh

  -c      CITY    Which city to search
  -f      FORMAT  Which format (text, csv)
  -s      STATE   Which state to search (Indiana)

If not CITY is specified, then all the zip codes for the STATE are displayed.
EOF

exit 0

}

# adjust the output format of the matched zipcodes

format() {

    case $FORMAT in
        text)   cat;;
        csv)    paste -d, -s -;;
        *)      echo "invalid format!"
                exit 1;;
    esac

    # paste is a great utility for merging lines of files.  -d is the
    # delimiter, which is TAB by default, and -s is the file ('-' means stdin)

}


STATE="Indiana"
FORMAT="text"

while [ $# -gt 0 ]; do
    case $1 in
        -c) CITY="$2"
            shift
            ;;
        -f) FORMAT=$2
            shift
            ;;
        -s) STATE="$2"
            shift
            ;;
        *)  usage;;
    esac
    shift
done



curl -s http://www.zipcodestogo.com/"$STATE"/ | all_zips | sort | uniq | format

# realizing the darned double quotes around $STATE above were needed was a pain



