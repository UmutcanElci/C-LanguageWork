#include <stdio.h>

int main() {
  printf("Input the size of the array : ");
  int n;
  scanf("%d", &n);

  int arr[n];

  int *ptr = arr;

  puts("\n\n");
  for (int i = 0; i < n; i++) {
    printf("Please enter the array %d number : \n", i);

    scanf("%d", ptr + i);
  }
  for (int i = 0; i < n; i++) {
    printf("Array [%d] : %d \n", i, arr[i]);
  }
}
