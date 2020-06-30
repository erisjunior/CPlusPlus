#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Message.h"

#include <fstream>
#include <string>

Diary::Diary(const std::string &filename)
    : filename(filename), messages(nullptr), messages_size(0),
      messages_capacity(10) {
  messages = new Message[messages_capacity];

  load();
}

Diary::~Diary() { delete[] messages; }

void Diary::load() {
  std::ifstream file;
  file.open(filename);

  if (!file.is_open()) {
    return;
  }

  std::string line;
  Date date;

  while (!file.eof()) {
    std::getline(file, line);
    if (line.size() == 0) {
      continue;
    }

    if (line[0] == '#') {
      date.set_from_string(line.substr(2));
      continue;
    }

    Message message;
    message.date = date;
    message.time.set_from_string(line.substr(2));
    message.content = line.substr(13);
    add(message);
  }

  file.close();
}

void Diary::add(const Message &message) {
  if (messages_capacity <= messages_size) {
    messages_capacity *= 2;

    Message *new_messages = new Message[messages_capacity];

    for (size_t i = 0; i < messages_size; i++) {
      new_messages[i] = messages[i];
    }

    delete[] messages;
    messages = new_messages;
  }

  messages[messages_size] = message;
  messages_size += 1;
}

void Diary::add(const std::string &messageContent) {
  Message message;
  message.content = messageContent;
  message.date.set_from_string(get_current_date());
  message.time.set_from_string(get_current_time());

  add(message);
}

void Diary::write() {
  std::ofstream file{filename};

  if (!file.is_open()) {
    return;
  }

  std::string last_date = get_last_date();

  for (size_t i = 0; i < messages_size; i++) {
    std::string date = messages[i].date.to_string();

    if (last_date != date) {
      file << "# " << date << std::endl;
      last_date = date;
    }

    file << "- " << messages[i].time.to_string() << " | " << messages[i].content
         << std::endl;
  }

  file.close();
}

Message *Diary::search(const std::string search_value) {
  Message *ptr = messages;
  for (size_t i = 0; i < messages_size; i++) {
    if (ptr[0].content.find(search_value) != std::string::npos) {
      return ptr;
    }
    ptr++;
  }

  return nullptr;
}

std::string Diary::get_last_date() {
  std::ifstream file;
  file.open(filename);

  if (!file.is_open()) {
    return "";
  }

  std::string line;
  std::string date;

  while (!file.eof()) {
    std::getline(file, line);

    if (line[0] == '#') {
      date = line;
    }
  }

  file.close();
  if (date.size() == 0) {
    return "";
  }

  return date.substr(2);
}
