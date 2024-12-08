#include "falsaposicao.hpp"
#include <cstdio>

double FalsaPosicao::determinante() { return ((A * Fb - B * Fa) / (Fb - Fa)); }
bool FalsaPosicao::criterioDeParada() { return std::abs(Fx) > epsilon; }

void FalsaPosicao::printBench(int i) {
  printf("%-5d|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|%-15.6e|\n", i,
         A, Fa, B, Fb, X, Fx, std::abs(B - A));
}
