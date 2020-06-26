#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Message.h"

#include <fstream>

Diary::Diary(const std::string &filename)
    : filename(filename), messages(nullptr), messages_size(0),
      messages_capacity(10) {
  messages = new Message[messages_capacity];
}

Diary::~Diary() { delete[] messages; }

void Diary::add(const std::string &messageContent) {
  if (messages_capacity <= messages_size) {
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

std::string Diary::get_last_date() {
  std::ifstream input_file;
  input_file.open(filename);

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
