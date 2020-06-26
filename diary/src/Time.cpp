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

std::string Time::to_string() {
  std::stringstream stream;

  if (hours < 10) {
    stream << '0';
  }
  stream << hours << ':';
  if (minutes < 10) {
    stream << '0';
  }
  stream << minutes << ':';
  if (seconds < 10) {
    stream << '0';
  }
  stream << seconds;

  return stream.str();
}
