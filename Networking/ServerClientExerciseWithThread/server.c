#include <pthread.h>
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ws2tcpip.h>

#define PORT 8080
#define BUFSZ 500
#define MAX_CLIENTS 5

typedef struct {
  int socket;
  int client_number;
} client_t;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
  client_t *client = (client_t *)arg;
  char buffer[BUFSZ];
  int client_num = client->client_number;
  printf("New client (%d) connected\n", client->client_number);

  while (1) {
    memset(buffer, 0, BUFSZ);
    int valread = recv(client->socket, buffer, BUFSZ, 0);

    if (valread > 0) {
      printf("Client -%d- sent: %s\n", client_num, buffer);
    } else {
      int error = WSAGetLastError();
      if (valread == 0) {
        printf("Client -%d- disconnected normally\n", client_num);
      } else {
        printf("Client -%d- disconnection error: %d\n", client_num, error);
      }
      break;
    }
  }

  closesocket(client->socket);
  free(client);
  return NULL;
}

int main() {
  int sd;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  int opt = 1;
  int client_count = 0;

  WSADATA wsaData;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
    return 1;
  }

  if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
    fprintf(stderr, "Socket creation failed: %d\n", WSAGetLastError());
    WSACleanup();
    return 1;
  }

  if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt,
                 sizeof(opt)) < 0) {
    fprintf(stderr, "Set socket options failed: %d\n", WSAGetLastError());
    closesocket(sd);
    WSACleanup();
    return 1;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(sd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    fprintf(stderr, "Bind failed: %d\n", WSAGetLastError());
    closesocket(sd);
    WSACleanup();
    return 1;
  }

  if (listen(sd, 5) < 0) {
    fprintf(stderr, "Listen failed: %d\n", WSAGetLastError());
    closesocket(sd);
    WSACleanup();
    return 1;
  }

  printf("Server listening on port %d...\n", PORT);

  while (1) {
    int new_socket;
    if ((new_socket = accept(sd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
      fprintf(stderr, "Client connection falied", WSAGetLastError());
      closesocket(sd);
      WSACleanup();
      return 1;
    }

    client_t *client = malloc(sizeof(client_t));
    client->socket = new_socket;
    client->client_number = ++client_count;

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
      fprintf(stderr, "Could not create the thread", WSAGetLastError());
      free(client);
      closesocket(new_socket);
      WSACleanup();
      continue;
    }

    pthread_detach(thread_id);
  }

  closesocket(sd);
  WSACleanup();
  pthread_mutex_destroy(&clients_mutex);
  return 0;
}
