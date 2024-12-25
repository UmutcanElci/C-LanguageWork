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

  account.balance = 100;

  while (1) {
    printf("Please select an option");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    int choice;

    switch (choice) {
    case1:
      printf("Enter the amount to deposit: ");
      float deposit;
      scanf("%f", &deposit);
      if (deposit <= 0) {
        account.balance = deposit + account.balance;
        printf("Your new balance : %f", account.balance);
      } else {
        printf("Your deposit value is not valid");
      }
      break;
    case 2:
      printf("Enter the amount to withdraw");
      float withdraw;
      scanf("%f", &withdraw);
      if (account.balance < withdraw) {
        printf("You can't withdraw this amount of money because your balance "
               "is : %f",
               account.balance);
      } else {
        account.balance = account.balance - withdraw;
        printf("You withdraw %f amount of money new balance is %f", withdraw,
               account.balance);
      }
      break;
      case 3:

    }
  }

  return 0;
}
