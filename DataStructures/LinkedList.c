#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void printLinkedList(struct node *n) {
  while (n != NULL) {
    printf("%d", n->value);
    n = n->next;
  }
}

int main() {
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  one->value = 1;
  two->value = 2;
  three->value = 3;

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;

  printLinkedList(head);
  return 0;
}
