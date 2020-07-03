#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <iostream>
#include <sstream>
#include <string>

struct App {
  App(const std::string &filename, const std::string &format);

  std::string prog_name;

  Diary diary;
  std::string format;

  int run(int argc, char *argv[]);

  int show_usage();

  int interactive_interface();
  void show_interactive_usage();

  int add();
  int add(const std::string message);

  int list(const std::string extra_format);
  void print_formated_message(Message &message, const std::string format);

  int search(const std::string search_value);
};

#endif
