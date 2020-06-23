#include "../include/Diary.h"
#include "../include/Message.h"

#include <fstream>
#include <iostream>

Diary::Diary(const std::string &filename) : filename(filename) {}

void Diary::add(const std::string &messageContent) {
  // std::ofstream file{filename, std::ios::app};

  // if (!file.is_open()) {
  // std::cerr << "Arquivo não pode ser criado" << std::endl;
  // return 1;
  // }

  // std::string date = get_current_date();

  // if (get_last_date() != date) {
  //   file << "# " << date << std::endl << std::endl;
  // }

  Message message;

  message.content = messageContent;

  // messages[messages_size] = message;
  // messages_size = messages_size + 1;

  // return 0;
}

void Diary::write() {
  // std::cout << messages_size << " " << messages[0].content;
}
