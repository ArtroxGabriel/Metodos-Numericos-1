#include "robustos.hpp"
#include <iostream>

using namespace std;

int main() {
  auto biseccao = Biseccao();
  auto posFalsa = PosFalsa();
  double a = 0, b = 1, epsilon = 0.001f;
  auto func = [](double x) { return std::pow(x, 3) - 9 * x + 3; };

  biseccao.getX(a, b, epsilon, func);
  cout << endl << endl << endl;
  epsilon = 5e-4;
  posFalsa.getX(a, b, epsilon, func);
}
