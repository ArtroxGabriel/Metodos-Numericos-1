#include "rapidos.hpp"

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
