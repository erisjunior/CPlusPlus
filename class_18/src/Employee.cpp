#include "../include/Employee.hpp"

int Employee::employees_amount = 0;

Employee::Employee(std::string name) {
  this->name = name;
  this->employees_amount++;
  this->id = this->employees_amount;
}
