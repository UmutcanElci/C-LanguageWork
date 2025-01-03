#include <stdio.h>

int sumTwoNumbers(int *num1, int *num2) { return *num1 + *num2; }

int main() {
  int a, b, sum;

  printf("First number : \n");
  scanf("%d", &a);
  printf("Second number : \n");
  scanf("%d", &b);

  sum = sumTwoNumbers(&a, &b);

  printf("The sum of two numbers : %d", sum);
}
