#include "winsock2.h"
#include "ws2ipdef.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>


int main() {

  WSADATA wsaData;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
    return 1;
  }

  char server_message[256] = "You have reached the server!";
  // create a socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define the server address
  struct sockaddr_in server_address;
  
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr =  inet_addr("127.0.0.1");


  // Bind the socket to our specified IP and port
  

  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  listen(server_socket, 5);


  int clien_socket;

  clien_socket = accept(server_socket, NULL, NULL);

  send(clien_socket, server_message, strlen(server_message), 0);

  closesocket(clien_socket);
  WSACleanup();
  closesocket(server_socket);
  return 0;
}
