#!/bin/sh

# gender.sh

URL="https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/csv/demographics.csv"

count_gender() {
    column=$(( (($1 - 2012)*2)-1 ))	
    gender="$2"

    # total = `awk "{print $(( $column * 2 - 1 )) $(( $column * 2 ))}"`
    # use `cut` to manipulate columns of data

    cat demographics.csv | cut -d , -f $column | sed '/^$/d' | sort | grep -ce "$2"

    # TODO extract gender data for specified year and group
}

curl -s "$URL" > demographics.csv


# -s suppressses the progress bar output in order to avoid terminal output
# clutter

for year in $(seq 2013 2019); do
    echo $year $(count_gender $year F) $(count_gender $year M)
done
