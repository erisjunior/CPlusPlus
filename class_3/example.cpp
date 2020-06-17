#include <fstream>
#include <iostream>
#include <string>

void show_usage(const std::string &prog_name);

int main(int argc, char const *argv[]) {
  std::ifstream input_file{"input"};                  // cin
  std::ofstream output_file{"output", std::ios::app}; // cout

  if (input_file.fail()) {
    std::cout << "Arquivo não encontrado." << std::endl;
  }

  // input_file >> nome;
  output_file << std::endl << "Juinaun";

  return 0;
}

void show_usage(const std::string &prog_name) {
  std::cout << "Uso: " << prog_name << "add <message> " << std::endl;
}
