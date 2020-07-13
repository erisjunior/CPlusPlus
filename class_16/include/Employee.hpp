#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Company.hpp"
#include <string>

class Employee {
  std::string name;
  std::string department;
  std::string admission_date;
  float sallary;
  Company company;

public:
  Employee();

  void setName(std::string name);
  void setDepartment(std::string department);
  void setAdmissionDate(std::string admission_date);
  void setSallary(float sallary);
  void setCompany(Company &company);

  std::string getName();
  std::string getDepartment();
  std::string getAdmissionDate();
  float getSallary();
  Company getCompany();

  void raiseSallaryBePercent(int percent);
};

#endif
