#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define BUFLEN 1500

int main() {
  WSADATA wsaData;

  // Initialize Winsock
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
  }

  // Create a socket
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == INVALID_SOCKET) {
    fprintf(stderr, "Socket creation failed: %d\n", WSAGetLastError());
  }

  // Configure the server address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr)); // Zero out the structure
  addr.sin_family = AF_INET;      // IPv4
  addr.sin_port = htons(8080);    // Port 8080 (convert to network byte order)
  addr.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces

  // Bind the socket to the address and port
  if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR) {
    fprintf(stderr, "Bind failed: %d\n", WSAGetLastError());
  }

  // Start listening for incoming connections
  if (listen(fd, 1) == SOCKET_ERROR) {
    fprintf(stderr, "Listen failed: %d\n", WSAGetLastError());
  }

  printf("Server is listening on port 8080...\n");

  // Accept a connection
  struct sockaddr_in cliaddr;
  socklen_t cliaddrlen = sizeof(cliaddr);
  int connfd = accept(fd, (struct sockaddr *)&cliaddr, &cliaddrlen);
  if (connfd == INVALID_SOCKET) {
    fprintf(stderr, "Accept failed: %d\n", WSAGetLastError());
  }

  printf("Connection accepted...\n");

  // Communicate with the client
  char buf[BUFLEN];
  ssize_t rcount = recv(connfd, buf, BUFLEN, 0);
  if (rcount == SOCKET_ERROR) {
    fprintf(stderr, "Receive failed: %d\n", WSAGetLastError());
  } else {
    printf("Received data: %.*s\n", (int)rcount, buf);
  }

  // Send data to the client
  const char *data = "Hello, I created a server!";
  if (send(connfd, data, strlen(data), 0) == SOCKET_ERROR) {
    fprintf(stderr, "Send failed: %d\n", WSAGetLastError());
  }

  // Close the sockets
  closesocket(connfd);
  closesocket(fd);

  // Cleanup Winsock
  WSACleanup();

  return 0;
}
