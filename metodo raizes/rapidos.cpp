#include "rapidos.hpp"
#include <cstdio>

double Rapido::getX(double X0, double epsilon1, double epsilon2,
                    std::function<double(double)> func,
                    std::function<double(double)> aux_func) {
  this->func = func;
  this->aux_func = aux_func;
  this->epsilon1 = epsilon1;
  this->epsilon2 = epsilon2;

  if (std::abs(func(X0)) < epsilon1) {
    return X0;
  }

  this->previous_x = X0;                     // X0 = X1
  this->curr_x = this->funcao_de_iteracao(); // X1 = qsi(X0)
  this->curr_func = func(this->curr_x);      // func(X1)

  printf("%-5s|%-15s|%-15s|%-15s|%-15s|\n", "K", "x1", "x0", "x1 - x0",
         "f(x1)");

  int k = 1;
  this->printBench(k);

  while (this->criterio_de_parada()) {
    this->previous_x = this->curr_x;           // X0 = X1
    this->curr_x = this->funcao_de_iteracao(); // X1 = qsi(X1)
    this->curr_func = func(this->curr_x);      // func(x1)

    ++k;
    this->printBench(k);
  }

  return this->curr_x;
};

void Rapido::printBench(int k) {
  printf("%-5d|%-15.6e|%-15.6e|%-15.6e|%-15.6e|\n", k, curr_x, previous_x,
         curr_x - previous_x, curr_func);
}

bool PontoFixo::criterio_de_parada() {
  return not(std::abs(curr_func) < epsilon1 ||
             std::abs(curr_x - previous_x) < epsilon2);
}
double PontoFixo::funcao_de_iteracao() { return aux_func(previous_x); }

double NewtonRaphson::funcao_de_iteracao() {
  return previous_x - (func(previous_x) / aux_func(previous_x));
}

bool NewtonRaphson::criterio_de_parada() {
  return not(std::abs(curr_func) < epsilon1 ||
             std::abs(curr_x - previous_x) < epsilon2);
}
