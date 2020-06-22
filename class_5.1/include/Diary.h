#ifndef DIARY_H
#define DIARY_H

#include "DateTime.h"
#include "Message.h"

struct Diary {
  Message *messages;

  void get_bd_messages();
  void add_message(const Message message);
  void list_messages();

  DateTime get_last_date();

  int print_use_case();
}

#endif
