#include "../include/E_Security.hpp"

E_Security::E_Security(std::string name, std::string security_area)
    : Employee(name) {
  this->security_area = security_area;
}
