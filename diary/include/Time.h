#ifndef TIME_H
#define TIME_H

#include <string>

struct Time {
  Time();

  unsigned hours;
  unsigned minutes;
  unsigned seconds;

  void set_from_string(const std::string &time);
  std::string to_string();
};

#endif
