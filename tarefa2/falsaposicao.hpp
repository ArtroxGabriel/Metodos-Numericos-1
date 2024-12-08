#ifndef FALSAPOSICAO_HPP
#define FALSAPOSICAO_HPP

#include "robustos.hpp"

class FalsaPosicao : public Robusto {
private:
  double determinante() override;
  bool criterioDeParada() override;
  void printBench(int) override;
};

#endif
