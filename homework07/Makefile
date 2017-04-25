CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs
TARGETS=	lsort

all:		$(TARGETS)

# TODO: Add rules for liblist.a, test_node, test_list, lsort, and any intermediate objects

test_node:	test_node.o liblist.a
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

test_list:	test_list.o liblist.a
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

lsort:	lsort.o liblist.a
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

liblist.a:	list.o node.o
	@echo "Linking $@..."
	@$(AR) $(ARFLAGS) $@ $^

list.o:		list.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

node.o:		node.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

test_node.o: test_node.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

test_list.o:	test_list.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

lsort.o:	lsort.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

lsort.c:	node.h list.h

test_node.c:	node.h list.h

test_list.c:	node.h list.h

list.c:		node.h list.h

node.c:		node.h list.h

test:		test-node test-list test-lsort

test-node:	test_node
	@echo Testing node...
	@[ `valgrind --leak-check=full ./test_node 2>&1 | tee test_node.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_node.log

test-list:	test_list
	@echo Testing list...
	@[ `valgrind --leak-check=full ./test_list 2>&1 | tee test_list.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_list.log

test-lsort:	lsort test_lsort.sh
	@echo Testing lsort...
	@./test_lsort.sh

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) test_node test_list *.a *.o *.log *.input

.PHONY:		all test test-node test-list test-lsort clean
