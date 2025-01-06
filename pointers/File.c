#include "io.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define MAX_TEXT_SIZE 256

FILE *filePtr;
char str[MAX_TEXT_SIZE];

void createTxt(const char *name) { filePtr = fopen(name, "w"); }
void writeTxt(const char *name) {
  filePtr = fopen(name, "w");

  printf("What you want to write here\n");

  fgets(str, MAX_TEXT_SIZE, stdin);
}

void readTxt(const char *name) { filePtr = fopen(name, "r"); }

void saveTxt() {
  fprintf(filePtr, "%s", str);
  fclose(filePtr);
}
void openTxt() {}

int main() {
  // char str[30];
  // printf("Enter the name of the file\n");
  // fgets(str, 30, stdin);
  //  add .txt to the file name
  // strcat(str, ".txt");
  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

  return 0;
}
