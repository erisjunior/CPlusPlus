#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <string>

struct Date {
  Date();

  unsigned year;
  unsigned month;
  unsigned day;

  void set_from_string(const std::string &date);
  std::string to_string();
};

#endif
