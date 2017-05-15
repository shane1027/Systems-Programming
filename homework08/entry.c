/* entry.c: map entry */

#include "map.h"
#include <errno.h>

/**
 * Create entry structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   next            Reference to next entry.
 * @param   type            Entry's value's type.
 * @return  Allocate Entry structure.
 */
Entry *		entry_create(const char *key, const Value value, Entry *next, Type type) {
    /* allocate a new entry */
    Entry * new_entry = malloc(sizeof(struct Entry));

    if (new_entry == NULL) {
        fprintf(stderr, "Couldn't allocate memory :/ : %s\n", strerror(errno));
        free(new_entry);
        exit(EXIT_FAILURE);
    }

    /*  okay, we've got a new entry!  fill her up   */
    if (next == NULL) {
        new_entry->next = NULL;
    } else {
        new_entry->next = next;
    }
    new_entry->key = strdup(key);
    new_entry->type = type;
    //entry_update(new_entry, value, type);
    if (type == STRING)
        new_entry->value.string = strdup(value.string);
    else
        new_entry->value.number = value.number;
    
    return new_entry;
}

/**
 * Delete entry structure.
 * @param   e               Entry structure.
 * @param   recursive       Whether or not to delete remainder of entries.
 * return   NULL.
 */
Entry *		entry_delete(Entry *e, bool recursive) {
    if (recursive) {
        if (e->next != NULL) {
            entry_delete(e->next, true);
        }
    }

    if ((e->type == STRING) && e->value.string != NULL) {
        //puts("about to free value.string");
        free((e->value.string));       // not sure why this works vs next line
        //free(e->value.string);
        //puts("freed value.string");
    }
    free(e->key);
    //puts("key freed");
    free(e);
    //puts("node freed");

    return NULL;
}

/**
 * Update entry's value.
 * @param   e               Entry structure.
 * @param   value           New value for entry.
 * @param   type            New value's type.
 */
void            entry_update(Entry *e, const Value value, Type type) {

    if (e->type == type) {
        e->value = value;
    } else if (type == STRING) {
        e->value.number = 0;
        e->value.string = strdup(value.string);
    } else {
        if (e->value.string != NULL)
            free((e->value.string));
        e->value = value;
    }
    e->type = type;
    /*
    if ((type == STRING) && (e->type == STRING)) {
        debug("case 1\n");
        e->value.string = value.string;
    } else if (type == STRING) {
        debug("case 2\n");
        e->value.string = strdup(value.string);
    } else if (e->type == STRING && (e->value.string != NULL)) {
        debug("case 3\n");
        //free(e->value.string);
        e->value.number = value.number;
    } else {
        debug("case 4\n");
        e->value.number = value.number;
    }
    */
}

/**
 * Dump entry.
 * @param   e               Entry structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void            entry_dump(Entry *e, FILE *stream, const DumpMode mode) {
    switch (mode) {
        case KEY:
            fprintf(stream, "%s\n", e->key);
            break;

        case KEY_VALUE:
            if (e->type == STRING)
                fprintf(stream, "%s\t%s\n", e->key, e->value.string);
            else
                fprintf(stream, "%s\t%ld\n", e->key, e->value.number);
            break;

        case VALUE:
            if (e->type == STRING)
                fprintf(stream, "%s\n", e->value.string);
            else
                fprintf(stream, "%ld\n", e->value.number);
            break;

        case VALUE_KEY:
            if (e->type == STRING)
                fprintf(stream, "%s\t%s\n", e->value.string, e->key);
            else
                fprintf(stream, "%ld\t%s\n", e->value.number, e->key);
            break;
        default:
            fprintf(stderr, "Unrecognized case!\n");
            exit(EXIT_FAILURE);
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
