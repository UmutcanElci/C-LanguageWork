#include <stdio.h>
#include <stdlib.h>

int main(){
  //array
  int arr[10];
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  //In the Stack
  printf("The address of the array %p\n", arr);
  //Cannot increment the pointer
  

  //sizeof
  printf("The size of the array %zu\n", sizeof(arr));
  

  //&
  printf("%p\n",&arr);
  printf("%p\n",arr);

  puts("\n\n");

  int * const ptr = alloca(10*sizeof(int));
  *(ptr + 0) = 10;
  *(ptr + 1) = 20;
  *(ptr + 2) = 30;

  //In the Stack
  printf("The address of the array %p\n", ptr);
  //Cannot increment the pointer


  //sizeof
  printf("The size of the array %zu\n", sizeof(ptr));

  //&

  printf("%p\n",&ptr);
  printf("%p\n",ptr);
}
