#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include "Product.hpp"
#include "vector_supermarket.hpp"

class Supplier {
public:
  vector_supermarket<Product> products;

  Supplier();

  void list_products();
  void suply();
};

#endif
