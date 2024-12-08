#ifndef RAPIDOS_HPP
#define RAPIDOS_HPP

#include <functional>
#include <math.h>

class Rapido {
public:
  double getX();

protected:
  double previous_x, curr_x, curr_func, epsilon1, epsilon2;
  std::function<double(double)> func, aux_func;

  virtual double funcao_de_iteracao() = 0;
  virtual bool criterio_de_parada() = 0;
  virtual void printBench(int) = 0;
};

#endif // !RAPIDOS_HPP
