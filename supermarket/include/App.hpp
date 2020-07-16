#ifndef APP_HPP
#define APP_HPP

#include "Client.hpp"
#include "Market.hpp"
#include "Product.hpp"

class App {
public:
  App();

  Market market;
  Client client;

  int clients_number;

  int run(int argc, char *argv[]);

  void list_market_products();
  void add_funds_to_client();
  void add_product_to_client();
  void list_client_cart();

  void show_product(Product product);

  void show_usage();
  void show_init_other_client();
};

#endif
