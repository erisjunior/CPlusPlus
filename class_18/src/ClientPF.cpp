#include "../include/ClientPF.hpp"

ClientPF::ClientPF(std::string name, std::string cpf) : Client(name) {
  this->cpf = cpf;
}
