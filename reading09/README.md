Reading 09
==========

## 1. Given the C code below:

```
struct Struct {
    char *  string;
    int     number;
};

union  Union {
    char *  string;
    int     number;
};

struct Struct s;
union  Union  u
```

#### What is the size of s and what is the size of u?

's' is 16 bytes, while 'u' is 8.

#### What is the difference between a union and a struct?

Memory allocation - a struct allocates enough memory to store each of it's 
values simultaneously, while a union only allocates enough memory to store it's
largest value.  Because of this, a union can only store one value accurately at
a time while a struct can store all of it's intended values accurately at once.



## 2. Given the C code below:

```
/* message.c */

#include <stdio.h>
#include <stdlib.h>

union Value {
    char    as_c;
    short   as_s;
    int     as_i;
    long    as_l;
};

struct Thing {
    union Value v0;
    union Value v1;
    union Value v2;
};

#define DUMP_BITS(_v) \
    for (int i = sizeof(_v)*8 - 1; i >= 0; i--) {\
        if ((i + 1) % 8 == 0) putc(' ', stdout); \
        putc(((_v).as_l & 1UL<<i) ? '1' : '0', stdout); \
    } \
    putc('\n', stdout);

int main(int argc, char *argv[]) {
    struct Thing t = {0};

    t.v0.as_i  = 0x65746166;
    t.v0.as_l |= (544434464UL << 32);

    t.v1.as_l  = (0x6261726FUL << 32);
    t.v1.as_i  = ((673304440UL * 3 + 1));

    t.v2.as_l  = 0xA210000;
    t.v2.as_s  = 25856;
    t.v2.as_c  = 108;

    char *s = (char *)&t;
    for (size_t i = 0; i < sizeof(struct Thing); i++) {
        putc(s[i], stdout);
    }

    return 0;
}
```

#### What message does this program output?

##### Note: this is only guaranteed to work on a 64-bit Linux machine like the student machines.

It prints the message 'fate is inexorable!'

#### Use the DUMP_BITS macro to explore this program and then explain how it works (that is, how does setting the values above in the struct Thing t object yield the final message).

/* Use DUMP_BITS macro to view the binary contents of t.v0 */
DUMP_BITS(t.v0)

First a union is defined which contains types char, short, int, and long.  Then
a struct is defined to contain three of the previously defined unions.  Since
the unions contain a type long, each is 8 bytes in memory.  Thus one instance
of the struct containing three unions takes up 24 bytes.

The message 'fate is inexorable!' is 19 characters long, plus a newline char
and a NULL char to define the end of the string.  Thus this string fits inside
the memory defined to hold the struct of unions.

Now, since the representation of a char takes one byte, and inherently thus
represented by 8 bits, one integer of 4 bytes could store 4 char's numerical
data.  If the proper number is stored as an int (or long for 8 chars) and
accessed as a char using a type cast, then the dereferenced pointer to what was
originally an int is now seen as a char and the data won't be cruft - it will
be whatever was intended as ASCII tables dictate.

Thus, the proper ASCII representations of the chars to hold the string printed
below were loaded into various parts of memory in the struct holding 3 unions
in various obfuscated ways, and a pointer to char at the beginning allowed the
compiler to address all the data as a sequence of characters.

#### What does this program tell you about types, memory, and how data is represented in C? What are we really doing when we cast values in C?

This tells me that types are simply a method of data organization and
standardization handled at the compiler level, and whatever is in a certain
place in data is interpreted in a certain way depending on what type the
compiler thinks it is.  The actual data is all the same, and can be referenced
as a different type.  Memory is contiguous and doesn't discriminate against
what types it's holding.  And data is represented in a uniform manner at the
file register level, but the types are handled by the (compiler?) rather than
encoding what type a piece of data represents in the memory itself.  Therefore
casting a value in C simply changes what the compiler thinks is stored at that
location, and doesn't actually manipulate any of the memory surrounding it.


## 3. A hash table can be classified by how it handles collisions:

#### What exactly is a collision?

A collision is when a hash function generates the same index for more than one
input key.  Hash functions should ideally have a one-to-one mapping between the
key space and index space (linear algebra terms!).

#### How are collisions handled in a hash table that uses separate chaining?

Separate chaining fills consecutive spots within the 'bucket' located at an
index of the hash table, so if two or more keys are hashed to the same index
value, they fill the bucket and are checked against a given key during lookup.

#### How are collisions handled in a hash table that uses open addressing (e.g. linear probing)?

When a key is added to the hash table, the key is hashed and the bucket at that
index location is examined.  If it is already full, another bucket (possibly
the next adjacent one, possibly one determined through another hash function)
is used instead.  Entries are stored as 'buckets' so no additional lookup needs
to take place once the proper key is found during lookup (although a few
buckets may need to be traversed if collisions had occurred effecting that
key's position).

Note: In both methods, order of adding things to the hash table does
effect performance of lookup (since multiple list entries or buckets must be
traversed), but one can sort the entries in a list or use a binary tree in
separate chaining whereas the order of lookup for collided keys cannot easily
be manipulated in an open addressing scheme.

Open addressing = closed hashing, closed addressing = open hashing = sep. chain


## Fill the following hash table using separate chaining and then open addressing given: 

## 7, 3, 2, 78, 56, 72, 79, 68, 13, 14

## And using hash function `h(x) = x % 10`.

Separate Chaining:

| Bucket |	Value | Array of Integers |
|:------:|:------:|:-----------------:|
|0		 |`*int 0`|		`[]`		  |
|1		 |`*int 1`|	`[]`			  |
|2		 |`*int 2`|		'[2, 72]'	  |
|3		 |`*int 3`|	'[3, 13]'		  |
|4		 |`*int 4`|	'[14]'			  |
|5		 |`*int 5`|		`[]`		  |
|6		 |`*int 6`|		'[56]'		  |
|7		 |`*int 7`|	`[7]`			  |
|8		 |`*int 8`|	'[78, 68]'		  |
|9		 |`*int 9`|	'[79]'			  |

Open Addressing:

| Bucket |	Value |
|:------:|:------:|
|0		 |`68`	  |
|1		 |`14`	  |
|2		 |`2`	  |
|3		 |`3`	  |
|4		 |`72`	  |
|5		 |`13`	  |
|6		 |`56`	  |
|7		 |`7` 	  |
|8		 |`78`	  |
|9		 |`79`	  |







