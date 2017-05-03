CC	= gcc
CFLAGS 	= -g -gdwarf-2 -Wall -std=gnu99
LD 	= gcc
LDFLAGS	= -L.
TARGETS	= ncat
SHELL= bash

all:	$(TARGETS)

ncat.o: ncat.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

ncat:	ncat.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

clean:
	@echo Cleaning...
	@rm -r $(TARGETS) *.o 
	
