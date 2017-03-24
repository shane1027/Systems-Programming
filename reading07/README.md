Reading 07
==========


####1.) Describe what the read_numbers function does by explaining what is happening on the following line:

`while (i < n && scanf("%d", &numbers[i]) != EOF) {`

#####Be sure to explain the purpose of the & in front of numbers[i] and what the constant EOF is.

The read+numbers function reads integers from the stream stdin and saves them
as individual elements in the array 'numbers[]' until there are no numbers left
on the stream.

In order to save the numbers correctly, a pointer to the correct type specified
(in this case a pointer to int) must be passed to scanf().  Using the address
operator (&) on an element in an array provides a pointer to the address of
that element so that the number can be properly saved.

The while() loop continues until either the max. number of numbers are read
(dictated by the variable i being less than n) or the end of the stream is
encountered (which is dictated by hitting `EOF` which acts as NULL or `0`0).




####2.) Insteading of passing size_t n into the sum_numbers function, could we have used sizeof to get the size of the array as shown below?

```
int sum_numbers(int numbers[]) {
    int total = 0;
    for (size_t i = 0; i < sizeof(numbers); i++) {
        total += numbers[i];
    }

    return total;
}
```

No, we could not use that, because sizeof(numbers) returns the size of the
pointer 'numbers' which points to the first element in the array 'numbers[]',
not the size of the array.

####3.) Compare how this version of cat parses command line arguments versus the approach used in cat.py from Reading 05. Beyond the obvious differences in syntax, how is the code similar and how is it different?  Be sure to explain the role of argc and argv.


Most of the approach is the same - while there are still input arguments to be processed, and the length of the current input argument is both non-zero and begins with a hyphen ('-'), match the input character following the hyphen to the correct program state or variable modification.

The biggest difference besides syntax is the use of a list which supports applying '.pop(0)' in Python, vs. the use of argc to determine how many arguments to cycle through for C.  Also, argc is used in C to determine if there are any arguments past flag inputs to check for input file path or explicit declaration of stdin, while Python checks if the length of remaining argument list is greater than zero.


#### 4.) Describe how each file is processed by explaining the following code:

```
while (argind < argc) {
    char *path = argv[argind++];
    if (strcmp(path, "-") == 0) {
        cat_stream(stdin);
    } else {
        cat_file(path);
    }
}
```

Be sure to explain what the char \*path = argv[argind++] statement accomplishes and what the strcmp comparison check.
---

At the point in the program, all flags are processed, and the remaining
arguments are expected to be file paths or an explicit reference to stdin with
'-'.  The while() loop's condition ensures iteration through all remaining
arguments provided.  During the loop, the current argument's pointer is saved
to a pointer called 'path', and this argument is referenced using a variable
which increments on usage via the '++' operator.

Then, if the path is found to compare completely to '-', we take that as an
explicit indication of the desired use of stdin as the stream.  Otherwise, open
the file at the specified 'path' and use that as the stream of data.


####5.) Explain how the cat_stream function works. What are the purposes of fgets and fputs?

The function 'cat_stream()' takes a file pointer as an input (pointer to a stream of data), creates a temporary buffer via an array of char, and while we have not yet reached the EOF character while reading the stream into buffer, writes the buffer contents onto stdout.

'fgets()' gets a line from the stream and stores it, returning 0 if no line is left (EOF encountered), and 'fputs()' places a line from the buffer into stdout.

####6.) Explain how the cat_file function works. What is the purpose of the following if statement:

```
if (fs == NULL) {
    fprintf(stderr, "%s: %s: %s\n", PROGRAM_NAME, path, strerror(errno));
    return;
}
```

Be sure to explain what strerror and errno are.



The 'cat_file' function first attempts to open a file and obtain a pointer to the open stream of data at that file using fopen() and the provided path.  The if() statement checks whether or not the file pointer points to anything - if it does not, that means the file was not opened successfully.  If this is the case, print to the stderror stream (2>) a string containing information on the issue via an errno given to strerror(), both from the errno.h header. This gives the user more information on the failure using Linux error codes..







