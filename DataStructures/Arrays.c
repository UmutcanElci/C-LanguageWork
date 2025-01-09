#include <stdio.h>

int main() {
  printf("Input the size of the array : ");
  int n;
  scanf("%d", &n);

  int arr[n];

  puts("\n\n");
  for (int i = 0; i < n; i++) {
    printf("Please enter the array %d number : \n", i);

    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("Array [%d] : %d \n", i, arr[i]);
  }
}
