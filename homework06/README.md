Homework 06
===========

### Activity 1
####Describe how your string_reverse_words function works and analyze its time complexity and space complexity in terms of Big-O notation.

####Describe how your string_translate function works and analyze its time complexity and space complexity in terms of Big-O notation.

####Describe how your string_to_integer function works and analyze its time complexity and space complexity in terms of Big-O notation.

####What is the difference between a shared library such as libstringutils.so and a static library such as libstringutils.a?

####Comparing the sizes of libstringutils.a and libstringutils.so, which one is larger? Why?



### Activity 2
#### Describe how the translate.c program works. In particular, explain:

##### How you implemented command line parsing.
    The argv[] array was iterated over in a while loop which tested for a valid
    string length on the input and the presence or absence of a '-' to handle
    flags accordingly.

    If there were an odd number of arguments then somthing was not right and
    the usage function was displayed.  And if there was an argument left after
    al flags were processed, this was indicative of a source and target for
    translation.  After this was complete, the translation funtion was called.

###### Be sure to describe how you used and handled the mode bitmask.
    An enumeration named flags used meaningful names such as strip_whitespace
    to represent a logical shift left of 1 to a unique degree.  This ended up
    being a bitmask consisting of six bits, each holding a one or zero to
    represent the presence of a flag or option enabled.  When a flag was
    detected while iterating over argv[], the 'mode' variable encoding the
    desired functionality was bitwise-'OR'ed with the appropriate enumeration.

##### How you implemented the translation.
    Using a series of if{} statements to check the bitmask 'mode' variable and the appropriate functions from the
    created string library, a while loop gathered the stream of input to be
    translated, modified the information, and printed it back on stdout.
    

##### How you implemented the different post processing filters.
    There was no post-processing per se, just intelligent ordering of the if{}
    statements so that multiple could effect the output.

#### What is the difference between a static executable such as translate-static and a dynamic executable such as translate-dynamic?
    The static executable contains all necessary code within the executable
    file to run translate.c, including the string library created.  On the
    contrary, the dynamic one relies on an external file to act as the library,
    and is therefore more lightweight.

##### Comparing the sizes of translate-static and translate-dynamic, which one is larger? Why?
    The static one is larger due to it containing the extra library prototypes.

##### When trying to execute translate-static, does it work? If not, explain what you had to do in order for it to actually run.
    On my distribution it ran immediately.

##### When trying to execute translate-dynamic, does it work? If not, explain what you had to do in order for it to actually run.
    On my distribution it ran after adding the appropriate string_utils
    library to my library folder, and just for experimentation's sake, I also
    modified my library environment variable to the working directory, and that
    also worked.

