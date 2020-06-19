#include <ctime>
#include <fstream>
#include <iostream>
#include <string.h>

void print_success() { std::cout << "Mensagem adicionada" << std::endl; }

int print_use_case(const std::string &prog_name) {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;

  return 1;
}

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);

  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }
std::string get_current_time() { return format_current_date("%H:%M:%S"); }

std::string get_last_date() {
  std::ifstream input_file;
  input_file.open("diary");

  if (!input_file.is_open()) {
    return "";
  }

  std::string line;
  std::string date;

  while (!input_file.eof()) {
    std::getline(input_file, line);

    if (line[0] == '#') {
      date = line;
    }
  }

  input_file.close();
  if (date.size() == 0) {
    return "";
  }

  return date.substr(2);
}

int list_messages() {
  std::ifstream input_file;

  input_file.open("diary");

  if (!input_file.is_open()) {
    std::cerr << "Arquivo não existente ou você não tem permissão para isso"
              << std::endl;
    return 1;
  }

  std::string message;

  int line_number = 0;

  while (!input_file.eof()) {
    std::getline(input_file, message);

    if (message.size() == 0) {
      continue;
    }
    if (message[0] == '#') {
      continue;
    }

    ++line_number;
    std::cout << line_number << ". " << message.substr(13) << std::endl;
  }

  input_file.close();
  return 0;
}

int main(int argc, char const *argv[]) {
  std::string prog_name = argv[0];

  if (argc == 1) {
    return print_use_case(prog_name);
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

    if (!output_file.is_open()) {
      std::cerr << "Arquivo não pode ser criado" << std::endl;
      return 1;
    }

    std::string date = get_current_date();

    std::cout << get_current_date() << std::endl;
    std::cout << get_last_date() << std::endl;
    if (get_last_date() != date) {
      output_file << "# " << date << std::endl << std::endl;
    }

    output_file << "- " << get_current_time() << " | " << message << std::endl;

    output_file.close();

    print_success();
    return 0;
  }

  if (action == "list") {
    return list_messages();
  }

  return print_use_case(prog_name);
}
