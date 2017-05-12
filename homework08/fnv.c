/* fnv.c: fnv hash function */

#include "map.h"

// http://isthe.com/chongo/tech/comp/fnv/

#define FNV_OFFSET_BASIS    (0xcbf29ce484222325ULL)
#define FNV_PRIME           (0x100000001b3ULL)

/**
 * Compute FNV-1 hash.
 * @param   d               Data to hash.
 * @param   n               Number of bytes in data.
 * @return  Computed hash.
 */
uint64_t	fnv_hash(const void *d, size_t n) {
    /* type cast the pointer to the data so that we can iterate through in
     * nibbles using pointer increments rather than logical shifts of 4    */
    unsigned char *s = (unsigned char *) d;
    uint64_t hash = FNV_OFFSET_BASIS;

    for (int i = 0; i < n; i++) {
        hash ^= (uint64_t)*s++;
        hash *= FNV_PRIME;
    }

    return hash;
}

    /* the following was my second attempt... not sure why it doesn't work

    uint64_t hash = FNV_OFFSET_BASIS;

    uint data = *(uint *)d;
    uint8_t data_byte;

    for (int i = 0; i < n; i++) {
        data_byte = (data >> 8*i) & 0xFF;       // extract one byte
        hash ^= data_byte;              // XOR first
        hash *= FNV_PRIME;              // multiply second
    }

    return hash;
} */



    /*          old implementation  - first attempt
    uint64_t hash= FNV_OFFSET_BASIS;
    char total[64] = {0};

    uint data = *(int *)d;
    uint8_t data_byte;
    */
    
    /* I think this only works on 64 bit input data too???

    for (int i = n-1; i >= 0; --i) {
        data_byte = ((data >> 8*i) & 0xFF);     // use the bottom 8 bits
        hash ^= data_byte;          // should only modify the bottom 8 bits
        hash *= FNV_PRIME;          // returns 64 bits of the multiplication

        total[i] = hash & 0xFF;

        total[2*i] = hash >> 4;     // giveth the most significant 4 bits
        total[3*i+1] = hash & 0x0F; // now the rest 
    }
    return *(uint64_t *)total;
    */

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
