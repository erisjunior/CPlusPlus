#include "../include/Product.hpp"

Product::Product() {
  this->code = 0;
  this->name = "";
  this->und = "";
  this->price = 0;
  this->qnt = 0;
  this->sold_qnt = 0;
}

Product::Product(int code, std::string name, std::string und, float price,
                 int qnt) {
  this->code = code;
  this->name = name;
  this->und = und;
  this->price = price;
  this->qnt = qnt;
  this->sold_qnt = 0;
}
