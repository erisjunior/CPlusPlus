#include "../include/App.hpp"

App::App() { this->clients_number = 1; }

/** @Menu */

void App::run() {
  show_usage();
  std::string action = "";

  std::cout << std::endl << "Select your action: ";
  std::cin >> action;

  if (action == "1") {
    run_market();
  } else if (action == "2") {
    run_restaurant();
  }
}

void App::run_market() {
  show_market_usage();
  std::string action;

  while (true) {
    std::cout << std::endl << "Select your action: ";
    std::cin >> action;
    std::cin.ignore();

    if (action == "1") {
      add_funds_to_client();
    } else if (action == "2") {
      add_product_to_client();
    } else if (action == "3") {
      list_client_cart();
    } else if (action == "4") {
      list_market_products();
    } else if (action == "5") {
      list_market_info();
    } else if (action == "6") {
      list_supplier_products();
    } else if (action == "7") {
      supply_market();
    } else if (action == "0") {
      this->client.save(clients_number, "market");
      this->clients_number += 1;

      show_init_other_client();

      std::string choice;
      std::cin >> choice;

      if (choice != "1") {
        return;
      }

      Client new_client;
      this->client = new_client;
      show_market_usage();
    }
  }
}

void App::run_restaurant() {
  show_restaurant_usage();
  std::string action;

  while (true) {
    std::cout << std::endl << "Select your action: ";
    std::cin >> action;
    std::cin.ignore();

    if (action == "1") {
      add_funds_to_client();
    } else if (action == "2") {
      add_food_to_client();
    } else if (action == "3") {
      list_client_cart();
    } else if (action == "4") {
      list_restaurant_products();
    } else if (action == "0") {
      this->client.save(clients_number, "restaurant");
      this->clients_number += 1;

      show_init_other_client();

      std::string choice;
      std::cin >> choice;

      if (choice != "1") {
        return;
      }

      Client new_client;
      this->client = new_client;
      show_restaurant_usage();
    }
  }
}

/** @Client */

void App::add_funds_to_client() {
  float amount;

  std::cout << "Amount to add to funds: ";
  std::cin >> amount;

  this->client.add_funds(amount);
}

void App::add_product_to_client() {
  float code;

  std::cout << "Product code: ";
  std::cin >> code;

  int has_product = this->market.has_product(code);
  if (has_product == 0) {
    std::cout << "Unavailable product" << std::endl;
    return;
  }

  Product product = this->market.find_product(code);

  if (product.price > this->client.balance) {
    std::cout << "Insufficient funds" << std::endl;
    return;
  }

  if (product.qnt - product.sold_qnt < 1) {
    std::cout << "Out of stock" << std::endl;
    return;
  }

  this->market.sell(product.code);
  this->client.add_product(product);
}

void App::add_food_to_client() {
  std::string name;
  int qnt;

  std::cout << "Product name: ";
  std::getline(std::cin, name);
  std::cout << "Product quantity: ";
  std::cin >> qnt;

  Product product = this->restaurant.find_product(name);

  if (product.price * qnt > this->client.balance) {
    std::cout << "Insufficient funds" << std::endl;
    return;
  }

  this->restaurant.sell(name, qnt);
  this->client.add_product(product);
}

void App::list_client_cart() {
  std::cout << std::endl;
  for (size_t i = 0; i < this->client.cart.size; i++) {
    Product product = this->client.cart.elements[i];
    std::cout << product.name << " | R$" << product.price
              << " | Qnt: " << product.sold_qnt << std::endl;
  }
}

/** @Market */

void App::list_market_products() {
  for (size_t i = 0; i < this->market.products.size; i++) {
    Product product = this->market.products.elements[i];
    if (product.qnt - product.sold_qnt > 0) {
      std::cout << "#" << product.code << " " << product.name << " | R$"
                << product.price
                << " | Remaining quantity: " << product.qnt - product.sold_qnt
                << std::endl;
    }
  }
}

void App::list_market_info() {
  float total = 0;
  for (size_t i = 0; i < this->market.products.size; i++) {
    Product product = this->market.products.elements[i];
    if (product.qnt - product.sold_qnt > 0) {
      float product_profit = product.price * product.sold_qnt;
      total += product_profit;

      std::cout << "#" << product.code << " " << product.name
                << " | Sold quantity: " << product.sold_qnt << " | Profit: R$"
                << product_profit << std::endl;
    }
  }
  std::cout << std::endl << "Total profit: R$ " << total << std::endl;
}

/** @Market Supplier */

void App::list_supplier_products() {
  for (size_t i = 0; i < this->supplier.products.size; i++) {
    Product product = this->supplier.products.elements[i];
    if (product.qnt - product.sold_qnt > 0) {
      std::cout << product.name
                << " | Remaining quantity: " << product.qnt - product.sold_qnt
                << std::endl;
    }
  }
}

void App::supply_market() {
  std::string product_name;
  int product_qnt;

  std::cout << "Enter the product name: ";
  std::getline(std::cin, product_name);
  std::cout << "Enter quantity: ";
  std::cin >> product_qnt;

  int supply_result = this->supplier.supply(product_name, product_qnt);

  if (supply_result == 0) {
    this->market.fill_product_stock(product_name, product_qnt);
  }
}

/** @Restaurant */

void App::list_restaurant_products() {
  for (size_t i = 0; i < this->restaurant.products.size; i++) {
    Product product = this->restaurant.products.elements[i];
    std::cout << product.name << " | R$" << product.price << std::endl;
  }
}

/** @Show */

void App::show_usage() {
  std::cout << "Initialize program as:" << std::endl << std::endl;
  std::cout << "1) Market" << std::endl;
  std::cout << "2) Restaurant" << std::endl;
}

void App::show_market_usage() {
  std::cout << "Supermarket 1.0" << std::endl << std::endl;
  std::cout << "1) Add funds to your client" << std::endl;
  std::cout << "2) Add product to client cart" << std::endl;
  std::cout << "3) Show client cart" << std::endl;
  std::cout << "4) List market products" << std::endl;
  std::cout << "5) Show market info" << std::endl;
  std::cout << "6) Show supplier products" << std::endl;
  std::cout << "7) Supply amount to market" << std::endl;
  std::cout << "0) Finish Client" << std::endl << std::endl;
}

void App::show_restaurant_usage() {
  std::cout << "Restaurant 1.0" << std::endl << std::endl;
  std::cout << "1) Add funds to your client" << std::endl;
  std::cout << "2) Make an order" << std::endl;
  std::cout << "3) Show client bill" << std::endl;
  std::cout << "4) List restaurant products" << std::endl;
  std::cout << "0) Finish Client" << std::endl << std::endl;
}

void App::show_init_other_client() {
  std::cout << "Do you want to start a new client?" << std::endl << std::endl;
  std::cout << "1) Yes" << std::endl;
  std::cout << "2) No" << std::endl;
  std::cout << "Select your action: ";
}
