#include "../include/E_Manager.hpp"

E_Manager::E_Manager(std::string name, std::string sector) : Employee(name) {
  this->sector = sector;
}
