#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define BUFFLEN 1024

int main() {
  WSADATA wsaData;
  int socfd;
  struct sockaddr_in serveraddr;
  char sendbuf[BUFFLEN];
  char recvbuf[BUFFLEN];

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
  }

  socfd = socket(AF_INET, SOCK_STREAM, 0);

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(8080);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(socfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) ==
      SOCKET_ERROR) {
    fprintf(stderr, "Connect failed: %d\n", WSAGetLastError());
    closesocket(socfd);
    WSACleanup();
    return 1;
  }

  printf("Connected to the server \n");
  printf("Enter a message to send : ");

  fgets(sendbuf, BUFFLEN, stdin);

  if (send(socfd, sendbuf, sizeof(sendbuf), 0) == -1) {
    perror("Send error");
  }

  printf("Message send to the server");

  int recvlen = recv(socfd, recvbuf, sizeof(recvbuf), 0);

  if (recvlen > 0) {
    recvbuf[recvlen] = '\0';

    printf("Respense form server %s\n", recvbuf);
  }

  closesocket(socfd);
  WSACleanup();

  return 0;
}
