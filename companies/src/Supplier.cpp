#include "../include/Supplier.hpp"

Supplier::Supplier() {
  try {
    load_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

Supplier::~Supplier() {
  try {
    save_file();
  } catch (const std::string err) {
    std::cout << err << std::endl << std::endl;
  }
}

void Supplier::load_file() {
  std::ifstream file;
  file.open("fornecedor.csv");

  if (!file.is_open()) {
    throw(std::string("Impossible to read the supplier file"));
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
    throw(std::string("Impossible to save the supplier file"));
  }

  file << "PRODUTO,QUANTIDADE" << std::endl;

  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    file << product.name << "," << product.qnt - product.sold_qnt << std::endl;
  }

  file.close();
}

void Supplier::supply(std::string name, int qnt) {
  for (size_t i = 0; i < this->products.size; i++) {
    Product product = this->products.elements[i];
    if (product.name == name) {
      if (product.qnt - product.sold_qnt < qnt) {
        throw(std::string("Insufficient amount in stock"));
      }

      this->products.elements[i].sold_qnt += qnt;
    }
  }
}
