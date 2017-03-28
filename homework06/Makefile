CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs

TARGETS=	libstringutils.a \
		libstringutils.so 	\
		translate-static	\
		translate-dynamic

all:		$(TARGETS)

# TODO: Add rules for libstringutils.a libstringutils.so
libstringutils.a:	stringutils.o
	$(AR) $(ARFLAGS) $@ $^

libstringutils.so:	stringutils.o
	$(LD) $(LDFLAGS) -shared -o $@ $^

stringutils.o:	stringutils.c
	$(CC) -c -fPIC $(CFLAGS) -o $@ $^ 

translate-static:	translate.o
	$(LD) $(LDFLAGS) -static -o $@ $^ -lstringutils

translate-dynamic:	translate.o
	$(LD) $(LDFLAGS) -o $@ $^ -lstringutils

test:			test-libstringutils test-translate

test-libstringutils:	libstringutils.so test_stringutils.py
	./test_stringutils.py -v

test-translate:			translate-static translate-dynamic test_translate.py
	./test_translate.py -v

clean:
	rm -f $(TARGETS) *.o
