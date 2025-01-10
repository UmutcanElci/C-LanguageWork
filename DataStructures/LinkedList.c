#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

void printLinkedList(LinkedList *l) {
  Node *node_ptr = l->head;

  while (node_ptr != NULL) {
    printf("%d ", node_ptr->value);
    node_ptr = node_ptr->next;
  }
  printf("\n");
}

void AddToFront(LinkedList *l, int newNodeValue) {
  if (l->head == NULL) {
    Node *createNode = malloc(sizeof(Node));

    createNode->value = newNodeValue;
    createNode->next = NULL;
    l->head = createNode;
  } else {
    Node *createNode = malloc(sizeof(Node));

    createNode->value = newNodeValue;

    createNode->next = l->head;

    l->head = createNode;
  }
}

void freeLinkedList(struct node *n) {
  struct node *temp; // Temporary pointer to hold the next node

  while (n != NULL) {
    temp = n->next; // Save the next node
    free(n);        // Free the current node
    n = temp;       // Move to the next node
  }
}

int main() {
  LinkedList a;

  Node *n1, *n2, *n3;

  n1 = malloc(sizeof(Node));
  n2 = malloc(sizeof(Node));
  n3 = malloc(sizeof(Node));

  n1->value = 1;
  n2->value = 2;
  n3->value = 3;

  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  a.head = n1;

  AddToFront(&a, 43);
  printLinkedList(&a);
  return 0;
}
