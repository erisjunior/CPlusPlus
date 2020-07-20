#include "../include/Agency.hpp"

Agency::Agency(std::string name, int number) {
  this->name = name;
  this->number = number;
}

Agency::Agency() {
  this->name = "";
  this->number = 0;
}
