#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int value;
  struct node *next;
};

struct node *head;

void createNode(int numberOfNodes) {
  struct node *newNode;
  struct node *tempNode;

  int nodeData;
  int counter;

  head = malloc(sizeof(struct node));

  if (head == NULL) {
    printf("Memory cannot be allocated");
    return;
  } else {

    printf("Input the data for node %d :", counter);
    scanf("%d", &nodeData);

    head->value = nodeData;
    head->next = NULL;

    tempNode = head; // We need this to link the list

    for (counter = 2; counter <= numberOfNodes; counter++) {
      newNode = malloc(sizeof(struct node));

      if (newNode == NULL) {
        printf("Memory cannot be allocated");
        return;
      }
      puts("\n");
      printf("Input the data for node %d : ", counter);
      scanf("%d", &nodeData);

      newNode->value = nodeData;
      newNode->next = NULL;
      tempNode->next = newNode;
      tempNode = newNode;
    }
  }
}

void printLinkedList(struct node *n) {
  while (n != NULL) {
    printf("%d ", n->value);
    n = n->next;
  }
}

int main() {

  int n;

  printf("Input the size of the node : ");
  scanf("%d", &n);
  puts("\n");
  if (n <= 0) {
    printf("The size of the linked list must be greater than 0.\n");
    return 0;
  }

  createNode(n);
  puts("\n");
  printLinkedList(head);
  return 0;
}
