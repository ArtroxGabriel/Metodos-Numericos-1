#ifndef BISSECCAO_HPP
#define BISSECCAO_HPP

#include "robustos.hpp"

class Bisseccao : public Robusto {
private:
  double determinante() override;
  bool criterioDeParada() override;
  void printBench(int) override;
};

#endif
