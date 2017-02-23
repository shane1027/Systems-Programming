#!/bin/sh

# ethnic.sh

URL=https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/csv/demographics.csv

count_ethnic() {
    column=$(( (($1 - 2012)*2) ))	
    ethnic="$2"	

    cat demographics.csv | cut -d , -f $column | sed '/^$/d' | sort | grep -ce "$2"
}

curl -s $URL > demographics.csv

for year in $(seq 2013 2019); do
    echo $year $(count_ethnic $year C) \
    	       $(count_ethnic $year O) \
    	       $(count_ethnic $year S) \
    	       $(count_ethnic $year B) \
    	       $(count_ethnic $year N) \
    	       $(count_ethnic $year T) \
    	       $(count_ethnic $year U)
done
