#include <winsock2.h>
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

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
    fprintf(stderr, "Socket creation failed: %d\n", WSAGetLastError());
    WSACleanup();
    return 1;
  }

  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

  if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
    fprintf(stderr, "Connection failed: %d\n", WSAGetLastError());
    closesocket(sock);
    WSACleanup();
    return 1;
  }

  printf("Connected to Server!\n");

  while (1) {
    printf("Enter message (type ':q' to exit): ");
    fgets(buffer, BUFSZ, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strcmp(buffer, ":q") == 0) {
      printf("Closing connection...\n");
      break;
    }
    if (send(sock, buffer, strlen(buffer), 0) == SOCKET_ERROR) {
      fprintf(stderr, "Send failed: %d\n", WSAGetLastError());
      break;
    }
  }

  closesocket(sock);
  WSACleanup();

  return 0;
}
