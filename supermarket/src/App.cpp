#include "../include/App.hpp"

App::App() { this->clients_number = 1; }

int App::run(int argc, char **argv) {
  std::string action = "";

  show_usage();

  while (true) {
    std::cout << std::endl << "Select your action: ";
    std::cin >> action;
    std::cin.ignore();

    if (action == "1") {
      add_funds_to_client();
    } else if (action == "2") {
      list_market_products();
    } else if (action == "3") {
      add_product_to_client();
    } else if (action == "4") {
      list_client_cart();
    } else if (action == "5") {
      list_supplier_products();
    } else if (action == "6") {
      supply_market();
    } else if (action == "0") {
      this->client.save(clients_number);
      this->clients_number += 1;

      show_init_other_client();

      std::string choice;
      std::cin >> choice;

      if (choice == "2") {
        return 0;
      } else {
        Client new_client;
        this->client = new_client;
        show_usage();
      }
    }
  }

  return 0;
}

void App::add_funds_to_client() {
  float amount;

  std::cout << "Amount to add to funds: ";
  std::cin >> amount;

  this->client.add_funds(amount);
}

void App::list_market_products() { this->market.list_products(); }

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
    std::cout << "Produto sem estoque" << std::endl;
    return;
  }

  this->market.sell(product.code);
  this->client.add_product(product);
}

void App::list_client_cart() {
  std::cout << std::endl;
  for (size_t i = 0; i < this->client.cart.size; i++) {
    Product product = this->client.cart.elements[i];
    show_product(product);
  }
}

void App::list_supplier_products() { this->supplier.list_products(); }

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

void App::show_product(Product product) {
  std::cout << "#" << product.code << " " << product.name << " | R$"
            << product.price << " | Qnt: " << product.sold_qnt << std::endl;
}

void App::show_usage() {
  std::cout << "Supermarket 1.0" << std::endl << std::endl;
  std::cout << "1) Add funds to your client" << std::endl;
  std::cout << "2) List market products" << std::endl;
  std::cout << "3) Add product to client cart" << std::endl;
  std::cout << "4) Show client cart" << std::endl;
  std::cout << "5) Show supplier products" << std::endl;
  std::cout << "6) Supply amount to market" << std::endl;
  std::cout << "0) Finish Client" << std::endl << std::endl;
}

void App::show_init_other_client() {
  std::cout << "Do you want to start a new client?" << std::endl << std::endl;
  std::cout << "1) Yes" << std::endl;
  std::cout << "2) No" << std::endl;
  std::cout << "Select your action: ";
}
