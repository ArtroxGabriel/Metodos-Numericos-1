#include "rapidos.hpp"
#include "robustos.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

void run_rapidos() {
  double a, b;
  cout << "Digite o valor A: " << endl;
  cin >> a;
  cout << "Digite o valor B: " << endl;
  cin >> b;

  double root;

  double epsilon1 = 5e-4, epsilon2 = epsilon1;
  auto func = [](double x) { return pow(x, 3) - 9 * x + 3; };
  auto psi = [](double x) { return pow(x, 3.f) / 9.f + 1.f / 3.f; };

  printf("Metodo do Ponto Fixo:\nCalculando o valor da raiz da funcao %s para "
         "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
         "x³-9x+3", (a + b) / 2, epsilon1, epsilon2);
  auto pontoFixo = PontoFixo(a, b, epsilon1, epsilon2, func, psi);
  root = pontoFixo.getX();
  printf("\nA raiz encontrada é %e, aplicando a funcao o resultado é: %f\n\n",
         root, func(root));

  auto deriv = [](double x) { return 3 * pow(x, 2) - 9; };
  epsilon1 = 1e-4, epsilon2 = epsilon1;
  printf(
      "Metodo do Newton-Raphson:\nCalculando o valor da raiz da funcao %s para "
      "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
      "x³-9x+3", (a + b) / 2, epsilon1, epsilon2);
  auto newtonRaphson = NewtonRaphson(a, b, epsilon1, epsilon2, func, deriv);
  root = newtonRaphson.getX();
  printf("\nA raiz encontrada é %e, aplicando a funcao o resultado é:% f\n\n",
         root, func(root));

  epsilon1 = 5e-4, epsilon2 = epsilon1;
  printf("Metodo do Secante:\nCalculando o valor da raiz da funcao %s para "
         "o x0: %.2f & x1: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
         "x³-9x+3", a, b, epsilon1, epsilon2);
  auto secante = Secante(a, b, epsilon1, epsilon2, func);
  root = secante.getX();
  printf("\nA raiz encontrada é %e, aplicando a funcao o resultado é:% f\n\n",
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
  return EXIT_SUCCESS;
}
