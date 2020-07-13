#include "include/Company.hpp"

Company::Company() {}

void Company::setName(std::string name) { this->name = name; }

void Company::setCNPJ(std::string cnpj) { this->cnpj = cnpj; }

std::string Company::getName() { return this->name; }

std::string Company::getCNPJ() { return this->cnpj; }
