Homework 07
===========

### Describe what memory you allocated in node_create and what memory you deallocated in node_delete. How did you handle the recursive flag?

In node_create(), I allocated memory for the node itself which contains one int and two pointers, and memory for the string to which one of the pointers points.

In node_delete(), I first deallocated the string and then the node itself.  The recursive flag continues to call node_delete() on the singly linked-list by checking if the current node points to NULL.  If not, keep recursing until the last node is found (which points to NULL).  After that, start deleting nodes, beginning at the end, working back to the front via returning from the recursive calls.

### Describe what memory you allocated in list_create and what memory you deallocated in list_delete. How did you handle internal struct nodes?

list_create() allocates memory for the list structure, which contains a pointer to head and tail, and an integer for size.  No node structures are actually allocated so the default size is zero.  Deallocating a list first recursively deletes all nodes in the list and then removes the list structure itself.

### Describe how your list_qsort function works and analyze its time complexity and space complexity in terms of Big-O notation (both average and worst case).

Qsort calls the built-in C qsort() function with a list of pointers to each node as an input to sort and a node_compare function as input for comparison.  Appropriate parameters of node struct size and the list length are also provided.

The time complexity is O(n\*log(n)) not including the for() loop used to print out the results (because that can be omitted when just sorting in memory);

### Describe how your list_reverse function works and analyze its time complexity and space complexity in terms of Big-O notation (both average and worst case).

list_reverse() first sets the current head to the tail and then calls an interl function reverse() on the list, providing the original head and NULL as parameters for previous and next.  The internal reverse function checks if the current node's 'next' value is NULL - if so, we have reached the end of the list, but if not, reverse must be iterated to the next node using (curr->next) as the new current node and curr as the new previous node.  

Once curr->next is NULL, we have reached the end.  Make this the head of the
list and upon returning to each previous call set the 'prev' node as the
curr->next value, reversing the entire structure.  This is a O(\*n^2) function
since it has to call reverse for each subcomponent and the space required
increases linearly with size.


### Describe how your list_msort function works and analyze its time complexity and space complexity in terms of Big-O notation (both average and worst case).

Merge sort divides and conquers the data set.  It recursively splits the data into sublists and then sorts the sublists... merging the data includes a comparison so that the data is sorted as it is merged.  This is a time complexity of O(n\*log(n)) since dividing a list can be done at most log(n) times and sorting is done for every list member. 



### Based on your experiments, what is the overall trend in terms of time and space as the number of items increases for both of your sorting methods?

| NITEMS | SORT | TIME | SPACE |
|--------|------|------|-------|
| 1 |  MERGE | 0.000000 seconds  |      1.296875 Mbytes |
| 1 |  QUICK | 0.000000 seconds  |      1.246094 Mbytes |
| 10 |  MERGE | 0.000000 seconds |       1.238281 Mbytes |
| 10 |  QUICK | 0.000000 seconds |       1.371094 Mbytes |
| 100 |  MERGE | 0.000000 seconds |       1.300781 Mbytes |
| 100 |  QUICK | 0.000000 seconds |       1.312500 Mbytes |
| 1000 |  MERGE | 0.000000 seconds |       1.414062 Mbytes |
| 1000 |  QUICK | 0.000000 seconds |       1.339844 Mbytes |
| 10000 |  MERGE | 0.006666 seconds  |      2.308594 Mbytes |
| 10000 |  QUICK | 0.006666 seconds  |      2.507812 Mbytes |
| 100000 |  MERGE | 0.096666 seconds |       12.050781 Mbytes |
| 100000 |  QUICK | 0.063333 seconds |       12.023438 Mbytes |
| 1000000 |  MERGE | 1.013332 seconds |       70.183594 Mbytes |
| 1000000 |  QUICK | 0.769999 seconds |       77.292969 Mbytes |

The increasing number of items gave rise to an exponentially rising time
complexity, and space complexity seemed to rise exponentially as well.

### Are the results surprising to you? Explain why or why not.

Yes because this doesn't completely agree with the theoretical analysis of the
functions provided above, which I believe was accurate.

### Given what you said about the space complexity and time complexity of list_msort and list_qsort in Activity 1 and the experimental results in Activity 2, what can you say is the relationship between theoretical complexity and real world performance? Explain.

Theoretical time complexity likely depends on an ideal situation and could be
disturbed by environmental factors... this was run on my personal machine:

```
                   -`
                  .o+`                 shane@ThinkPad
                 `ooo/                 OS: Arch Linux
                `+oooo:                Kernel: x86_64 Linux 4.9.8-1-ARCH
               `+oooooo:               Uptime: 2h 38m
               -+oooooo+:              Packages: 1198
             `/:-:++oooo+:             Shell: zsh 5.3.1
            `/++++/+++++++:            Resolution: 1920x1080
           `/++++++++++++++:           DE: Gnome
          `/+++ooooooooooooo/`         WM: GNOME Shell
         ./ooosssso++osssssso+`        WM Theme: Adwaita
        .oossssso-````/ossssss+`       GTK Theme: Adwaita [GTK2/3]
       -osssssso.      :ssssssso.      Icon Theme: Adwaita
      :osssssss/        osssso+++.     Font: Tinos for Powerline 14
     /ossssssss/        +ssssooo/-     CPU: Intel Core i7-3520M CPU @ 3.6GHz
   `/ossssso+/:-        -:/+osssso+-   RAM: 5254MiB / 15871MiB
  `+sso+:-`                 `.-/+oso:
 `++:.                           `-/+/
 .`                                 `/

```








