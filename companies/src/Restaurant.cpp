#include "../include/Restaurant.hpp"

Restaurant::Restaurant() {
  try {
    load_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

Restaurant::~Restaurant() {
  try {
    save_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

void Restaurant::load_file() {
  std::ifstream file;
  file.open("menu.csv");

  if (!file.is_open()) {
    throw(std::string("Impossible to read the restaurant file"));
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

    std::getline(stream, product.name, ',');
    if (product.name == "ITEM") {
      continue;
    }
    std::getline(stream, number, ',');
    product.price = std::stof(number.substr(3));

    this->products.push(product);
  }

  file.close();
}

void Restaurant::save_file() {
  std::ofstream file{"restaurant_cashier.csv"};

  if (!file.is_open()) {
    throw(std::string("Impossible to create restaurant cashier file"));
  }

  file << "ITEM,PREÇO,QUANTIDADE VENDIDA,LUCRO" << std::endl;

  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.sold_qnt > 0) {
      file << product.name << ",R$ " << product.price << "," << product.sold_qnt
           << ",R$ " << product.sold_qnt * product.price << std::endl;
    }
  }

  file.close();
}

Product Restaurant::find_product(std::string product_name) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.name == product_name) {
      return product;
    }
  }
  throw(std::string("Product not found"));
}

void Restaurant::sell(std::string product_name, int qnt) {
  for (size_t i = 0; i < this->products.size; i++) {
    if (this->products.elements[i].name == product_name) {
      this->products.elements[i].sold_qnt += qnt;
      return;
    }
  }
  throw(std::string("Product not found"));
}
