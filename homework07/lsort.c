/* lsort.c */

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/*
enum flags {
    NUMERICAL = 1<<1,
    QUICK = 1<<2,
}; */

int mode = 0;
bool NUMERICAL = false;
bool QUICK = false;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s\n", PROGRAM_NAME);
    fprintf(stderr, "  -n   Numerical sort\n");
    fprintf(stderr, "  -q   Quick sort\n");
    exit(status);
}

void lsort(FILE *stream, bool numeric, bool quicksort) {
    char buff[BUFSIZ];
    struct list *listy_list = list_create();
    struct node *nodey_node = NULL;

    // add some junk to the list
    while (fgets(buff, BUFSIZ, stream)) {
        list_push_back(listy_list, buff);
    }

    //list_dump(listy_list, stdout);
    
    /*      darnit i wanted to use a bitmask...
    if ((mode & QUICK) && (mode & NUMERICAL)) {
        list_qsort(listy_list, node_compare_number);    
    } else if (mode & QUICK) {
        list_qsort(listy_list, node_compare_string);
    } else if (mode & NUMERICAL) {
        list_msort(listy_list, node_compare_number);
    } else {
        list_msort(listy_list, node_compare_string);
    } */

    if (quicksort && numeric) {
        //puts("got to qsort w/o string");
        list_qsort(listy_list, node_compare_number);
    } else if (quicksort) {
        //puts("got to qsort w/ string");
        list_qsort(listy_list, node_compare_string);
    } else if (numeric) {
        //puts("got to msort w/o string");
        list_msort(listy_list, node_compare_number);
    } else {
        //puts("got to msort w/ string");
        list_msort(listy_list, node_compare_string);
    }

    for (nodey_node = listy_list->head; nodey_node; nodey_node = nodey_node->next) {
        printf("%s", nodey_node->string);
    }

    list_delete(listy_list);


}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* Parse command line arguments */
    int argind = 1;

    PROGRAM_NAME = argv[0];
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];

        switch(arg[1]) {
            case 'n':
                NUMERICAL = true;
                //mode |= NUMERICAL;
                break;
            case 'q':
                QUICK = true;
                //mode |= QUICK;
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    //printf("input arguments: %d for num and %d for quick\n", NUMERICAL, QUICK);
    //
    
    /*
    char buff[BUFSIZ];
    struct list *listy_list = list_create();
    struct node *nodey_node = NULL;

    // add some junk to the list
    while (fgets(buff, BUFSIZ, stdin)) {
        list_push_back(listy_list, buff);
    }

    //list_qsort(listy_list, node_compare_number);
    list_msort(listy_list, node_compare_number);

    for (nodey_node = listy_list->head; nodey_node; nodey_node = nodey_node->next) {
        printf("%s\n", nodey_node->string);
    }

    free(listy_list);
    */

    /* Sort using list */
    lsort(stdin, NUMERICAL, QUICK);

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
