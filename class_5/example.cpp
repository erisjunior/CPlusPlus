#include <fstream>
#include <iostream>
#include <string>

#include "usage.h"

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
