#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>

#include "Agency.hpp"
#include "Client.hpp"

class BankAccount {
public:
  int id;
  int amount;
  Client client;
  Agency agency;

  static int accounts_amount;

  BankAccount(Client client);

  void withdraw(int amount);
  void deposit(int amount);
  void transfer(int amount, BankAccount &account);
};

#endif
