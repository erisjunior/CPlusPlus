#include "../include/Market.hpp"

Market::Market() { load_file(); }

Market::~Market() { save_file(); }

void Market::load_file() {
  std::ifstream file;
  file.open("estoque.csv");

  if (!file.is_open()) {
    return;
  }

  std::string line;
  Product product;
  std::string number;

  while (!file.eof()) {
    std::getline(file, line);
    if (line.size() == 0) {
      continue;
    }

    std::stringstream stream(line);

    std::getline(stream, number, ',');
    if (number == "COD") {
      continue;
    }
    product.code = std::stoi(number);

    std::getline(stream, product.name, ',');
    std::getline(stream, product.und, ',');

    std::getline(stream, number, ',');
    product.price = std::stof(number.substr(3));

    std::getline(stream, number, ',');
    product.qnt = std::stoi(number);

    this->products.push(product);
  }

  file.close();
}

void Market::save_file() {
  std::ofstream file{"supermarket_cashier.csv"};

  if (!file.is_open()) {
    return;
  }

  file << "COD,PRODUTO,PREÇO,QUANTIDADE VENDIDA,LUCRO" << std::endl;

  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.sold_qnt > 0) {
      file << product.code << "," << product.name << ",R$ " << product.price
           << "," << product.sold_qnt << ",R$ "
           << product.sold_qnt * product.price << std::endl;
    }
  }

  file.close();
}

void Market::fill_product_stock(std::string name, int qnt) {
  for (size_t i = 0; i < this->products.size; i++) {
    if (this->products.elements[i].name == name) {
      this->products.elements[i].qnt += qnt;
      return;
    }
  }
}

int Market::has_product(int code) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.code == code) {
      return 1;
    }
  }
  return 0;
}

Product Market::find_product(int code) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.code == code) {
      return product;
    }
  }
}

void Market::sell(int code) {
  for (size_t i = 0; i < this->products.size; i++) {
    if (this->products.elements[i].code == code) {
      this->products.elements[i].sold_qnt += 1;
      return;
    }
  }
}
