#include <stdio.h>
#include <string.h>

int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // print size
  printf("%d", strlen(alphabet));

  // Combine two strings(Concatenate)

  char str1[20] = "Hello ";
  char str2[] = "World";

  strcat(str1, str2);

  printf("%s", str1);
  // copy strings
  char strc[20] = "Hi How are you?";
  char strr[20];

  strcpy(strr, strc);

  printf("%s", strr);
  // Compare strings
  char str3[20] = "Hello World";

  printf("%d\n", strcmp(str1, str2)); // returns -1 not equal
  printf("%d\n", strcmp(str1, str3)); // returns 0 equal
}
