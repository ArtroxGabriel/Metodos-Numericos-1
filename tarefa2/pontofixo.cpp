#include "pontofixo.hpp"
#include <cstdio>

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
