#include "bisseccao.hpp"
#include <cstdio>

double Bisseccao::determinante() { return (A + B) / 2; }
bool Bisseccao::criterioDeParada() { return (B - A) > epsilon; }

void Bisseccao::printBench(int i) {
  printf("%-5d|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|\n", i,
         A, Fa, B, Fb, X, Fx, std::abs(B - A));
}
