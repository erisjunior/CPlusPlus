#include <iostream>
#include <string.h>

void printSuccess()
{
  std::cout << "Mensagem adicionada" << std::endl;
}

void printUseCase()
{
  std::cout << "Uso: ./prog add <mensagem>" << std::endl;
}

int main(int argc, char const *argv[])
{
  std::string message;

  if (argc == 1)
  {
    printUseCase();
    return -1;
  }

  if (!strcmp(argv[1], "add"))
  {
    if (argc > 2)
    {
      message = argv[2];
    }
    else
    {
      std::cin >> message;
    }

    printSuccess();
  }
  else
  {
    printUseCase();
    return -1;
  }

  return 0;
}
