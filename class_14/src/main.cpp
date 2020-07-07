#include "BankAccount.h"

int main(int argc, char const *argv[]) {
  BankAccount account_one;
  BankAccount account_two;

  account_one.id = 1234;
  account_one.name = "Junior";

  account_two.id = 4321;
  account_two.name = "Erisvan";

  std::cout << account_one.name << " | ID: " << account_one.id << std::endl;
  std::cout << account_two.name << " | ID: " << account_two.id << std::endl;

  account_one.deposit(100);
  account_two.deposit(50);

  account_one.withdraw(10);
  account_two.withdraw(10);

  std::cout << account_one.name << " | Current Amount: " << account_one.amount
            << std::endl;
  std::cout << account_two.name << " | Current Amount: " << account_two.amount
            << std::endl;

  account_one.transfer(30, account_two);

  std::cout << account_one.name << " | Current Amount: " << account_one.amount
            << std::endl;
  std::cout << account_two.name << " | Current Amount: " << account_two.amount
            << std::endl;
}
