/*  port scanner and file uploader - Shane Ryan     */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <dirent.h>
#include <sys/stat.h>

#define PORT_MIN 9700
#define PORT_MAX 9800
const char *host = "xavier.h4x0r.space";


// i would be fork() since I could spawn children and live as a kid forever!

// favorite part of this course was cracking the hashes with hulk.  I also
// really enjoyed the networking content.  Tbh I loved everything in this
// course but those two were my favorites.  Plus, it gave me an excuse to
// constantly tweak and explore new vim setups and linux scripts

// not knowing people!  i was struggling to finish things one time, largely due
// to not having people to turn to for help within the class.  office hours
// were helpful though.
//
// Thanks for an awesome class!


FILE *scream_at_socket(const char *host, const char *port) {

    struct addrinfo *results;
    struct addrinfo hints = {
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM
    };

    if ((getaddrinfo(host, port, &hints, &results) != 0))
        return NULL;

    int client_fd = -1;
    struct addrinfo *result_pointer;
    
    for (result_pointer = results; client_fd < 0 && result_pointer != NULL; result_pointer = result_pointer->ai_next) {
        /* Allocate socket */
        if ((client_fd = socket(result_pointer->ai_family, result_pointer->ai_socktype, result_pointer->ai_protocol)) < 0) {
            fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
            continue;
        }

        /* Connect to host */
        if (connect(client_fd, result_pointer->ai_addr, result_pointer->ai_addrlen) < 0) {
            fprintf(stderr, "Unable to connect to %s:%s: %s\n", host, port, strerror(errno));
            close(client_fd);
            puts("got here");
            client_fd = -1;
            continue;
        }
    }

	if (client_fd < 0) {
		freeaddrinfo(results);
		return NULL;
    }


    /* Open file stream from socket file descriptor */
    FILE *client_file = fdopen(client_fd, "w+");
    if (client_file == NULL) {
        fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
		freeaddrinfo(results);
        close(client_fd);
        return NULL;
    }

	freeaddrinfo(results);
    return client_file;
    
}

void spam_socket(FILE *filey_file) {
    FILE *fs;
    char buffer[BUFSIZ];
    struct stat s;
    char filesize[BUFSIZ];
    if ((fs = fopen("final.c", "r")) == NULL) {
        fprintf(stderr, "couldn't open final.c");
        exit(EXIT_FAILURE);
    }
    stat("final.c", &s);       // now we have the statistics
    printf("size of file.c: %d\n", s.st_size);
    sprintf(filesize, "%d\n", s.st_size);
    
    // send connecting message
    char message[BUFSIZ] = "PUT sryan8 ";
    strcat(message, filesize);

    //puts(message);

    // now read in this file to the port
    
    fputs(message, filey_file);
    puts("got here");
    while (fgets(buffer, BUFSIZ, fs)) {
        fputs(buffer, filey_file);
    }
    fflush(filey_file);

    fclose(filey_file);

}

int main(void) {
    
    char port[BUFSIZ];
    FILE *filey_file;

    for (int i = PORT_MIN; i < PORT_MAX; i++) {
        sprintf(port, "%d", i);
        filey_file = scream_at_socket(host, port);
        if (filey_file == NULL) {
            //printf("No connection on port %d\n", i);
        } else {
            printf("CONNECTED ON PORT %d\n", i);
            spam_socket(filey_file);
    // after a few tries, looks like 9776 is our dropbox
    // now open file and read it into the socket:
        }

    }

    return 0;
}

