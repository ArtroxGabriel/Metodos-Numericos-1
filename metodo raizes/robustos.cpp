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

  int iteracoes = 0;

  do {
    X = this->determinante();
    Fx = func(X);

    if (Fa * Fx < 0) {
      B = X;
      Fb = Fx;
    } else {
      A = X;
      Fa = Fx;
    }
    ++iteracoes;
  } while (this->criterioDeParada());

  std::cout << "Numero de iterações: " << iteracoes << std::endl;

  return X;
}

double Biseccao::determinante() { return std::abs(A + B) / 2; }
bool Biseccao::criterioDeParada() { return std::abs(A - B) > epsilon; }

double PosFalsa::determinante() { return ((A * Fb - B * Fa) / (Fb - Fa)); }
bool PosFalsa::criterioDeParada() { return std::abs(Fx) > epsilon; }
