#include "../include/App.h"

std::pair<std::string, std::string> get_config_file() {
  std::pair<std::string, std::string> pair;
  pair.first = "diary.md";
  pair.second = "%d %t: %m";

  std::ifstream file;
  file.open("diary.config");

  if (file.is_open()) {
    std::string line;

    while (!file.eof()) {
      std::getline(file, line);
      if (line.size() == 0) {
        continue;
      }
      if (line.find("path=") != std::string::npos) {
        pair.first = line.substr(5);
      }
      if (line.find("default_format=") != std::string::npos) {
        pair.second = line.substr(15);
      }
    }
    file.close();
    return pair;
  }

  file.close();

  std::ofstream output_file{"diary.config"};

  if (!output_file.is_open()) {
    return pair;
  }

  output_file << "path=" << pair.first << std::endl;
  output_file << "default_format=" << pair.second << std::endl;

  output_file.close();

  return pair;
}

int main(int argc, char **argv) {
  auto config = get_config_file();
  App app(config.first, config.second);

  return app.run(argc, argv);
}
