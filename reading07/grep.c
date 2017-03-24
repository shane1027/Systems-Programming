/* cat.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s PATTERN FILE...\n", PROGRAM_NAME);
    exit(status);
}

void grep_stream(FILE *stream, const char *pattern) {
    char buffer[BUFSIZ];
	char * match;

    while (fgets(buffer, BUFSIZ, stream)) {
		// const char *buffer_buf = buffer;
        match = strstr(buffer, pattern);
		if (match != NULL) {
			fputs(buffer, stdout);
		}
    }
}

void grep_file(const char *path, const char *pattern) {
    FILE *fs = fopen(path, "r");
    if (fs == NULL) {
        fprintf(stderr, "%s: %s: %s\n", PROGRAM_NAME, path, strerror(errno));
        return;
    }
    grep_stream(fs, pattern);
    fclose(fs);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int argind = 1;
	char *pattern = NULL;

    /* Parse command line arguments */
    PROGRAM_NAME = argv[0];
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        switch (arg[1]) {
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    /* Process each file */
    if (argind == argc) {
        usage(1);
    }
	else if (argind == (argc - 1)) {
		pattern = argv[argind];
		grep_stream(stdin, pattern);
	} else {
		pattern = argv[argind++];
        while (argind < argc) {
            char *path = argv[argind++];
            if (strcmp(path, "-") == 0) {
                grep_stream(stdin, pattern);
            } else {
                grep_file(path, pattern);
            }
        }
    }

    return EXIT_SUCCESS;
}

