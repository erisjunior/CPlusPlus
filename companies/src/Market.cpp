#include "../include/Market.hpp"

Market::Market() {
  try {
    load_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

Market::~Market() {
  try {
    save_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

void Market::load_file() {
  std::ifstream file;
  file.open("estoque.csv");

  if (!file.is_open()) {
    throw(std::string("Impossible to read the market file"));
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
    throw(std::string("Impossible to create market cashier file"));
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

Product Market::find_product(int code) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.code == code) {
      return product;
    }
  }
  throw(std::string("Product not found"));
}

void Market::sell(int code) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.code == code) {
      if (product.qnt - product.sold_qnt < 1) {
        throw(std::string("Product out of stock"));
      }

      this->products.elements[i].sold_qnt += 1;
      return;
    }
  }
  throw(std::string("Product not found"));
}
