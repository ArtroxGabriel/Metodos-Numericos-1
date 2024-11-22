#include "robustos.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

  auto bisseccao = Bisseccao();
  auto posFalsa = FalsaPosicao();
  double a, b, epsilon = 0.001;
  cout << "Digite o valor A: " << endl;
  cin >> a;
  cout << "Digite o valor B: " << endl;
  cin >> b;
  auto func = [](double x) { return pow(x, 3) - 9 * x + 3; };
  double root;

  printf("Metodo da Bissecao:\nCalculando o valor da raiz da funcao %s para o "
         "intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "x³-9x+3", a, b, epsilon);
  root = bisseccao.getX(a, b, epsilon, func);
  printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é: %f\n\n",
         root, func(root));

  epsilon = 5e-4;

  printf("Metodo da Falsa Posicao:\nCalculando o valor da raiz da funcao %s "
         "para o intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "x³-9x+3", a, b, epsilon);
  root = posFalsa.getX(a, b, epsilon, func);
  printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é: %f\n\n",
         root, func(root));

  return 0;
}
