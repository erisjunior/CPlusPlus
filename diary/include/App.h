#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App {
  App(const std::string &filename);

  Diary diary;

  int run(int argc, char *argv[]);
  int show_usage(const std::string prog_name);

  int add();
  int add(const std::string message);

  int list();

  int search(const std::string searc_value);
};

#endif
