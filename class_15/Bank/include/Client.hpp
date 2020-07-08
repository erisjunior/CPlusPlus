#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
  std::string name;
  std::string cpf;

  Client(std::string name);
  Client();
};

#endif
