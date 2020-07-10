#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Product.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Client {
public:
  Client();

  float balance;

  std::vector<Product> cart;

  void add_funds(float amount);
  void add_product(Product product);

  void save(int client_number);
};

#endif
