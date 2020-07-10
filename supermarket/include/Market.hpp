#ifndef MARKET_HPP
#define MARKET_HPP

#include "Product.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Market {
public:
  Market();
  ~Market();

  std::vector<Product> products;

  void load_file();
  void save_file();

  void list_products();
  void list_info();

  int has_product(int code);
  Product find_product(int code);

  void sell(int product_code);
};

#endif
