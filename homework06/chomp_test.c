#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stringutils.h"


int main(void) {

    char buff[BUFSIZ];
    char *c;

    typedef struct dict
    {
        char *input;
        char *output;
    } dict;

    dict x[] = {
        {"", "430"},
        {"aeo", ""},
        {"aeo", "430"},
        {"aeol", "4301"}
    };

    while (fgets(buff, BUFSIZ, stdin)) {
        for (int i = 0; i < 4; i++) {
            c = string_translate(buff, x[i].input, x[i].output);
            printf("Input: %s\nOutput: %s\n", x[i].input, x[i].output);
            fputs(c, stdout);  
            printf("\n");
        }
    }
    
    return 0;
}
