#ifndef APP_HPP
#define APP_HPP

#include "Client.hpp"
#include "Market.hpp"
#include "Product.hpp"
#include "Restaurant.hpp"
#include "Supplier.hpp"
#include <iostream>

class App {
public:
  App();

  Restaurant restaurant;
  Market market;
  Client client;
  Supplier supplier;

  int clients_number;

  // Menu
  void run();
  void run_market();
  void run_restaurant();

  // Client
  void add_funds_to_client();
  void add_product_to_client();
  void add_food_to_client();
  void list_client_cart();

  // Market
  void list_market_products();
  void list_market_info();

  // Market Supplier
  void list_supplier_products();
  void supply_market();

  // Restaurant
  void list_restaurant_products();

  void show_usage();
  void show_market_usage();
  void show_restaurant_usage();
  void show_init_other_client();
};

#endif
