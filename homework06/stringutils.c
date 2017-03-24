/* stringutils.c: String Utilities */

#include "stringutils.h"

#include <ctype.h>
#include <string.h>

/**
 * Convert all characters in string to lowercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_lowercase(char *s) {
    return s;
}

/**
 * Convert all characters in string to uppercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_uppercase(char *s) {
    return s;
}

/**
 * Returns whether or not the 's' string starts with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' starts with 't'
 **/
bool	string_startswith(char *s, char *t) {
    return true;
}

/**
 * Returns whether or not the 's' string ends with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' ends with 't'
 **/
bool	string_endswith(char *s, char *t) {
    return true;
}

/**
 * Removes trailing newline (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_chomp(char *s) {
    return s;
}

/**
 * Removes whitespace from front and back of string (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_strip(char *s) {
    return s;
}

/**
 * Reverses a string given the provided from and to pointers.
 * @param   from    Beginning of string
 * @param   to      End of string
 * @return          Pointer to beginning of modified string
 **/
static char *	string_reverse_range(char *from, char *to) {
    return from;
}

/**
 * Reverses a string.
 * @param   s       String to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse(char *s) {
    return s;
}

/**
 * Reverses all words in a string.
 * @param   s       String with words to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse_words(char *s) {
    return s;
}

/**
 * Replaces all instances of 'from' in 's' with corresponding values in 'to'.
 * @param   s       String to translate
 * @param   from    String with letter to replace
 * @param   to      String with corresponding replacment values
 * @return          Pointer to beginning of modified string
 **/
char *	string_translate(char *s, char *from, char *to) {
    return s;
}

/**
 * Converts given string into an integer.
 * @param   s       String to convert
 * @param   base    Integer base
 * @return          Converted integer value
 **/
int	string_to_integer(char *s, int base) {
    return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
