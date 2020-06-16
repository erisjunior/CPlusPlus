#include <iostream>

int main(int argc, char *argv[])
{
  int number1 = 0;
  int number2 = 0;

  std::cout << "Informe o primeiro número: ";
  std::cin >> number1;

  std::cout << "Informe o segundo número: ";
  std::cin >> number2;

  int sum = number1 + number2;

  std::cout << "A soma dos números é " << sum << std::endl;

  return 0;
}