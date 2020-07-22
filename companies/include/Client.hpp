#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Product.hpp"
#include "vector_supermarket.hpp"
#include <fstream>
#include <iostream>

class Client {
public:
  Client();

  float balance;

  vector_supermarket<Product> cart;

  void add_funds(float amount);
  void add_product(Product product);

  void save(int client_number, std::string preffix);
};

#endif
