#include <stdio.h>

struct User {
  char name[50];
  char address[100];
  char email[50];
  char phone[15];
};

typedef struct BankAccount {
  struct User user;
  float balance;
  float interestRate;
  char accountNumber[10];
} BankAccount;

int main(void) {

  printf("Welcome to Simple Bank App\n");
  printf("Please first fill your User Information\n");

  BankAccount account;
  printf("Name: \n");
  fgets(account.user.name, 50, stdin);
  printf("Address: \n");
  fgets(account.user.address, 100, stdin);
  printf("Email: \n");
  fgets(account.user.email, 50, stdin);
  printf("Phone: \n");
  fgets(account.user.phone, 15, stdin);

  printf("Great your information is saved\n");

  while (1) {
    printf("Please select an option");
  }
  return 0;
}
