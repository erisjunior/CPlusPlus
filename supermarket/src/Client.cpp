#include "../include/Client.hpp"

Client::Client() { this->balance = 0; }

void Client::save(int client_number) {
  std::string file_name = "client_" + std::to_string(client_number) + ".txt";
  std::ofstream file{file_name};

  if (!file.is_open()) {
    return;
  }

  float total = 0;
  for (size_t i = 0; i < this->cart.size; i++) {
    Product product = this->cart.elements[i];
    if (product.sold_qnt > 0) {
      float product_profit = product.price * product.sold_qnt;
      total += product_profit;

      file << "#" << product.code << " " << product.name << " | R$ "
           << product.price << " | Quantidade" << product.sold_qnt
           << " | Total: R$ " << product_profit << std::endl;
    }
  }

  file << std::endl << "Gastos do cliente: " << total << std::endl;
  file << "Saldo do cliente: " << this->balance << std::endl;

  file.close();
}

void Client::add_funds(float amount) { this->balance += amount; }

void Client::add_product(Product product) {
  this->balance -= product.price;

  for (size_t i = 0; i < this->cart.size; i++) {
    if (this->cart.elements[i].code == product.code) {
      this->cart.elements[i].sold_qnt += 1;

      return;
    }
  }

  product.sold_qnt = 1;
  this->cart.push(product);
}
