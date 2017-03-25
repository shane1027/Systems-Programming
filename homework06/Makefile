CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99 -lm
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs

TARGETS=	libstringutils.a \
		libstringutils.so

all:		$(TARGETS)

# TODO: Add rules for libstringutils.a libstringutils.so
libstringutils.a:	stringutils.o
	$(AR) $(ARFLAGS) $@ $^

libstringutils.so:	stringutils.o
	$(LD) $(LDFLAGS) -shared -o $@ $^

stringutils.o:	stringutils.c
	$(CC) -c -fPIC $(CFLAGS) -o $@ $^ 

test:			test-libstringutils

test-libstringutils:	libstringutils.so test_stringutils.py
	./test_stringutils.py -v

clean:
	rm -f $(TARGETS) *.o
