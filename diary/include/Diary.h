#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <fstream>
#include <string>
#include <vector>

struct Diary {
  Diary(const std::string &filename);

  std::string filename;
  std::vector<Message> messages;

  void load();

  void add(const std::string &messageContent);
  void add(const Message &message);
  void write();

  std::vector<Message *> search(std::string search_value);

  std::string get_last_date();
};

#endif
