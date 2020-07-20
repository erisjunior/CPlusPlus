#ifndef CLIENTPJ_H
#define CLIENTPJ_H

#include "Client.hpp"

class ClientPJ : public Client {
public:
  std::string cnpj;

  ClientPJ(std::string name, std::string cnpj);
};

#endif
