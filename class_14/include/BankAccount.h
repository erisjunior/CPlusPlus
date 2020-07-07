#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>

class BankAccount {
public:
  int id;
  int amount = 0;
  std::string name;

  void withdraw(int amount);
  void deposit(int amount);
  void transfer(int amount, BankAccount &account);
};

#endif
