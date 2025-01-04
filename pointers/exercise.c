#include <stdio.h>

//& address of -  * value at address

int strLenght(char *str){
  int len;

  while (*str++) {
    len++;
  }
  printf("%d",len);
  return len;
}

int main() {
  char a[10] = "Hello";
  strLenght(a);

}
