#include <stdio.h>
#include <string.h>

int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // splitting
  for (int i = 0; i < strlen(alphabet); i++) {
    printf("%s",&alphabet[i]);
    if (i < strlen(alphabet) - 1) {
    printf(" ");
    }
  }
  printf("\n");
  return 0;
}
