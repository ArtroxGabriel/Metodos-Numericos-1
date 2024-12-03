#ifndef RAPIDOS_HPP
#define RAPIDOS_HPP

#include <functional>
#include <math.h>

class Rapido {
public:
  double previous_x, curr_x, curr_func, epsilon1, epsilon2;

  std::function<double(double)> qsi;

  double getX(double, double, double, std::function<double(double)>,
              std::function<double(double)>);

  void printBench(int);

private:
  virtual double determinante() = 0;
  virtual bool criterioDeParada() = 0;
};

class PontoFixo : public Rapido {
private:
  double determinante() override;
  bool criterioDeParada() override;
};

// class FalsaPosicao : public Robusto {
// private:
//   double determinante() override;
//   bool criterioDeParada() override;
// };
#endif // !RAPIDOS_HPP
