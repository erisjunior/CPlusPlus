#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.hpp"
#include <iostream>
#include <string>
#include <vector>

class Company {
  std::string name;
  std::string cnpj;

public:
  Company();

  void setName(std::string name);
  void setCNPJ(std::string cnpj);
  std::string getName();
  std::string getCNPJ();
};

#endif
