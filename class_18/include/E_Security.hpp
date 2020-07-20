#ifndef E_SECURITY_H
#define E_SECURITY_H

#include "Employee.hpp"

class E_Security : public Employee {
public:
  std::string security_area;

  E_Security(std::string name, std::string security_area);
};

#endif
