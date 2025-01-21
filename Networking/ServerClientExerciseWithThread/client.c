#include <winsock2.h>
#include "winsock.h"
#include "psdk_inc/_ip_types.h"
#include "psdk_inc/_socket_types.h"
#include "psdk_inc/_wsadata.h"
#include "synchapi.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ws2tcpip.h>

#define PORT 8080
#define BUFSZ 500

int main() {
  WSADATA wsaData;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
    return 1;
  }

  int sock;
  struct sockaddr_in address;
  char buffer[BUFSZ];

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
    perror("Client socket error!");
    WSACleanup();
    closesocket(sock);
  }

  address.sin_family = AF_INET;
  address.sin_port = PORT;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sock, (struct sockaddr *)&address, sizeof(address)) <= 0) {
    perror("Connection failed!");
    WSACleanup();
    closesocket(sock);
  }

  printf("Connected to Server!");

  while (1) {

    printf("Enter message (type ':q' to exit)  : \n");
    fgets(buffer, BUFSZ, stdin);

    if (strcmp(buffer, ":q") == 0) {
      printf("Closing Connection.....\n");
      break;
    }

    send(sock, buffer, strlen(buffer), 0);
  }

  WSACleanup();
  closesocket(sock);

  return 0;
}
