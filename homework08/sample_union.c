
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <map.h>

void fun_stuff(void) {
    
    
}

int main(void) {
    Value a = {34};

    fun_stuff();

    printf("The number in a is %ld\n\n", a.number);

    char *hi = "hello";

    printf("size of empty string %ld\n\n", sizeof(a.string));

    a.string = strdup(hi);

    printf("size of empty string %ld\n\n", sizeof(a.string));
    printf("The char in a is %s\n\n", a.string);

    printf("Pointer to the number: %p\n\n", &a.number);
    printf("Pointer to the string: %p\n\n", &a.string);
    printf("Pointer to the union: %p\n\n", &a);

    free(a.string);

    return 0;

}


