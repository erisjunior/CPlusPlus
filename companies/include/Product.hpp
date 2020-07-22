#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
public:
  Product();
  Product(int code, std::string name, std::string und, float price, int qnt);

  int code;
  std::string name;
  std::string und;
  float price;
  int qnt;
  int sold_qnt;
};

#endif
