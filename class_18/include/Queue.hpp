#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template <class C> class Queue {
public:
  std::vector<C> clients;

  Queue() {}

  C first() {
    if (clients.size() > 0) {
      return clients[0];
    }
  }

  C last() { return clients[clients.size() - 1]; }

  void add(C client) { clients.push_back(client); }

  void remove(int index) {
    if (clients[index]) {
      clients.erase(index);
    }
  }
};

#endif
