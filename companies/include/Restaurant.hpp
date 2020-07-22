#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Company.hpp"

class Restaurant : public Company {
public:
  Restaurant();
  ~Restaurant();

  void load_file();
  void save_file();

  Product find_product(std::string product_name);

  void sell(std::string product_name, int qnt);
};

#endif
