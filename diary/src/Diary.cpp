#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Message.h"

#include <fstream>
#include <iostream>

Diary::Diary(const std::string &filename)
    : filename(filename), messages(nullptr), messages_size(0),
      messages_capacity(10) {
  messages = new Message[messages_capacity];
}

Diary::~Diary() { delete[] messages; }

void Diary::add(const std::string &messageContent) {
  if (messages_capacity <= messages_size) {
    std::cout << "Capacidade máxima do diário atingida" << std::endl;
    return;
  }

  Message message;
  message.content = messageContent;
  message.date.set_from_string(get_current_date());
  message.time.set_from_string(get_current_time());

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
