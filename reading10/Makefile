CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
TARGETS = walk
SHELL = bash

all:	$(TARGETS)


walk.o: walk.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

walk: walk.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) *.o *.a *.log

test:
	@echo Testing walk...
	@diff <(./walk | sort) <(./walk.py | sort) > walk.log
	@[ `valgrind --leak-check=full ./walk 2>&1 | tee -a walk.log | grep ERROR | awk '{print $4}'` = 0 ] && ! grep -q 'failed' walk.log || cat walk.log
