#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::ifstream file;

  file.open("messages");

  if (!file.is_open()) {
    std::cerr << "Arquivo não existente ou sem permissão" << std::endl;
    return 1;
  }

  std::string message;

  int line_number = 0;

  while (!file.eof()) {
    ++line_number;
    std::getline(file, message);

    if (message.size() == 0) {
      continue;
    }
    std::cout << line_number << ". " << message << std::endl;
  }

  file.close();

  return 0;
}
