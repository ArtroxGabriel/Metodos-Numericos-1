#include "secante.hpp"
#include <cstdio>
#include <functional>

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
