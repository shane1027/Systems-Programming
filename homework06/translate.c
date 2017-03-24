/* translate.c: string translator */

#include "stringutils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char *PROGRAM_NAME = NULL;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s SOURCE TARGET\n\n", PROGRAM_NAME);
    fprintf(stderr, "Post Translation filters:\n\n");
    fprintf(stderr, "   -s     Strip whitespace\n");
    fprintf(stderr, "   -r     Reverse line\n");
    fprintf(stderr, "   -w     Reverse words in line\n");
    fprintf(stderr, "   -l     Convert to lowercase\n");
    fprintf(stderr, "   -u     Convert to uppercase\n");
    exit(status);
}

void translate_stream(FILE *stream, char *source, char *target, int mode) {
    /* TODO */
}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* Parse command line arguments */

    /* Translate Stream */

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
