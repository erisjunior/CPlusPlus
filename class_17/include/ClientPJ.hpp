#ifndef CLIENTPJ_H
#define CLIENTPJ_H

#include <string>

class ClientPJ {
public:
  std::string company_name;
  std::string cnpj;

  ClientPJ(std::string company_name);
  ClientPJ();
};

#endif
