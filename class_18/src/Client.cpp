#include "../include/Client.hpp"

int Client::clients_amount = 0;

Client::Client(std::string name) {
  this->name = name;
  this->clients_amount++;
  this->id = this->clients_amount;
}
