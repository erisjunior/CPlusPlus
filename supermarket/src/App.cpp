#include "../include/App.hpp"

App::App() {}

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
      add_product_to_client();
    } else if (action == "3") {
      list_client_cart();
    } else if (action == "0") {
      show_init_other_client();

      std::string choice;
      std::cin >> choice;

      if (choice == "2") {
        return 0;
      } else {
        show_usage();
      }
    }
  }

  return 0;
}

void App::add_funds_to_client() {
  float amount;

  std::cout << "Valor para adicionar ao saldo: ";
  std::cin >> amount;

  this->client.add_funds(amount);
}

void App::add_product_to_client() {
  float code;

  std::cout << "Código do produto: ";
  std::cin >> code;

  int has_product = this->market.has_product(code);
  if (has_product == 0) {
    std::cout << "Produto indisponivel" << std::endl;
    return;
  }

  Product product = this->market.find_product(code);

  if (product.price > this->client.balance) {
    std::cout << "Saldo insuficiente" << std::endl;
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
  for (auto product : this->client.cart) {
    show_product(product);
  }
}

void App::show_product(Product product) {
  std::cout << "#" << product.code << " " << product.name << " | R$"
            << product.price << " | Qnt: " << product.sold_qnt << std::endl;
}

void App::show_usage() {
  std::cout << "Supermarket 1.0" << std::endl << std::endl;
  std::cout << "1) Add funds to your client" << std::endl;
  std::cout << "2) Add product to client cart" << std::endl;
  std::cout << "3) Show client cart" << std::endl;
  std::cout << "0) Finish Client" << std::endl << std::endl;
}

void App::show_init_other_client() {
  std::cout << "Do you want to start a new client?" << std::endl << std::endl;
  std::cout << "1) Yes" << std::endl;
  std::cout << "2) No" << std::endl;
  std::cout << "Select your action: ";
}
