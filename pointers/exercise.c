#include <stdio.h>

int FindMax(int *num1,int *num2){
  if (*num1 > *num2) {
    return *num1;
  }else {
  return *num2;
  }
}

int main() {
  int a,b,*ptr1,*ptr2,result;
  printf("First number:");
  scanf("%d",&a);
  printf("Second nubmer:");
  scanf("%d",&b);

  ptr1 = &a;
  ptr2 = &b;

  result = FindMax(ptr1, ptr2);

  printf("%d is the maximum number",result);
}
