#include "../include/BankAccount.hpp"

int BankAccount::accounts_amount = 0;

BankAccount::BankAccount(Client client) {
  this->client = client;
  this->amount = 0;
  this->id = accounts_amount;

  this->accounts_amount += 1;
}

void BankAccount::withdraw(int amount) { this->amount -= amount; }

void BankAccount::deposit(int amount) { this->amount += amount; }

void BankAccount::transfer(int amount, BankAccount &account) {
  this->amount -= amount;
  account.amount += amount;
}
