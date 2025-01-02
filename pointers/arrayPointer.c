#include <stdio.h>
#include <stdlib.h>

int main(){
  //array
  int arr[10];
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;


  printf("The address of the array %p\n", arr);

  puts("\n\n");

  int * const ptr = alloca(10*sizeof(int));
  *(ptr + 0) = 10;
  *(ptr + 1) = 20;
  *(ptr + 2) = 30;


  printf("The address of the array %p\n", ptr);


}
