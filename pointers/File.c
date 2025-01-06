#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 256

FILE *filePtr;
char str[MAX_TEXT_SIZE];

void createTxt(const char *name) {
  filePtr = fopen(name, "w");
  fclose(filePtr);
}
void writeTxt(const char *name) {
  filePtr = fopen(name, "w");

  printf("What you want to write here\n");
  getchar();
  fgets(str, MAX_TEXT_SIZE, stdin);
  fprintf(filePtr, "%s", str);
  fclose(filePtr);
}

void readTxt(const char *name) {
  filePtr = fopen(name, "r");
  printf("In txt file: \n");
  fgets(str, MAX_TEXT_SIZE, filePtr);
  printf("%s", str);
  fclose(filePtr);
}


int main() {
  char name[30];
  printf("Enter the name of the file\n");
  fgets(name, 30, stdin);
  name[strcspn(name, "\n")] = '\0';
  //  add .txt to the file name
  strcat(name, ".txt");
  createTxt(name);
  int choice;
  while (1) {
    printf("\nMenu:\n1. Write\n2. Read\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      writeTxt(str);
      break;
    case 2:
      readTxt(str);
      break;
    case 3:
      return 0;
    }
  }
}
