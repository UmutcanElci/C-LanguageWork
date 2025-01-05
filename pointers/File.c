#include <stddef.h>
#include <stdio.h>
FILE *filePtr;
void createTxt(char *name) {
  filePtr = fopen(name, "w");
  fclose(filePtr);
}
void writeTxt(char *name) {
  filePtr = fopen(name, "w");
  char str[500];
  printf("What you want to write here\n");

  fgets(str, 500, stdin);

  fprintf(filePtr, "%s", str);
}
void readTxt(char *name) {
  filePtr = fopen(name, "r");
  char str[500];
  fgets(str, 500, filePtr);

  printf("%s", str);
}
void saveTxt() {}
void openTxt() {}
void closeTxt() {}

int main() {
  char str[50] = "newFile.txt";
  createTxt(str);
  writeTxt(str);
  readTxt(str);
  return 0;
}
