#ifndef E_MANAGER_H
#define E_MANAGER_H

#include "Employee.hpp"

class E_Manager : public Employee {
public:
  std::string sector;

  E_Manager(std::string name, std::string sector);
};

#endif
