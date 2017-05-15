/* test_map.c */

#include "map.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    Map *m = NULL;
    char key[BUFSIZ];

    /*
    Value val = { .number = 45 };
    Entry * tmp = entry_create("0", val, NULL, NUMBER);
    printf("Entry %s has value %ld and next ptr %p\n", tmp->key, 
            tmp->value.number, tmp->next);

    entry_delete(tmp, false);
    */


    puts("Testing map creation (defaults)...");
    /*
    m = map_create(0, 0);
    assert(m != NULL);
    assert(m->capacity    == DEFAULT_CAPACITY);
    assert(m->load_factor == DEFAULT_LOAD_FACTOR);
    assert(m->size        == 0);
    */
    int test = 5;
    m = map_create(test, 1);
    assert(m != NULL);
    assert(m->capacity    == test);
    assert(m->load_factor == 1);
    assert(m->size        == 0);

    puts("map 'm' is allocated");

    for (int i = 0; i < test; i++) {
        printf("Entry %s has value %ld and next ptr %p\n", m->buckets[i].key, 
            m->buckets[i].value.number, m->buckets[i].next);
    }

    //map_delete(m);
    
    //puts("map deleted");


    puts("Testing map insertion...");
    /*
    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        sprintf(key, "%lx", i);
        map_insert(m, key, (Value)(int64_t)i, NUMBER);
        assert(m->size == (i + 1));
        map_insert(m, key, (Value)(int64_t)i, NUMBER);
        assert(m->size == (i + 1));
    }
    assert(m->capacity > DEFAULT_CAPACITY);
    map_dump(m, stdout, KEY_VALUE);
    */
    int add = 2;
    for (size_t i = 0; i < add; i++) {
        sprintf(key, "%lx", i);
        map_insert(m, key, (Value)(int64_t)i, NUMBER);
        debug("first value in");
        assert(m->size == (i + 1));
        map_insert(m, key, (Value)(int64_t)i, NUMBER);
        assert(m->size == (i + 1));
    }
    //assert(m->capacity > DEFAULT_CAPACITY);
    //map_dump(m, stdout, KEY_VALUE);



    puts("Testing map searching...");

    for (size_t i = 0; i < add; i++) {
        sprintf(key, "%lx", i);
        assert(map_search(m, key) != NULL);
        sprintf(key, "-%lx", i);
        assert(map_search(m, key) == NULL);
    }
    //map_delete(m);
    //puts("map deleted");
    //return 0;
    /*
    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        sprintf(key, "%lx", i);
        assert(map_search(m, key) != NULL);
        sprintf(key, "-%lx", i);
        assert(map_search(m, key) == NULL);
    }
    map_delete(m);
    */

    /*
    puts("Testing map creation (custom)...");
    m = map_create(DEFAULT_CAPACITY/2, 0.5);
    assert(m != NULL);
    assert(m->capacity    == DEFAULT_CAPACITY/2);
    assert(m->load_factor == 0.5);
    assert(m->size        == 0);

    puts("Testing map insertion...");
    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        sprintf(key, "%lx", i);
        map_insert(m, key, (Value)key, STRING);
        assert(m->size == (i + 1));
        map_insert(m, key, (Value)key, STRING);
        assert(m->size == (i + 1));
    }
    assert(m->capacity > DEFAULT_CAPACITY);
    map_dump(m, stdout, VALUE_KEY);

    puts("Testing map searching...");
    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        sprintf(key, "%lx", i);
        assert(map_search(m, key) != NULL);
        sprintf(key, "-%lx", i);
        assert(map_search(m, key) == NULL);
    } */

    puts("Testing map removal...");
    for (size_t i = 0; i < add; i++) {
        sprintf(key, "%lx", i);
        assert(map_remove(m, key) == true);
        assert(map_search(m, key) == NULL);
        assert(map_remove(m, key) == false);
    }
    map_delete(m);
    /*
    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        sprintf(key, "%lx", i);
        assert(map_remove(m, key) == true);
        assert(map_search(m, key) == NULL);
        assert(m->size == DEFAULT_CAPACITY - i - 1);
        assert(map_remove(m, key) == false);
    }
    map_delete(m); */

    return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
