#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "psdk_inc/_socket_types.h"
#include "winsock.h"

#define BUFFLEN 1024

int main() {

  WSADATA wsaData;
  int fd; // File Descriptor
  struct sockaddr_in saddr;
  struct sockaddr_in clientaddr;
  int connfd;

  char buf[BUFFLEN];

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
    return 1;
  }

  // IPv4, TCP , 0
  fd = socket(AF_INET, SOCK_STREAM, 0);

  if (fd == INVALID_SOCKET) {
    fprintf(stderr, "Socket creation failed: %d\n", WSAGetLastError());
  }

  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(8080);
  saddr.sin_addr.s_addr = INADDR_ANY;

  if (bind(fd, (struct sockaddr*) &saddr, sizeof(saddr)) == SOCKET_ERROR) {
    perror("bind error");
    
  }


  if (listen(fd, 1) == SOCKET_ERROR) {
    perror("Listen!");
  }

  printf("Server is listening on port 8080...\n");

 socklen_t cliaddrlen = sizeof(clientaddr);
  connfd = accept(fd, (struct sockaddr *)&clientaddr, &cliaddrlen);
  if (connfd == INVALID_SOCKET) {
    fprintf(stderr, "Accept failed: %d\n", WSAGetLastError());
    closesocket(fd);
    WSACleanup();
    return 1;
  }

 

  ssize_t rcount = recv(connfd, buf, BUFFLEN, 0);
  printf("Client Connected\n");
  for (int i = 0; i < rcount; i++) {
    printf("%c", buf[i]);
  }

  if (rcount > 0) {
    char *response = "Your data has been received!";
    if (send(connfd, response, strlen(response), 0) == SOCKET_ERROR) {
      perror("Failed to response");
    } else {
      printf("Response sent to client");
    }
  }

  closesocket(connfd);
  closesocket(fd);
  WSACleanup();
  return 0;
}
