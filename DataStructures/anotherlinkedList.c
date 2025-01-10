#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void PrintList(Node *head) {
  while (head != NULL) {
    printf("%d", head->value);
    head = head->next;
  }
}

void AddToFront(Node *head, int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = head->next;
  head->next = newNode->next;

  PrintList(newNode);
}

void DeleteFirst(Node *head) {
  Node *deletedNode = head;
  head->next = deletedNode->next;

  free(deletedNode);

  PrintList(deletedNode);
}

int main() {

  Node *a, *b, *c;

  a = malloc(sizeof(Node));
  b = malloc(sizeof(Node));
  c = malloc(sizeof(Node));

  a->value = 1;
  b->value = 2;
  c->value = 3;

  a->next = b;
  b->next = c;
  c->next = NULL;

  AddToFront(a, 26);

  DeleteFirst(a);
  return 0;
}
