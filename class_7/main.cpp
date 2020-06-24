#include <iostream>
#include <string>

struct Message {
  std::string content;
};

// DON'T EXECUTE IT IF YOU HAVE A FRAGILE HEART

int main(int argc, char const *argv[]) {
  char *fuck_memory = new char[5368709120];
  delete[] fuck_memory;

  int *a = new int;
  std::cout << a << std::endl;
  delete a;

  Message *m = new Message;
  Message *messages = new Message[1000];

  delete m;
  delete[] messages;

  return 0;
}
