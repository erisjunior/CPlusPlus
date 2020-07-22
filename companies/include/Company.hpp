#ifndef COMPANY_HPP
#define COMPANY_HPP

#include "Product.hpp"
#include "vector_supermarket.hpp"
#include <fstream>
#include <sstream>

class Company {
public:
  vector_supermarket<Product> products;

  void load_file();
  void save_file();

  void list_products();
};

#endif
