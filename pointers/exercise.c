#include <stdio.h>

int main() {
  int m = 300;
  float fx = 300.600006;
  char cht = 'z';

  // & address of
  printf("address of m = %p\n", &m);
  printf("address of fx = %p\n", &fx);
  printf("address of cht = %p\n", &cht);

  // * value at address
  printf("value at address of m = %d\n", *(&m));
  printf("value at address of fx = %f\n", *(&fx));
  printf("value at address of cht = %c\n", *(&cht));

  int *pm;
  float *pfx;
  char *pcht;

  pm = &m;
  pfx = &fx;
  pcht = &cht;
  printf("address of m = %p\n", pm);
  printf("address of fx = %p\n", pfx);
  printf("address of cht = %p\n", pcht);

  // Pointer to value

  printf("value at address of m = %d\n", *pm);
  printf("value at address of fx = %f\n", *pfx);
  printf("value at address of cht = %c\n", *pcht);
}
