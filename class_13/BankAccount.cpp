#include "BankAccount.h"

void BankAccount::withdraw(int amount) { this->amount -= amount; }

void BankAccount::deposit(int amount) { this->amount += amount; }

void BankAccount::transfer(int amount, BankAccount &account) {
  this->amount -= amount;
  account.amount += amount;
}
