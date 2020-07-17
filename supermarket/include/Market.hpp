#ifndef MARKET_HPP
#define MARKET_HPP

#include "Product.hpp"
#include "vector_supermarket.hpp"
#include <fstream>
#include <sstream>

class Market {
public:
  Market();
  ~Market();

  vector_supermarket<Product> products;

  void load_file();
  void save_file();

  void list_products();
  void list_info();

  void fill_product_stock(std::string name, int qnt);

  int has_product(int code);
  Product find_product(int code);

  void sell(int product_code);
};

#endif
