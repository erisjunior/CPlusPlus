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

    this->products.push_back(product);
  }

  file.close();
}

void Market::save_file() {
  std::ofstream file{"caixa.csv"};

  if (!file.is_open()) {
    return;
  }

  file << "COD,PRODUTO,PREÇO,QUANTIDADE VENDIDA,LUCRO" << std::endl;

  for (auto product : this->products) {
    if (product.sold_qnt > 0) {
      file << product.code << "," << product.name << ",R$ " << product.price
           << "," << product.sold_qnt << "," << product.sold_qnt * product.price
           << std::endl;
    }
  }

  file.close();
}

void Market::list_products() {
  for (auto product : this->products) {
    if (product.qnt - product.sold_qnt > 0) {
      std::cout << "#" << product.code << " " << product.name << " | R$"
                << product.price
                << " | Quantidade restante: " << product.qnt - product.sold_qnt
                << std::endl;
    }
  }
}

void Market::list_info() {
  float total = 0;
  for (auto product : this->products) {
    if (product.qnt - product.sold_qnt > 0) {
      float product_profit = product.price * product.sold_qnt;
      total += product_profit;

      std::cout << "#" << product.code << " " << product.name
                << " | Quantidade vendida: " << product.sold_qnt
                << " | Lucro: R$" << product_profit << std::endl;
    }
  }
  std::cout << std::endl << "Lucro Total: R$ " << total << std::endl;
}

int Market::has_product(int code) {
  for (auto product : this->products) {
    if (product.code == code) {
      return 1;
    }
  }
  return 0;
}

Product Market::find_product(int code) {
  for (auto product : this->products) {
    if (product.code == code) {
      return product;
    }
  }
}

void Market::sell(int code) {
  for (size_t i = 0; i < this->products.size(); i++) {
    if (this->products[i].code == code) {
      this->products[i].sold_qnt += 1;
      return;
    }
  }
}
