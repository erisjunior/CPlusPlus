#include <fstream>
#include <iostream>
#include <string.h>

void printSuccess() { std::cout << "Mensagem adicionada" << std::endl; }

void printUseCase(const std::string &prog_name) {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;
}

int main(int argc, char const *argv[]) {
  std::string prog_name = argv[0];

  if (argc == 1) {
    printUseCase(prog_name);
    return 1;
  }

  std::string action = argv[1];

  if (action == "add") {
    std::string message;

    if (argc > 2) {
      message = argv[2];
    } else {
      std::cin >> message;
    }

    std::ofstream output_file{"diary", std::ios::app};

    output_file << message << std::endl;

    printSuccess();
    return 0;
  }

  if (action == "list") { // não finalizada
    std::string diary;
    std::ifstream input_file{"diary"};

    if (input_file.fail()) {
      std::cout << "Arquivo não encontrado." << std::endl;
      return 1;
    }

    input_file >> diary;
    std::cout << diary;

    return 0;
  }

  printUseCase(prog_name);
  return 1;
}
