#ifndef AGENCY_H
#define AGENCY_H

#include <string>

class Agency {
public:
  std::string name;
  int number;

  Agency(std::string name, int number);
  Agency();
};

#endif
