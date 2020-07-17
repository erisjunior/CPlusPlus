#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include "Product.hpp"
#include "vector_supermarket.hpp"
#include <fstream>
#include <sstream>

class Supplier {
public:
  vector_supermarket<Product> products;

  Supplier();
  ~Supplier();

  void load_file();
  void save_file();

  void list_products();
  int supply(std::string name, int qnt);
};

#endif
