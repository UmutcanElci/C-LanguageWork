**From C Basics to a Threaded HTTP Server**  
This repository documents my journey of relearning C and building a simple HTTP server using the Windows Socket API (Winsock). Along the way, I explore network programming, multithreading, file handling, and memory management in C.

***Project Breakdown***
1. Revisiting C Fundamentals
* Basic input/output operations
* Working with structs, typedef, and nested structs
* Understanding pointers, arrays, and dynamic memory allocation (malloc, free)

2. File Handling in C
* Creating, writing, reading, and saving data in text files
* Exploring buffer limitations and how fgets handles input beyond set limits

3. Understanding Network Programming (TCP/IP & Sockets)
* Learning TCP/IP communication and the Sockets API
* Building a simple TCP client and server
* Implementing a threaded TCP server

4. Creating a Basic HTTP Server
* Initializing Winsock (WSAStartup) on Windows
* Setting up a server socket (socket, bind, listen, accept)
* Handling client requests and responding with basic HTTP responses
* Serving an HTML file through the server
