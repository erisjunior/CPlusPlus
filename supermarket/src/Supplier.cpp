#include "../include/Supplier.hpp"

Supplier::Supplier() { load_file(); }

Supplier::~Supplier() { save_file(); }

void Supplier::load_file() {
  std::ifstream file;
  file.open("fornecedor.csv");

  if (!file.is_open()) {
    return;
  }

  std::string line;
  std::string number;
  Product product;

  while (!file.eof()) {
    std::getline(file, line);
    if (line.size() == 0) {
      continue;
    }

    std::stringstream stream(line);

    std::getline(stream, product.name, ',');
    if (product.name == "PRODUTO") {
      continue;
    }

    std::getline(stream, number, ',');
    product.qnt = std::stoi(number);

    this->products.push(product);
  }

  file.close();
}

void Supplier::save_file() {
  std::ofstream file{"fornecedor.csv"};

  if (!file.is_open()) {
    return;
  }

  file << "PRODUTO,QUANTIDADE" << std::endl;

  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    file << product.name << "," << product.qnt - product.sold_qnt << std::endl;
  }

  file.close();
}

void Supplier::list_products() {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.qnt - product.sold_qnt > 0) {
      std::cout << product.name
                << " | Quantidade restante: " << product.qnt - product.sold_qnt
                << std::endl;
    }
  }
}

int Supplier::supply(std::string name, int qnt) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.name == name) {
      if (product.qnt - product.sold_qnt >= qnt) {
        this->products.elements[i].sold_qnt += qnt;
        return 1;
      }
      return 0;
    }
  }
}
