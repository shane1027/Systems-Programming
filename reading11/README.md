Reading 11
==========

### Identify which system calls you would use to perform the following action:

- Creating a file descriptor or endpoint for communicating over the network.

	`socket()` for creating a file descriptor.

- Lookup the address information for a particular machine or service.

	`getaddrinfo()`

- Assign an address to a server network file descriptor (aka assign a name to a socket).

	`bind()`

- Convert the network address structure into corresponding host and service strings.

	`getnameinfo()`

- Establish a client network file descriptor to a specified address.

	`accept()`

- Mark network file descriptor as waiting for incoming connections.

	`listen()`

- Create a new network file descriptor based on a incoming connection.

	`accept()`
