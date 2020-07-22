#ifndef MARKET_HPP
#define MARKET_HPP

#include "Company.hpp"

class Market : public Company {
public:
  Market();
  ~Market();

  void load_file();
  void save_file();

  void fill_product_stock(std::string name, int qnt);

  int has_product(int code);
  Product find_product(int code);

  void sell(int product_code);
};

#endif
