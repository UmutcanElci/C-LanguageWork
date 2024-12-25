#include <stdio.h>
int main(void) {
  printf("Hello World");

  int interger = 10;
  float foo = 10.5;

  // I try to remember C language
  printf("Integer = %d\n", interger);
  printf("Float = %f\n", foo);

  int x;
  printf("Enter a number: ");

  scanf("%d", &x);

  printf("You entered: %d\n", x);

  int a;
  float b;

  printf("Enter integer and then float number:");

  scanf("%d, %f", &a, &b);

  printf("You entered: %d and %f\n", a, b);

  return 0;
}
