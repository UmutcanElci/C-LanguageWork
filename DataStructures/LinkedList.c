#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  struct node *next;
}Node;


typedef struct {
  Node* head;
}LinkedList;

void printLinkedList(LinkedList *l){
  Node *node_ptr = l -> head;

  while (node_ptr != NULL) {
    printf("&d", node_ptr -> value);
    node_ptr = node_ptr -> next;
  }
  printf("\n");
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
  LinkedList b;
  LinkedList c;

  Node n1, n2, n3, n4, n5, n6;

  a.head = &n1;
  b.head = &n3;
  c.head = &n5;

  n1.value = 1;
  n1.next = &n2;
  n2.value = 2;
  n2.next = NULL;


  n3.value = 3;
  n3.next = &n4;
  n4.value = 4;
  n4.next = NULL;
  
  n5.value = 5;
  n5.next = &n6;
  n6.value = 6;
  n6.next = NULL;

  printLinkedList(&a);
  printLinkedList(&b);
  printLinkedList(&c);
  
  return 0;
 
}
