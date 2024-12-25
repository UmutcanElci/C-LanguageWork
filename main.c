#include <stdio.h>
#include <string.h>
struct Identity {
  int id;
  char nationality[50];
};
typedef struct Person {
  struct Identity identity;
  char name[20];
  int age;
  float salary;
}Person;

int main(void) {
  Person person;

  person.identity.id = 1;
  strcpy(person.identity.nationality, "Wordlwide");
  strcpy(person.name, "John Doe");
  person.age = 30;
  person.salary = 1000.0;

  printf("ID : %d\n  Nationality : %s\n Name: %s\n Age: %d\n Salary : %f \n", person.identity.id,person.identity.nationality, person.name, person.age, person.salary);


  return 0;
}
