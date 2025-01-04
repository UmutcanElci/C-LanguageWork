#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//& address of -  * value at address

int main() {

  int n;
  printf("Input total number of element (1 to 100) : ");
  scanf("%d", &n);

  int *ptr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("\nNumber %d : ", i);
    scanf("%d", ptr + i);
  }

  for (int i = 0; i < n; i++) {
    printf("Your input Number =  %d  \n", *(ptr + i));
  }
}
