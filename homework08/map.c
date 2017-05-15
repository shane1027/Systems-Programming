/* map.c: separate chaining hash table */

#include "map.h"
#include <errno.h>

/**
 * Create map data structure.
 * @param   capacity        Number of buckets in the hash table.
 * @param   load_factor     Maximum load factor before resizing.
 * @return  Allocated Map structure.
 */
Map *	        map_create(size_t capacity, double load_factor) {
    /*  Allocate a new map  */
    Map * new_map = malloc(sizeof(Map));

    //debug("got a map");

    if (new_map == NULL) {
        fprintf(stderr, "Couldn't allocate memory :/ : %s\n", strerror(errno));
        free(new_map);
        exit(EXIT_FAILURE);
    }

    if (capacity < 1) 
        capacity = DEFAULT_CAPACITY;

    /* Allocate an array full of entry structures for bucket    */
    Entry * buckets = malloc(sizeof(Entry)*capacity);
    Value dummy_value = { .number = 42 };
    char dummy_key[BUFSIZ];
    
    //debug("got a bucket");

    for (int i = 0; i < capacity; i++) {
        sprintf(dummy_key, "%d", i);
        //Entry * tmp = entry_create(dummy_key, dummy_value, NULL, NUMBER);
        buckets[i].key = strdup(dummy_key);
        buckets[i].value = dummy_value;
        buckets[i].type = NUMBER;
        buckets[i].next = NULL;
        //entry_delete(tmp, false);
    }

    //debug("got some entries");

    /* okay now fill up that map struct   */
    if (load_factor < 1)
        new_map->load_factor = DEFAULT_LOAD_FACTOR;
    else
        new_map->load_factor = load_factor;

    new_map->capacity = capacity;

    new_map->size = 0;

    new_map->buckets = buckets;

    return new_map;
}

/**
 * Delete map data structure.
 * @param   m               Map data structure.
 * @return  NULL.
 */
Map *	        map_delete(Map *m) {
    for (int i = 0; i < m->capacity; i++) {
        if (m->buckets[i].next != NULL)
            entry_delete(m->buckets[i].next, true);
        free(m->buckets[i].key);
    }
    
    free(m->buckets);
    free(m);
    m = NULL;

    return m;
}

/**
 * Insert or update entry into map data structure.
 * @param   m               Map data structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   type            Entry's value's type.
 */
void            map_insert(Map *m, const char *key, const Value value, Type type) {
    /*  check to see if we have sufficient space    */
    if (m->size == m->capacity-1)
        /*  if not, add some more buckets!  */
        map_resize(m, m->capacity+1);

    /*  use hash function to obtain bucket index    */
    int bucket_address = fnv_hash(key, sizeof(key)) % m->capacity;

    /* iterate to the last entry in linked list @ bucket index  */
    Entry * last_entry = &m->buckets[bucket_address];

    printf("pointer: %p for %d bucket addr. and %ld\n", last_entry, bucket_address,
            m->buckets[bucket_address].value.number);

    while (last_entry) {
        last_entry = last_entry->next;        
    }

    /*
    Entry * last_entry = &m->buckets[bucket_address];

    puts("got here");

    while (last_entry->next) {
        last_entry = last_entry->next;
    }   */

    last_entry->next = entry_create(key, value, NULL, type);

    m->size++;
}

/**
 * Search map data structure by key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to search for.
 * @param   Pointer to the entry with the specified key (or NULL if not found).
 */
Entry *         map_search(Map *m, const char *key) {
    return NULL;
}

/**
 * Remove entry from map data structure with specified key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to remove.
 * return   Whether or not the removal was successful.
 */
bool            map_remove(Map *m, const char *key) {
    return false;
}

/**
 * Dump all the entries in the map data structure.
 * @param   m               Map data structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void		map_dump(Map *m, FILE *stream, const DumpMode mode) {
}

/**
 * Resize the map data structure.
 * @param   m               Map data structure.
 * @param   new_capacity    New capacity for the map data structure.
 */
void            map_resize(Map *m, size_t new_capacity) {
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
