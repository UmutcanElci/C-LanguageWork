#include "psdk_inc/_ip_types.h"
#include "winsock2.h"
#include "ws2ipdef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ws2tcpip.h>

int main() {
  WSADATA wsaData;
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    printf("WSAStartup failed\n");
    return 1;
  }
  FILE *html_data;
  html_data = fopen("index.html", "r");

  char response_data[1024] = {0};
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), html_data)) {
    strcat(response_data, buffer);
  }

  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
  strcat(http_header, response_data);

  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8001);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(server_socket, (struct sockaddr *)&server_address,
       sizeof(server_address));

  listen(server_socket, 6);

  int client_socket;
  while (1) {
    client_socket = accept(server_socket, NULL, NULL);
    send(client_socket, http_header, strlen(http_header), 0);
  }

  return 0;
}
