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

int DeleteFirst(LinkedList *l) {
  if (l->head == NULL) {
    printf("There is not a Linked List...");
  } else {
    Node *deletedNode = l->head;
    int deletedValue = deletedNode->value;
    l->head = deletedNode->next;
    free(deletedNode);

    return deletedValue;
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

  a.head = NULL;
  AddToFront(&a, 1);
  AddToFront(&a, 2);
  AddToFront(&a, 32);
  AddToFront(&a, 4);




  printLinkedList(&a);
  return 0;
}
