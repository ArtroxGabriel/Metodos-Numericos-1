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

void Robusto::printBench(int i) {
  printf("%-5d|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|\n", i,
         A, Fa, B, Fb, X, Fx, std::abs(B - A));
}

double Bisseccao::determinante() { return (A + B) / 2; }
bool Bisseccao::criterioDeParada() { return (B - A) > epsilon; }

double FalsaPosicao::determinante() { return ((A * Fb - B * Fa) / (Fb - Fa)); }
bool FalsaPosicao::criterioDeParada() { return std::abs(Fx) > epsilon; }
