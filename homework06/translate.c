/* translate.c: string translator */

#include "stringutils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char *PROGRAM_NAME = NULL;

/* Functions */

/* TODO */
/*  modify argument parsing to accept strings beginning w/ whitespace
 *  potentially use some libstring functions in parsing args
 *  look into why the dynamic program does not run
 */

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
    char buffer[BUFSIZ];
    char *c = NULL;

    while (fgets(buffer, BUFSIZ, stream)) {
        c = buffer;
        if (mode & 1<<6) {
            c = string_translate(c, source, target);
        }
        if (mode & 1<<1) {
            c = string_strip(c);
            int len = strlen(c);
            *(c+len) = '\n';
            *(c+len+1) = 0;
        }
        if (mode & 1<<2) {
            c = string_reverse(c); 
        }
        if (mode & 1<<3) {
            c = string_reverse_words(c); 
        }
        if (mode & 1<<4) {
            c = string_lowercase(c); 
        }
        if (mode & 1<<5) {
            c = string_uppercase(c);
        }
        fputs(c, stdout);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    enum flags {
        strip_whitespace = 1<<1,
        reverse_line = 1<<2,
        reverse_words = 1<<3,
        convert_lower = 1<<4,
        convert_upper = 1<<5,
            translate = 1<<6
    };

    int mode = 0;

    int argind = 1;
    char *source = NULL;
    char *target = NULL;

    /* Parse command line arguments */
    PROGRAM_NAME = argv[0];
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        switch (arg[1]) {
            case 's':
                mode |= strip_whitespace;
                break;
            case 'r':
                mode |= reverse_line;
                break;
            case 'w':
                mode |= reverse_words;
                break;
            case 'l':
                mode |= convert_lower;
                break;
            case 'u':
                mode |= convert_upper;
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    /* Translate Stream */

    if ((argc - argind) == 1 || (argc - argind) > 2) {     // if there are an odd number of input args
        usage(1);
    } else {
        if (argc != argind) {
            mode |= translate;
            source = argv[argind++];
            target = argv[argind];
        }
        translate_stream(stdin, source, target, mode);
    }


    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
