#ifndef CLIENTPF_H
#define CLIENTPF_H

#include "Client.hpp"

class ClientPF : public Client {
public:
  std::string cpf;

  ClientPF(std::string name, std::string cpf);
};

#endif
