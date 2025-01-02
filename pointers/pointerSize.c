#include <stdio.h>

int main() {
  int nb;
  int *ptr;

  nb = 19;
  ptr = &nb;

  printf("%d %.60f\n",*ptr, *(float *)ptr);

  return 0;
}
