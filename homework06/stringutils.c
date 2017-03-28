/* stringutils.c: String Utilities */

#include "stringutils.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Convert all characters in string to lowercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_lowercase(char *s) {
    char *c;

    for (c = s; *c; c++) {
        *c = tolower(*c); 
    }

    c = s;
    return s;
}

/**
 * Convert all characters in string to uppercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_uppercase(char *s) {
    char *c;

    for (c = s; *c; c++) {
        *c = toupper(*c); 
    }

    c = s;
    return s;
}

/**
 * Returns whether or not the 's' string starts with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' starts with 't'
 **/
bool	string_startswith(char *s, char *t) {
    for (char *c = t; *c; c++) {
        if (*c != *s) {
            return false; 
        }
        s++;
    }
    return true;

}

/**
 * Returns whether or not the 's' string ends with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' ends with 't'
 **/
bool	string_endswith(char *s, char *t) {
    char *f;
    char *g;
    for (f = s; *f; f++) {}     // move pointers to end of string
    for (g = t; *g; g++) {}
    f--; g--;                   // index stopped at EOF, move back one

    for (char *c = g; *c; c--) { // then just iterate like before,
        if (*c != *f--) {        // decrementing!
            return false; 
        }
    }

    return true;
}

/**
 * Removes trailing newline (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_chomp(char *s) {
    int len = strlen(s);
    if (*(s+len-1) == '\n') {*(s+len-1) = 0;}

    return s;
}

/**
 * Removes whitespace from front and back of string (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_strip(char *s) {
    char *c;
    char *f;

    for (c = s; isspace(*c); c++) {
        *c = *(c+1);
    }

    int len = strlen(c);
    len--;
    f = (c+len);

    while (isspace(*f)) {
        *f-- = 0;
        len--;
    }

    return (f-(len));
}

/**
 * Reverses a string given the provided from and to pointers.
 * @param   from    Beginning of string
 * @param   to      End of string
 * @return          Pointer to beginning of modified string
 **/
static char *	string_reverse_range(char *from, char *to) {
    char *c = from;

    if (*to == '\n') {to--;}
    
    while (from < to) {
        *from ^= *to;
        *to ^= *from;
        *from ^= *to;
        from++;
        to--;
    }

    return c;

}

/**
 * Reverses a string.
 * @param   s       String to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse(char *s) {
    char *c;
    c = string_reverse_range(s, (s+strlen(s)-1));

    return c;
}

/**
 * Reverses all words in a string.
 * @param   s       String with words to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse_words(char *s) {
    char *c;
    char *start;
    char *end;
    int len = strlen(s);

    s = string_reverse_range(s, s+(len-1));

    while (*s) {
        for (c = s; isspace(*c); c++);
        start = c;
        while (!isspace(*c) && *c) {c++;}
        end = (c-1);
        s = string_reverse_range(start, end);
        s = s + (c-s);
    }

    return s - (len);
}

/**
 * Replaces all instances of 'from' in 's' with corresponding values in 'to'.
 * @param   s       String to translate
 * @param   from    String with letter to replace
 * @param   to      String with corresponding replacment values
 * @return          Pointer to beginning of modified string
 **/
char *	string_translate(char *s, char *from, char *to) {
    /*  This code translates a substring to another substring.. oops
    char *c;
    do {
        c = strstr(s, from);
        if (!c) {break;}
        *c = *to;
        //fputs(c, stdout);
        //fputs(s, stdout);
    } while (*c);

    return s; */

    int len_haystack = strlen(s);

    if (strlen(from) != strlen(to)) {return s;}

    while (*from) {
        while (*s) {
            if (*s == *from) {*s = *to;} 
            s++;
        }
        s = s - len_haystack;
        from++;
        to++;
    }

    return s;

}

/**
 * Converts given string into an integer.
 * @param   s       String to convert
 * @param   base    Integer base
 * @return          Converted integer value
 **/
int	string_to_integer(char *s, int base) {
    return strtol(s, NULL, base);
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
