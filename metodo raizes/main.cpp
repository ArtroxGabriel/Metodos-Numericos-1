#include "rapidos.hpp"
#include "robustos.hpp"
#include <iostream>

using namespace std;

void run_rapidos() {
  auto pontoFixo = PontoFixo();
  auto newtonRaphson = NewtonRaphson();

  double a, b;
  cout << "Digite o valor A: " << endl;
  cin >> a;
  cout << "Digite o valor B: " << endl;
  cin >> b;

  double x0 = (b + a) / 2;
  cout << "x0: " << x0 << endl;
  double epsilon1 = 5e-4, epsilon2 = epsilon1;
  double root;

  auto func = [](double x) { return pow(x, 3) - 9 * x + 3; };
  // auto qsi = [](double x) { return pow(x, 3.f) / 9.f + 1.f / 3.f; };
  //
  // root = pontoFixo.getX(x0, epsilon1, epsilon2, func, qsi);
  // printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é:% f\n\n
  // ",
  //        root, func(root));

  auto deriv = [](double x) { return 3 * pow(x, 2) - 9; };
  root = newtonRaphson.getX(x0, epsilon1, epsilon2, func, deriv);
  printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é:% f\n\n ",
         root, func(root));
}

void run_Robustos() {
  auto bisseccao = Bisseccao();
  auto posFalsa = FalsaPosicao();
  double a, b, epsilon = 0.001;
  cout << "Digite o valor A: " << endl;
  cin >> a;
  cout << "Digite o valor B: " << endl;
  cin >> b;
  auto func = [](double x) { return pow(x, 3) - 9 * x + 3; };
  double root;

  printf("Metodo da Bissecao:\nCalculando o valor da raiz da funcao %s para o"
         "intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "x³-9x+3", a, b, epsilon);
  root = bisseccao.getX(a, b, epsilon, func);
  printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é:% f\n\n",
         root, func(root));

  epsilon = 5e-4;

  printf("Metodo da Falsa Posicao:\nCalculando o valor da raiz da funcao %s "
         "para o intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "x³-9x+3", a, b, epsilon);
  root = posFalsa.getX(a, b, epsilon, func);
  printf("\nA raiz encontrada é %f, aplicando a funcao o resultado é:% f\n\n",
         root, func(root));
}

int main() {
  run_rapidos();
  return 0;
}
