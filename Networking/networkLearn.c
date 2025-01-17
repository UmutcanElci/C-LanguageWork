#include "corecrt.h"
#include "io.h"
#include "psdk_inc/_ip_types.h"
#include <cerrno>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>


int main() {
  int fd;
struct sockaddr_in addr; 

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
       //Permission denied
       perror("Permission denied");
       break;
     default:
       break;
    }
  }

  //Bind a socket to a port 
  // Socket , Pointer to addr strucutre , sizeof addr
  if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Unable to bind!");
  }


  return 0;
}

