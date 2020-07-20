#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
  int id;
  std::string name;

  static int clients_amount;

protected:
  Client(std::string name);
};

#endif
