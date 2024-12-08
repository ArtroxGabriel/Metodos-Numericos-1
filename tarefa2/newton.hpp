#ifndef NEWTON_HPP
#define NEWTON_HPP

#include "rapidos.hpp"
#include <functional>
#include <vector>

class NewtonRaphson : public Rapido {
public:
  NewtonRaphson(double, double, double, double, std::function<double(double)>,
                std::function<double(double)>);

protected:
  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
  void printBench(int) override;
};

class NewtonPolynomial : public Rapido {
public:
  NewtonPolynomial(double, double, double, double, std::vector<double>);

protected:
  std::vector<double> coefficient;

  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
  void printBench(int) override;
  double itera(int);
};

#endif // !NEWTON_HPP
