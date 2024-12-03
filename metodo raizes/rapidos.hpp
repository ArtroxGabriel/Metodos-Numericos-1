#ifndef RAPIDOS_HPP
#define RAPIDOS_HPP

#include <functional>
#include <math.h>

class Rapido {
public:
  double previous_x, curr_x, curr_func, epsilon1, epsilon2;

  std::function<double(double)> func, aux_func;

  double getX(double, double, double, std::function<double(double)>,
              std::function<double(double)>);

  void printBench(int);

private:
  virtual double funcao_de_iteracao() = 0;
  virtual bool criterio_de_parada() = 0;
};

class PontoFixo : public Rapido {
private:
  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
};

class NewtonRaphson : public Rapido {
private:
  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
};

// PREGUIÇA DE FAZER ESSE
class Secante : public Rapido {
private:
  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
};
#endif // !RAPIDOS_HPP
