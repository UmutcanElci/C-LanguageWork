#include <stdio.h>
#include <string.h>

//& address of -  * value at address

void swap(char *x, char *y) {
  char temp = *x;
  *x = *y;
  *y = temp;
}

void permute(char *str, int start, int end) {
  if (start == end) {
    printf("%s  ", str);
  } else {

    for (int i = start; i <= end; i++) {
      swap((str + start), (str + i));
      permute(str, start+1, end);
      swap((str + start), (str + i));
    }
  }
}

int main() {

  char str[5] = "ABCDE";

  int n = strlen(str);

  permute(str, 0, n - 1);
}
