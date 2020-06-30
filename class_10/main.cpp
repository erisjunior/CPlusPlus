#include <iostream>

struct MyStruct {
  int variable;
  void funcao() {}
  int *ptn;
};

void por_copia(int a) { a = 30; }

void por_referencia(int &a) { a = 30; }

void por_ponteiro(int *a) { *a = 40; }

int main(int argc, char const *argv[]) {
  int a = 10;
  int *b = &a;

  std::cout << "Endereço: " << b << std::endl;
  std::cout << "Valor:    " << *b << std::endl;

  *b = 20;
  std::cout << a << std::endl;

  char *c = new char[10];

  int *d = nullptr;

  int joao = 10;
  int &joaozinho = joao;

  joaozinho = 20;

  std::cout << joao << std::endl;

  int n = 10;
  int &n2 = n;
  int *n3 = &n;

  std::cout << &n << std::endl;
  std::cout << &n2 << std::endl;
  std::cout << n3 << std::endl;

  por_copia(n);
  std::cout << n << std::endl;
  por_referencia(n);
  std::cout << n << std::endl;
  por_ponteiro(&n);
  std::cout << n << std::endl;

  int arr[] = {10, 20, 30, 40};
  std::cout << *arr << std::endl;

  std::cout << *(arr + 1) << std::endl;

  MyStruct s;
  MyStruct *p = &s;

  s.funcao();
  s.variable = 10;
  p->funcao();
  p->variable = 20;

  std::cout << s.variable << std::endl;

  s.ptn = &argc;

  int k = 10;
  int l = 20;
  int *m = &a;
  *m = 50;
  m = &l;
  *m = 100;

  std::cout << k << std::endl;
  std::cout << l << std::endl;

  return 0;
}
