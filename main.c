#include <stdio.h>
#include <string.h>
typedef struct Person {
  char name[20];
  int age;
  float salary;
}Person;

int main(void) {
  Person p1;

  strcpy(p1.name, "John");
  p1.age = 25;
  p1.salary = 50000.00;

  printf("Name: %s\n Age: %d\n Salary: %.2f\n", p1.name, p1.age, p1.salary);



  return 0;
}
