#ifndef E_CASHIER_H
#define E_CASHIER_H

#include "Employee.hpp"

class E_Cashier : public Employee {
public:
  int amount;

  E_Cashier(std::string name);
};

#endif
