#include "../include/Diary.h"
#include "../include/Message.h"

#include <fstream>
#include <iostream>

Diary::Diary(const std::string &filename)
    : filename(filename), messages_capacity(10), messages_size(0),
      messages(nullptr) {
  messages = new Message[messages_capacity];
}

void Diary::add(const std::string &messageContent) {
  if (messages_capacity <= messages_size) {
    std::cout << "Capacidade máxima do diário atingida" << std::endl;
    return;
  }

  Message message;

  message.content = messageContent;

  // std::string date = get_current_date();

  // if (get_last_date() != date) {
  //   file << "# " << date << std::endl << std::endl;
  // }

  messages[messages_size] = message;
  messages_size += 1;
}

void Diary::write() {
  // std::ofstream file{filename, std::ios::app};

  // if (!file.is_open()) {
  // std::cerr << "Arquivo não pode ser criado" << std::endl;
  // return 1;
  // }
}
