#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary {
  Diary(const std::string &filename);

  std::string filename;
  Message *messages;
  size_t messages_size;
  size_t messages_capacity;

  void load();

  void add(const std::string &messageContent);
  void write();

  // DateTime get_last_date();
};

#endif
