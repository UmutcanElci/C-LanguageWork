#include "corecrt.h"
#include "io.h"
#include "psdk_inc/_ip_types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define BUFLEN 1500

int main() {
  WSADATA wsaData;
  // Because I am using Windows
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    perror("WSAStartup failed");
    exit(EXIT_FAILURE);
  }
  int fd;

  struct sockaddr_in addr;

  struct sockaddr_in cliaddr;
  socklen_t cliaddrlen = sizeof(cliaddr);

  // IPv4 , TCP , 0
  fd = socket(AF_INET, SOCK_STREAM, 0); // creating a socket

  // The Unix man pages list possible erors that can occur
  // https://man7.org/linux/man-pages/man3/errno.3.html
  if (fd == -1) {
    switch (errno) {
    case EPROTONOSUPPORT:
      // Protocol Not Supported
      perror("Protocol not Supported!");
      break;
    case EACCES:
      // Permission denied
      perror("Permission denied");
      break;
    default:
      break;
    }
  }

  // Configure the server address structure

  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = INADDR_ANY;

  // Bind a socket to a port
  //  Socket , Pointer to addr strucutre , sizeof addr
  if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Unable to bind!");
  }

  // Listening for connections
  // socket , number of maximum conenctions(backlog)
  if (listen(fd, 1) == -1) {
    perror("Another errno... for listening");
  }

  // Connecting to a server
  // Same as binding
  if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Unable to open connection");
  }

  // Accepting connections
  // Creating a new File Descritor for user - taking data from user
  int connfd = accept(fd, (struct sockaddr *)&cliaddr, &cliaddrlen);

  if (connfd == -1) {
    perror("Unablea to accept connection");
  }

  ssize_t i;
  ssize_t rcount;
  char buf[BUFLEN];
  // Reading Data
  rcount = read(fd, buf, BUFLEN);

  if (rcount == -1) {
    perror("Error while reading data");
  }

  for (i = 0; i < rcount; i++) {
    printf("%c", buf[i]);
  }

  char data[] = "Hello I create a server I think...";
  int datalen = strlen(data);

  // Writing data
  if (write(fd, data, datalen) == -1) {
    perror("Error while writing data");
  }

  // Closing the Socket
  close(connfd);
  close(fd);
  WSACleanup();

  return 0;
}
