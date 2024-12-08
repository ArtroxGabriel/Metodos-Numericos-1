#ifndef SECANTE_HPP
#define SECANTE_HPP

#include "rapidos.hpp"
#include <functional>

class Secante : public Rapido {
public:
  Secante(double, double, double, double, std::function<double(double)>);

protected:
  double previous_func;

  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
  void printBench(int) override;
};
#endif // !SECANTE_HPP
