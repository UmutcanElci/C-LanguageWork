#include <windows.h>
#include "psdk_inc/_ip_types.h"
#include "psdk_inc/_socket_types.h"
#include "synchapi.h"
#include "winsock.h"
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>


#define PORT 8080
#define BUFSZ 500


 int main (){
   int sd;
   int client_sd;
   struct sockaddr_in address;
   int addrlen = sizeof(address);
   char buffer[BUFSZ]; 
   int opt = 1;

   WSADATA wsaData;
 

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
      fprintf(stderr, "WSAStartup failed: %d\n", WSAGetLastError());
      return 1;
    }

    if (sd = (socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
      perror("Socket creation error!");
      WSACleanup();
      closesocket(sd);
    }
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
      perror("Set socket Options error!");
      WSACleanup();
      closesocket(sd);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = PORT;

    if ((bind(sd, (struct sockaddr*) &address, sizeof(address))) <= 0) {
      perror("Binding erorr!");
      WSACleanup();
      closesocket(sd);
    }


    if (listen(sd,5) <= 0) {
      perror("Listen error!");
      WSACleanup();
      closesocket(sd);
    }

    printf("Server listening on port %d......\n",PORT);


    if (client_sd = accept(sd, (struct sockaddr*) &address, sizeof(address))) {
      perror("Accept error!");
      WSACleanup();
      closesocket(sd);
    }


 }
