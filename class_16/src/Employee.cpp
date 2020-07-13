#include "include/Employee.hpp"

Employee::Employee() {}

void Employee::setName(std::string name) { this->name = name; }
void Employee::setDepartment(std::string department) {
  this->department = department;
}
void Employee::setAdmissionDate(std::string admission_date) {
  this->admission_date = admission_date;
}
void Employee::setSallary(float sallary) { this->sallary = sallary; }
void Employee::setCompany(Company &company) { this->company = company; }

std::string Employee::getName() { return this->name; }
std::string Employee::getDepartment() { return this->department; }
std::string Employee::getAdmissionDate() { return this->admission_date; }
float Employee::getSallary() { return this->sallary; }
Company Employee::getCompany() { return this->company; }

void Employee::raiseSallaryBePercent(int percent) {
  this->sallary *= (percent / 100) + 1;
}
