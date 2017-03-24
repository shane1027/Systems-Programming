CC=             gcc
CFLAGS=         -g -gdwarf-2 -Wall -std=gnu99
TARGETS=        sort grep

all:            $(TARGETS)

# TODO: Add rules for sort and grep

sort:			sort.c
		$(CC) $(CFLAGS) -o $@ $^ 

grep:			grep.c
		$(CC) $(CFLAGS) -o $@ $^ 

test:           test_sort.sh test_grep.sh
		./test_sort.sh
		./test_grep.sh

test_sort.sh:
		curl -O http://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/sh/test_sort.sh
		chmod +x $@

test_grep.sh:
		curl -O http://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/sh/test_grep.sh
		chmod +x $@

clean:
		rm -f $(TARGETS)
