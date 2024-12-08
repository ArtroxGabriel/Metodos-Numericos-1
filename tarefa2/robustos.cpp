#include "robustos.hpp"
#include <iostream>

double Robusto::getX(double a, double b, double epsilon,
                     std::function<double(double)> func) {
  this->epsilon = epsilon;
  this->A = a;
  this->B = b;
  this->Fa = func(a);
  this->Fb = func(b);

  if (Fa * Fb > 0) {
    std::cout << "ERROR: Funcao nao muda de sinal entre a e b " << std::endl;
    return 0;
  }
  printf("%-5s|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|\n", "I", "a", "fa",
         "b", "fb", "x", "fx", "intervX");

  int iteracoes = 0;

  X = this->determinante();
  Fx = func(X);

  this->printBench(iteracoes);

  while (this->criterioDeParada()) {
    if (Fa * Fx < 0) {
      B = X;
      Fb = Fx;
    } else {
      A = X;
      Fa = Fx;
    }
    X = this->determinante();
    Fx = func(X);
    ++iteracoes;

    this->printBench(iteracoes);
  };

  return X;
}
