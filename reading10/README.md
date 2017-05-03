Reading 10
==========

### Identify which system calls you would use to perform the following actions by briefly listing example C code:

- Print out the error message associated with a failed system call.

```
FILE * filey_file;
char name[BUFSIZ] = "filey_file.txt";

filey_file = fopen(file_name);
errno = 0					// errno is set upon failure, but should init to 0 

if (filey_file == NULL) {
	fprintf(stderr, "Couldn't open %s: %s\n", file_name, strerror(errno));
	exit EXIT_FAILURE;
}

return filey_file;
```

- Truncate a file.

```
// the following 'w' option clears the file, or truncates to zero:

FILE * funky_file = fopen("funky_file.txt", "w");

```

```
// the following truncates up to a point, but idk if these are sys calls:

FILE * flaky_file; 
errno = 0;

if (flaky_file = fopen("flakey_file.txt")) {
	if (ftruncate(fileno(flaky_file), shorten_size)) {
		printf("File truncated to %d successfully!\n", shorten_size);
		exit EXIT_SUCCESS;
	} else {
		fprintf(stderr, "Darn, couldn't truncate: %s :(\n", strerror(errno));
		exit EXIT_FAILURE;
	}
} else {
	fprintf(stderr, "Rats, couldn't open flakey_file: %s :(\n", strerror(errno));
	exit EXIT_FAILURE:
}
```

- Move to the 10th byte of a file.

```
// given a file stream is already open as 'FILE * flirty_file':

if (fseek(flirty_file, 10, SEEK_SET) == NULL) {
	fprintf(stderr, "Dang flabbit, couldn't get to the 10th byte: %s :(\n", 
		strerror(errno));
	exit EXIT_FAILURE;
} else {
	printf("What's the past-tense of seek?  Sought? Sucked? Suecked? \
		\nwell whatever it is, we did it!  Ten bytes worth.\n");
	return EXIT_SUCCESS:
}
```

- Check if a path is a directory.

```
DIR * secret_directory = opendir("SUPER_SECRET_DONT_CLICK");

if (secret_directory) {
	printf("it exists!  shh...\n");
} else if (errno == ENOENT) {
	printf("not a valid directory!  secrecy maintained!\n");
} else {
	printf("well it may or may not be real, what a let down.\n");
}
```

- Create a copy of the current process.

```
pid_t child_name = fork();      // children have names, not IDs!!!

// the process is created... that's all you need, should be checking return ID
// in some sort of conditional right now though!!  That way we know who's who

```

- Replace the code in the current process with another program.

```
const char killing_machine[BUFSIZ] = "/usr/bin/rm";
const char arg1[20] = "-rf";
const char innocent_file[20] = "/";

if (execl(killing_machine, arg2, innocent_file) != 0) {
    puts("darn, your machine lives to see another day...\n");
} else {
    while (1)
        puts("wake me up inside");
}

```

- Tell a process to terminate.

```
// given the above two snippets of code, a process with PID of child_name
// needs to be killed off:

kill(child_name, SIGKILL);      // rip :'(


```

- Receive the exit status of a child process.

```
// again, given the above snippets are running:
int exit_code = 0;

waitpid(child_name, &exit_status, 0)

if (WIFEXITED(exit_status)) {
    int code = WEXITSTATUS(exit_status);    
    printf("Exit status: %d\n", code);
}
```



Write the C equivalent, walk.c, to the Python code below (walk.py):

```
#!/usr/bin/env python2.7

import os

for name in os.listdir('.'):
    if os.path.isfile(name):
        print name, os.path.getsize(name)
```

### My implementation is as follows:  (makefile in directory)

```
/*  Print the name and size of each file in a given directory   *
 *                                                              *
 *  Author: ME!                                         (shane) */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>	    /* Definition of AT_* constants */
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



int main(void) {
    DIR * dir = opendir(".");

    struct dirent * dir_entry = NULL;
    FILE * flippy_file = NULL;
    struct stat super_stats;
    
    if (dir == NULL) {
        fprintf(stderr, "Oh no! Somehow the directory we are in isn't real?\n \
                %s\n", strerror(errno));
        closedir(dir);
        return EXIT_FAILURE;
    }

    // if we're at this point, we have an open directory stream!
    
    while ((dir_entry = readdir(dir))) {
        // remove pesky current / parent dirs
        if (!strcmp (dir_entry->d_name, "."))
            continue;
        if (!strcmp (dir_entry->d_name, ".."))    
            continue; 

        // now let's try open the current directory entry as a file:
        flippy_file = fopen(dir_entry->d_name, "r");

        // debugging: printf("file name: %s\n", dir_entry->d_name);
        
        // check if it's a valid file
        if (flippy_file == NULL) {
            // puts("not a file!");
            fclose(flippy_file);
        } else {
            if (fstat(fileno(flippy_file), &super_stats) != 0) {
                fprintf(stderr, "somehow we didn't get file info :( : %s\n",
                    strerror(errno));
                fclose(flippy_file); 
                closedir(dir);
                return EXIT_FAILURE;
            }

            printf("%s %ld\n", dir_entry->d_name, super_stats.st_size);

            fclose(flippy_file);
        }
    }

    closedir(dir);

    return EXIT_SUCCESS;
}
```



