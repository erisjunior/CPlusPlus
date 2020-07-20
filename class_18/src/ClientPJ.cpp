#include "../include/ClientPJ.hpp"

ClientPJ::ClientPJ(std::string name, std::string cnpj) : Client(name) {
  this->cnpj = cnpj;
}
