#ifndef ROBUSTO_HPP
#define ROBUSTO_HPP

#include <cmath>
#include <functional>

class Robusto {
public:
  double A, Fa, B, Fb, epsilon, X, Fx;

  double getX(double, double, double, std::function<double(double)> func);

  void printBench(int);

private:
  virtual double determinante() = 0;
  virtual bool criterioDeParada() = 0;
};

class Bisseccao : public Robusto {
private:
  double determinante() override;
  bool criterioDeParada() override;
};

class FalsaPosicao : public Robusto {
private:
  double determinante() override;
  bool criterioDeParada() override;
};

#endif
