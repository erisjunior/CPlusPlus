#ifndef MESSAGE_H
#define MESSAGE_H

#include "DateTime.h"
#include <string>

struct Message {
  DateTime date_time;
  std::string content;
};

#endif
