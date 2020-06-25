#include "../include/Time.h"

#include <sstream>

Time::Time() : hours(0), minutes(0), seconds(0) {}

void Time::set_from_string(const std::string &time) {
  std::stringstream stream(time);

  char discard;

  stream >> hours;
  stream >> discard;
  stream >> minutes;
  stream >> discard;
  stream >> seconds;
}
