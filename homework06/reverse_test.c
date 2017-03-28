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
            c = string_reverse(buff);
            fputs(c, stdout);  
    }
    
    return 0;
}
