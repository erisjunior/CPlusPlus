#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
  int id;
  std::string name;

  static int employees_amount;

protected:
  Employee(std::string name);
};

#endif
