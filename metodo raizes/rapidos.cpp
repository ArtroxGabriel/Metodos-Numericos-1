#include "rapidos.hpp"
#include <cstdio>
#include <functional>

double Rapido::getX() {
  if (std::abs(curr_func) < epsilon1) {
    return curr_x;
  }

  int k = 1;
  do {
    curr_x = funcao_de_iteracao();
    curr_func = func(curr_x);

    printBench(k);
    ++k;
  } while (criterio_de_parada());

  return curr_x;
};

PontoFixo::PontoFixo(double a, double b, double epsilon1, double epsilon2,
                     std::function<double(double)> func,
                     std::function<double(double)> aux_func) {
  this->func = func;
  this->aux_func = aux_func;
  this->epsilon1 = epsilon1;
  this->epsilon2 = epsilon2;

  this->curr_x = (a + b) / 2;
  this->previous_x = curr_x;
  this->curr_func = func(curr_x);
};
void PontoFixo::printBench(int k) {
  if (k == 1) {
    printf("%-5s|%-15s|%-15s|%-15s|%-15s|\n", "K", "x1", "x0", "x1 - x0",
           "f(x1)");
  }
  printf("%-5d|%-15.6e|%-15.6e|%-15.6e|%-15.6e|\n", k, curr_x, previous_x,
         curr_x - previous_x, curr_func);
}
bool PontoFixo::criterio_de_parada() {
  return not(std::abs(curr_func) < epsilon1 ||
             std::abs(curr_x - previous_x) < epsilon2);
};
double PontoFixo::funcao_de_iteracao() {
  previous_x = curr_x;
  return aux_func(curr_x);
}

NewtonRaphson::NewtonRaphson(double a, double b, double epsilon1,
                             double epsilon2,
                             std::function<double(double)> func,
                             std::function<double(double)> aux_func) {
  this->func = func;
  this->aux_func = aux_func;
  this->epsilon1 = epsilon1;
  this->epsilon2 = epsilon2;

  this->curr_x = (a + b) / 2;
  this->previous_x = curr_x;
  this->curr_func = func(curr_x);
};
double NewtonRaphson::funcao_de_iteracao() {
  previous_x = curr_x;
  return curr_x - (curr_func / aux_func(curr_x));
}
bool NewtonRaphson::criterio_de_parada() {
  return not(std::abs(curr_func) < epsilon1 ||
             std::abs(curr_x - previous_x) < epsilon2);
};
void NewtonRaphson::printBench(int k) {
  if (k == 1) {
    printf("%-5s|%-15s|%-15s|\n", "K", "x", "f(x)");
    printf("%-5d|%-15.6e|%-15.6e|\n", 0, previous_x, func(previous_x));
  }
  printf("%-5d|%-15.6e|%-15.6e|\n", k, curr_x, curr_func);
};

Secante::Secante(double a, double b, double epsilon1, double epsilon2,
                 std::function<double(double)> func) {
  this->func = func;
  this->epsilon1 = epsilon1;
  this->epsilon2 = epsilon2;

  this->previous_x = a;
  this->curr_x = b;
  this->curr_func = func(curr_x);
  this->previous_func = func(previous_x);
};
double Secante::funcao_de_iteracao() {
  auto next_x = (previous_x * curr_func - curr_x * previous_func) /
                (curr_func - previous_func);

  previous_x = curr_x;
  previous_func = curr_func;

  return next_x;
}
bool Secante::criterio_de_parada() {
  return not(std::abs(curr_func) < epsilon1 ||
             std::abs(curr_x - previous_x) < epsilon2);
};
void Secante::printBench(int k) {
  if (k == 1) {
    printf("%-5s|%-15s|%-15s|\n", "K", "x", "f(x)");
  }
  printf("%-5d|%-15.6e|%-15.6e|\n", k, curr_x, curr_func);
};
