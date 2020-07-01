#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Message.h"

Diary::Diary(const std::string &filename) : filename(filename) { load(); }

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

void Diary::add(const Message &message) { messages.push_back(message); }

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

  for (auto message : messages) {
    std::string date = message.date.to_string();

    if (last_date != date) {
      file << "# " << date << std::endl;
      last_date = date;
    }

    file << "- " << message.time.to_string() << " | " << message.content
         << std::endl;
  }

  file.close();
}

std::vector<Message *> Diary::search(const std::string search_value) {
  std::vector<Message *> messages_vector;

  for (auto message : messages) {
    if (message.content.find(search_value) != std::string::npos) {
      messages_vector.push_back(&message);
    }
  }

  return messages_vector;
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
