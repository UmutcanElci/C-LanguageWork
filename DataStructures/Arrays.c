#include <stdio.h>
#include <stdlib.h>

int main() {
  // Merge two array
  int n1,n2;
  printf("Input the size of first array : ");
  scanf("%d",&n1);
  puts("\n");
  printf("Input the size of second array : ");
  scanf("%d",&n2);
  puts("\n");
  
  int arr1[n1],arr2[n2];

  for (int i = 0; i < n1; i++) {
    printf("Input the first array value %d : ",i);
    scanf("%d",&arr1[i]);
  }
  puts("\n");
 for (int i = 0; i < n2; i++) {
  printf("Input the second array value %d : ",i);
  scanf("%d",&arr2[i]);
 }

 puts("\n");

 int *ptr = malloc(n1+n2);

 for (int i =0; i < n1; i++) {
 *(ptr + i) = arr1[i];
 }
 for (int i = 0; i < n2; i++) {
   *(ptr + i + n1) = arr2[i];
 }

 printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    free(ptr);

    return 0;
}
