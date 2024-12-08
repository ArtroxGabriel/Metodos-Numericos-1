#ifndef PONTOFIXO_HPP
#define PONTOFIXO_HPP

#include "rapidos.hpp"

class PontoFixo : public Rapido {
public:
  PontoFixo(double, double, double, double, std::function<double(double)>,
            std::function<double(double)>);

protected:
  double funcao_de_iteracao() override;
  bool criterio_de_parada() override;
  void printBench(int) override;
};

#endif // !PONTOFIXO_HPP
