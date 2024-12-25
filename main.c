#include <stdio.h>
#include <string.h>
struct Person {
  char name[20];
  int age;
  float salary;
};

int main(void) {
  struct Person person1; // Declare a structure variable

  strcpy(person1.name, "Bob");
  person1.age = 25;
  person1.salary = 4680.50;

  printf("Name %s\n Age %d\n Salary %f\n", person1.name, person1.age,
         person1.salary);

  return 0;
}
