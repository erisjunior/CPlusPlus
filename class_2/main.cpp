#include <iostream>
#include <string.h>

void printSuccess() { std::cout << "Mensagem adicionada" << std::endl; }

void printUseCase() { std::cout << "Uso: ./prog add <mensagem>" << std::endl; }

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    printUseCase();
    return -1;
  }
  std::string action = argv[1];
  // std::string action{argv[1]};

  if (action != "add") {
    printUseCase();
    return -1;
  }

  std::string message;

  if (argc > 2) {
    message = argv[2];
  } else {
    std::cin >> message;
  }

  printSuccess();

  return 0;
}
