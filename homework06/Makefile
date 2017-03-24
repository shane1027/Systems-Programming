CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs

TARGETS=	libstringutils.a \
		libstringutils.so

all:		$(TARGETS)

# TODO: Add rules for libstringutils.a libstringutils.so

test:			test-libstringutils

test-libstringutils:	libstringutils.so test_stringutils.py
	./test_stringutils.py -v

clean:
	rm -f $(TARGETS) *.o
