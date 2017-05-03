
/*  cool networking stuff - open port on a host and send stdin  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

void usage(char * prog_name, int status); 

int main(int arg_c, char ** v) {
	char * send_host = v[1];
	char * send_port = v[2];

	if (arg_c != 3) {
		usage(v[0], 1);
	}

	struct addrinfo hints = { 
		.ai_family = AF_UNSPEC,
		.ai_socktype = SOCK_STREAM,
	};
	
	struct addrinfo *results;

    /* start off by getting address info       */
	if (getaddrinfo(send_host, send_port, &hints, &results) < 0) {
		fprintf(stderr, "getaddrinfo() failed: %s\n", strerror(errno));
		return EXIT_FAILURE;	
	}	

	int FD;
	struct addrinfo *p;
	for (p = results; p != NULL; p = p->ai_next) {
		if ((FD = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
			puts("Eek!  Socket failed... \n");
			return EXIT_FAILURE;
		}
		if (connect(FD, p->ai_addr, p->ai_addrlen) < 0) {
			fprintf(stderr, "Couldn't connect to %s:%s %s\n", send_host, send_port, strerror(errno));
			close(FD);
			return EXIT_FAILURE;
		}
	}	
	
	if (FD < 0)
        return EXIT_FAILURE;

	FILE * file = fdopen(FD, "w+");     // append to file
	char buffer[BUFSIZ];

	while (fgets(buffer, BUFSIZ, stdin) != NULL)
		fprintf(file,"%s", buffer);
		
    /* close her up! */
	close(FD);
	fclose(file);
	freeaddrinfo(results);

	return EXIT_SUCCESS;	
}
	
void usage(char * prog_name, int status) {
	fprintf(stderr, "Usage %s send_host send_port\n", prog_name);
    exit(status);
}

