
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

