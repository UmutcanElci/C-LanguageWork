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

int CountEvenNumbers(LinkedList *l){
  int count = 0;

  Node *countNode = l -> head;
  while ( countNode != NULL) {
    if (countNode->value % 2 == 0) {
      count++;
    }
    countNode = countNode -> next;
  }

  return count;
}

void InsertAfterValue(LinkedList *l, int value, int newValue) {
  Node *currentNode = l -> head;

  while (currentNode != NULL) {
    if (currentNode -> value == value) {
      Node *newNode = malloc(sizeof(Node));
      newNode -> value = newValue;
      newNode -> next = currentNode -> next;
      currentNode -> next = newNode;

      return;// Cut the loop
    }
    currentNode = currentNode -> next;
  }


}

int FindMaxValue(LinkedList *l) {
  int max = 0;

  Node *FindMaxNode = l -> head;

  while (FindMaxNode != NULL) {
    if (FindMaxNode -> value > max) {
      max = FindMaxNode -> value;
    }
    FindMaxNode = FindMaxNode -> next;
  }
  return max;
}

void RemoveDuplicates(LinkedList *l) {

}

void ReverseLinkedList(LinkedList *l) {

}

int FindMiddleValue(LinkedList *l) {

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
  AddToFront(&a, 17);
  AddToFront(&a, 21);
  AddToFront(&a, 32);
  AddToFront(&a, 4);
  AddToFront(&a, 52);
  AddToFront(&a, 12);
  AddToFront(&a, 7);

  InsertAfterValue(&a, 17, 99);

  int evenNumbers = CountEvenNumbers(&a);

  printf("In Linked list there is %d even numbers.\n",evenNumbers);

  int maxValue = FindMaxValue(&a);

  printf("In Linked list max value is %d.\n",maxValue);
  
  printLinkedList(&a);
  return 0;
}
