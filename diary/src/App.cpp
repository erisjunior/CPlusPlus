#include "../include/App.h"

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
  for (auto message : diary.messages) {
    std::cout << "- " << message.content << std::endl;
  }
  return 0;
}

int App::search(const std::string search_value) {
  std::vector<Message *> messages_vector = diary.search(search_value);

  if (messages_vector.empty()) {
    std::cout << "Não existe mensagem com esse termo." << std::endl;
  } else {
    std::cout << messages_vector.size() << std::endl;
    for (auto message : messages_vector) {
      std::cout << "# " << message->content << std::endl;
    }
  }

  return 0;
}

int App::show_usage(const std::string prog_name) {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;
  std::cout << prog_name << " search <termo de busca>" << std::endl;

  return 1;
}
