#include <stdio.h>

//& address of * value at address

int main() {
  int n;
  printf("Input the size array : \n");
  scanf("%d",&n);

  int *ptr;
  int arr[n];
  
  for (int i=0; i<n; i++) {
    printf("Input the %d element : \n",i);
    scanf("%d",&arr[i]);
  }


  ptr = arr;

  printf("--------\n");
  for (int j = 0; j < n; j++) {
    printf("Element %d of the array : %d\n",j,*(ptr+j));
  }

}
