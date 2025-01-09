#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char str [100];

  int alp,digit,spe;
  alp=digit=spe=0;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  int i = 0;
  while(str[i]!='\0') {
    if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
      alp++;
    }
    else if(str[i]>='0' && str[i]<='9') {
      digit++;
    }
    else {
      spe++;
    }
    i++;
  }


  printf("Alphabets: %d\n", alp);
  printf("Digits: %d\n", digit);
  printf("Special Characters: %d\n", spe);

  return 0;
}
