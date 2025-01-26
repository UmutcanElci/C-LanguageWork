#include "winsock2.h"
#include <stdlib.h>
#include <stdio.h>
// Socket for windows
#include <windows.h>
#include <ws2tcpip.h>

int main() {
  WSADATA wsaData;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
    return 1;
  }

  int network_socket;
  // create a socket
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  // specify an address for the socket
  struct sockaddr_in server_address;

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect
  int connection = connect(network_socket, (struct sockaddr *)&server_address,
                           sizeof(server_address));

  // Check for error with the connection
  if (connection == -1) {
    printf(
        "There was and error making a connection to the removete socket \n\n");
  }

  // recieve data from the server
  char server_response[256];
  recv(network_socket, server_response, sizeof(server_response), 0);

  // print out the server's response

  printf("The server sent the data : %s\n", server_response);

  WSACleanup();
  closesocket(network_socket);
  return 0;
}
