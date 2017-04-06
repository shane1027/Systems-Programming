Reading 08
==========

Given the following lines of code in C99:

```
struct point {
    double x;
    double y;
};

1. int            i = 0;
2. int          a[] = {4, 6, 6, 3, 7};
3. char          *s = "pgui";
4. struct point   p = {0, 0};
5. struct point  *q = NULL;
6. struct point  *x = malloc(sizeof(struct point));
7. struct point  *y = malloc(10*sizeof(struct point));
8. struct point **z = malloc(10*sizeof(struct point *));
```
How much memory (in terms of bytes) is allocated or reserved for each of the 8 declarations above (assume a 64 bit Linux machine such as the student machines)?

Note: Remember that each variable declaration is a memory allocation.

1. 4
2. 20
3. 1
4. 16
5. 16
6. 16
7. 16
8. 16



## Describe what the memory error was in Task 3 and how you fixed it.

Task 3 used a piece of starter code that included the statment `int *randoms =
malloc(n)`, which hoped to allocate n integers worth of data.  However, this
statement only allocates n bytes - I changed it to `int *randoms =
malloc(sizeof(int) * n)` in order to fix the memory issue.

## Same thing for Task 4's memory leak:

Valgrind mentioned that out of 101 allocations at 4 bytes each, only one was
freed at the end of the program's operation.  This is because there was a
mistake with the control flow of the program - the function 'duplicates'
would return a value within a for loop upon a certain condition, exiting the
loop before reaching the `free()` statement later in the function.  This was
changed to a variable and checked to determine return value after freeing the
memory.



