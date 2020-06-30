#include "../include/App.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename) {}

int App::run(int argc, char **argv) {
  const std::string prog_name = argv[0];

  if (argc == 1) {
    return show_usage(prog_name);
  }

  std::string action = argv[1];

  if (action == "add") {
    if (argc == 2) {
      return add();
    }

    return add(argv[2]);
  }

  if (action == "list") {
    return list();
  }

  if (action == "search") {
    if (argc > 2) {
      return search(argv[2]);
    }
  }

  return show_usage(prog_name);
}

int App::add() {
  std::string message;
  std::cout << "Enter your message: " << std::endl;
  std::getline(std::cin, message);

  return add(message);
}

int App::add(const std::string message) {
  diary.add(message);
  diary.write();

  return 0;
}

int App::list() {
  for (size_t i = 0; i < diary.messages_size; i++) {
    const Message &message = diary.messages[i];
    std::cout << "- " << message.content << std::endl;
  }
  return 0;
}

int App::search(const std::string search_value) {
  Message *message = diary.search(search_value);

  if (message) {
    std::cout << "# " << message[0].date.to_string() << " - "
              << message[0].time.to_string() << " | " << message[0].content
              << std::endl;
    return 0;
  }

  std::cout << "Não existe mensagem com esse termo." << std::endl;
  return 1;
}

int App::show_usage(const std::string prog_name) {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;
  std::cout << prog_name << " search <termo de busca>" << std::endl;

  return 1;
}
