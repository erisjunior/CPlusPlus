#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Any {
  int value;
  std::string name;
};

int main(int argc, char const *argv[]) {
  std::vector<int> items;

  items.push_back(40);
  items.push_back(30);
  items.push_back(20);
  items.push_back(10);

  std::cout << items[0] << std::endl;

  for (size_t i = 0; i < items.size(); i++) {
    std::cout << items[i] << std::endl;
  }

  std::cout << items.capacity() << std::endl;

  std::vector<Any> items2;
  {
    Any a1;
    Any a2;

    a1.value = 10;
    a2.value = 20;

    items2.push_back(a1);
    items2.push_back(a2);
  }
  items2[0].name = "sei lá";
  std::cout << items2[0].value << std::endl;

  std::unordered_map<std::string, int> dic;

  dic["caba_um"] = 10;
  dic["caba_dois"] = 8;

  for (std::unordered_map<std::string, int>::iterator it = dic.begin();
       it != dic.end(); it++) {
    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
  }

  for (auto it = dic.begin(); it != dic.end(); it++) {
    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
  }

  std::sort(items.begin(), items.end());
  // std::sort(items.begin(), items.begin()+2);
  for (int i : items) {
    std::cout << i << std::endl;
  }

  for (auto p : dic) {
    std::cout << p.first << std::endl;
  }

  return 0;
}
