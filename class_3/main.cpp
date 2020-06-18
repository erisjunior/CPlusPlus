#include <fstream>
#include <iostream>
#include <string.h>

void printSuccess() { std::cout << "Mensagem adicionada" << std::endl; }

void printUseCase(const std::string &prog_name) {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;
}

void addMessage() {}

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
      std::cout << "Informe a mensagem: " << std::endl;
      std::getline(std::cin, message);
    }

    std::ofstream output_file{"diary", std::ios::app};

    output_file << message << std::endl;

    printSuccess();
    return 0;
  }

  if (action == "list") {
    std::ifstream input_file;

    input_file.open("diary");

    if (!input_file.is_open()) {
      std::cerr << "Arquivo não existente ou sem permissão" << std::endl;
      return 1;
    }

    std::string message;

    int line_number = 0;

    while (!input_file.eof()) {
      ++line_number;
      std::getline(input_file, message);

      if (message.size() == 0) {
        continue;
      }
      std::cout << line_number << ". " << message << std::endl;
    }

    input_file.close();

    return 0;
  }

  printUseCase(prog_name);
  return 1;
}
