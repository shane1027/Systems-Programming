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
    if (m->size == m->capacity-1) {
        /*  if not, add some more buckets!  */
        debug("about to resize");
        map_resize(m, 2*(m->capacity));
        debug("done resizing");
    }

    /*  use hash function to obtain bucket index    */
    int bucket_address = fnv_hash(key, sizeof(key)) % m->capacity;
    //printf("bucket addr for %s = %d\n", key, bucket_address);
    debug("got new bucket address");

    /* check if the key is alreadt in our map.  if not, add it  */
    if (map_search(m, key) != NULL) {
        debug("already in map!");
        return;
    }
    debug("key not in hash table");

    /* iterate to the last entry in linked list @ bucket index  */
    Entry * last_entry = &m->buckets[bucket_address];

    //debug("got here");
    while (last_entry->next != NULL) {
        last_entry = last_entry->next;        
    }
    debug("got to last entry");

    /*
    Entry * last_entry = &m->buckets[bucket_address];

    puts("got here");

    while (last_entry->next) {
        last_entry = last_entry->next;
    }   */

    last_entry->next = entry_create(key, value, NULL, type);
    debug("linked last entry to new insertion");
//    debug("got to next entry");

    m->size++;
}

/**
 * Search map data structure by key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to search for.
 * @param   Pointer to the entry with the specified key (or NULL if not found).
 */
Entry *         map_search(Map *m, const char *key) {

    /*  get hash of key to check appropriate bucket */
    int bucket_address = fnv_hash(key, sizeof(key)) % m->capacity;
    debug("got key for where the search should start");

    /*  now check that bucket for desired key   */
    Entry * curr_entry = &m->buckets[bucket_address];
    debug("made temp entry to iterate");
    while (curr_entry->next != NULL) {
        curr_entry = curr_entry->next;
        if ((strcmp(curr_entry->key, key)) == 0) {
            debug("found a match");
            return curr_entry;
        }
        debug("moving to next entry");
        curr_entry = curr_entry->next;
        debug("moved.");
    }

    return NULL;
}

/**
 * Remove entry from map data structure with specified key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to remove.
 * return   Whether or not the removal was successful.
 */
bool            map_remove(Map *m, const char *key) {

    /*  get hash of key to check appropriate bucket */
    int bucket_address = fnv_hash(key, sizeof(key)) % m->capacity;

    /*  now check that bucket for desired key   */
    Entry * prev_entry = &m->buckets[bucket_address];
    Entry * curr_entry = prev_entry->next;

    while (curr_entry != NULL) {    // note: still works when key @ 1st entry
        if ((strcmp(curr_entry->key, key) == 0)) {
            prev_entry->next = curr_entry->next; 
            entry_delete(curr_entry, false);
            m->size--;
            return true;
        }
    }

    return false;
}

/**
 * Dump all the entries in the map data structure.
 * @param   m               Map data structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void		map_dump(Map *m, FILE *stream, const DumpMode mode) {

    for (int i = 0; i < m->capacity; i++) {
        Entry * curr = &m->buckets[i];
        while (curr->next) {
            curr = curr->next;
            switch (mode) {
                case KEY:
                    fprintf(stream, "%s\n", curr->key);
                    break;
                case VALUE:
                    if (curr->type == NUMBER)
                        fprintf(stream, "%ld\n", curr->value.number);
                    else
                        fprintf(stream, "%s\n", curr->value.string);
                    break;
                case KEY_VALUE:
                    if (curr->type == NUMBER)
                        fprintf(stream, "%s\t%ld\n", 
                                curr->key, curr->value.number);
                    else
                        fprintf(stream, "%s\t%s\n", 
                                curr->key, curr->value.string);
                    break;
                case VALUE_KEY:
                    if (curr->type == NUMBER)
                        fprintf(stream, "%ld\t%s\n", 
                                curr->value.number, curr->key);
                    else
                        fprintf(stream, "%s\t%s\n", 
                                curr->value.string, curr->key);
                    break;

            }
        }
    }
}

/**
 * Resize the map data structure.
 * @param   m               Map data structure.
 * @param   new_capacity    New capacity for the map data structure.
 */
void            map_resize(Map *m, size_t new_capacity) {

    Map * new_map = map_create(new_capacity, m->load_factor); 
    //int bucket_address;
    
    debug("new map created");

    for (int i = 0; i < m->capacity; i++) {
        Entry * curr = &m->buckets[i];
        while (curr->next != NULL) {
            curr = curr->next;
            char *key = curr->key;
            debug("about to insert new key");
            //bucket_address = fnv_hash(key, sizeof(key)) % new_map->capacity;
            map_insert(new_map, key, curr->value, curr->type);
            debug("new key insreted");
        }
    }

    debug("about to free old map");
    free(m);
    debug("old map freed.  About to point old map to new");
    m = new_map;
    debug("done");

}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
