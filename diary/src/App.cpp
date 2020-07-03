#include "../include/App.h"

App::App(const std::string &filename, const std::string &format)
    : diary(filename), format(format) {}

int App::run(int argc, char **argv) {
  prog_name = argv[0];

  if (argc == 1) {
    return show_usage();
  }

  std::string action = argv[1];

  if (action == "add") {
    if (argc == 2) {
      return add();
    }

    return add(argv[2]);
  }

  if (action == "list") {
    if (argc == 2) {
      return list("");
    }
    return list(argv[2]);
  }

  if (action == "search") {
    if (argc > 2) {
      return search(argv[2]);
    }
  }

  if (action == "interactive") {
    return interactive_interface();
  }

  return show_usage();
}

int App::interactive_interface() {
  std::string action = "";

  show_interactive_usage();

  while (action != "0") {
    if (action != "") {
      std::cout << "Select your action: ";
    }

    std::cin >> action;
    std::cin.ignore();

    if (action == "1") {
      list("");
    } else if (action == "2") {
      add();
    }
  }
  return 0;
}

int App::add() {
  std::string message;
  std::cout << "Enter your message: ";
  std::getline(std::cin, message);

  return add(message);
}

int App::add(const std::string message) {
  diary.add(message);
  diary.write();

  return 0;
}

int App::list(std::string extra_format) {
  std::string message_format = format;

  if (extra_format != "") {
    message_format = extra_format;
  }

  for (auto message : diary.messages) {
    print_formated_message(message, message_format);
  }
  return 0;
}

void App::print_formated_message(Message &message, const std::string format) {
  std::stringstream formated_message;

  int is_mask = 0;

  for (auto character : format) {
    if (is_mask) {
      if (character == 'm') {
        formated_message << message.content;
      } else if (character == 'd') {
        formated_message << message.date.to_string();
      } else if (character == 't') {
        formated_message << message.time.to_string();
      }
      is_mask = 0;
      continue;
    }

    if (character == '%') {
      is_mask = 1;
      continue;
    }

    formated_message << character;
  }

  std::cout << formated_message.str() << std::endl;
}

int App::search(const std::string search_value) {
  std::vector<Message *> messages_vector = diary.search(search_value);

  if (messages_vector.empty()) {
    std::cout << "Não existe mensagem com esse termo." << std::endl;
  } else {
    for (auto message : messages_vector) {
      std::cout << "# " << message->date.to_string() << " - "
                << message->time.to_string() << " | " << message->content
                << std::endl;
    }
  }

  return 0;
}

int App::show_usage() {
  std::cout << "Uso: " << std::endl;
  std::cout << prog_name << " interactive" << std::endl;
  std::cout << prog_name << " add <mensagem>" << std::endl;
  std::cout << prog_name << " list" << std::endl;
  std::cout << prog_name << " search <termo de busca>" << std::endl;

  return 1;
}

void App::show_interactive_usage() {
  std::cout << "Diary 1.0" << std::endl << std::endl;
  std::cout << "Select your action: " << std::endl << std::endl;
  std::cout << "1) List messages" << std::endl;
  std::cout << "2) Add new message" << std::endl;
  std::cout << "0) End" << std::endl << std::endl;
}
