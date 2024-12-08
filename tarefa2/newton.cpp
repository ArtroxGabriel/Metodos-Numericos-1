#include "newton.hpp"
#include <cstdio>
#include <functional>

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
