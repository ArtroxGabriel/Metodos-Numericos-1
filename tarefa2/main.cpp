#include "bisseccao.hpp"
#include "falsaposicao.hpp"
#include "newton.hpp"
#include "pontofixo.hpp"
#include "secante.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

void questao1() {
  auto bisseccao = Bisseccao();
  auto posFalsa = FalsaPosicao();

  double a = 0, b = 1, epsilon = 1e-4;

  auto func = [](double x) { return -(exp(x) / 2) + 2 * cos(x); };

  double root;

  printf("Metodo da Bissecao:\nCalculando o valor da raiz da funcao %s para o"
         "intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "f(x) = -(e^x / 2) + 2 cos(x)\n", a, b, epsilon);
  root = bisseccao.getX(a, b, epsilon, func);

  epsilon = 5e-4;

  printf("Metodo da Falsa Posicao:\nCalculando o valor da raiz da funcao %s "
         "para o intervalo [%.2f,%.2f] com "
         "epsilon = %f\n\n",
         "f(x) = -(e^x / 2) + 2 cos(x)\n", a, b, epsilon);
  root = posFalsa.getX(a, b, epsilon, func);
}

void questao2() {
  double a, b, epsilon1, epsilon2;
  a = 0;
  b = 1;
  epsilon1 = 1e-4;
  epsilon2 = epsilon1;
  auto func = [](double x) { return -(exp(x) / 2) + 2 * cos(x); };

  auto deriv = [](double x) { return -(exp(x) / 2) - 2 * sin(x); };

  printf(
      "Metodo do Newton-Raphson:\nCalculando o valor da raiz da funcao %s para "
      "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
      "f(x) = -(e^x / 2) + 2 cos(x)", (a + b) / 2, epsilon1, epsilon2);
  auto newtonRaphson = NewtonRaphson(a, b, epsilon1, epsilon2, func, deriv);
  newtonRaphson.getX();

  a = 0.5;
  printf("Metodo do Secante:\nCalculando o valor da raiz da funcao %s para "
         "o x0: %.2f & x1: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
         "f(x) = -(e^x / 2) + 2 cos(x)", a, b, epsilon1, epsilon2);
  auto secante = Secante(a, b, epsilon1, epsilon2, func);
  secante.getX();
}

void questao3() {
  double a, b, epsilon1, epsilon2;
  a = 0;
  b = 1;
  epsilon1 = 1e-4;
  epsilon2 = epsilon1;

  auto func = [](double x) { return pow(x, 3) - 9 * x + 3; };
  auto psi = [](double x) { return pow(x, 3.f) / 9.f + 1.f / 3.f; };
  printf("Metodo do Ponto Fixo:\nCalculando o valor da raiz da funcao %s para "
         "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
         "a³-9a+3", (a + b) / 2, epsilon1, epsilon2);
  auto pontoFixo = PontoFixo(a, b, epsilon1, epsilon2, func, psi);
  pontoFixo.getX();
}

void questao4() {
  double a, b, epsilon1, epsilon2;
  a = 2;
  b = 3;
  epsilon1 = 1e-5;
  epsilon2 = epsilon1;

  printf(
      "Metodo do Newton-Raphson:\nCalculando o valor da raiz da funcao %s para "
      "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
      "f(x) = x - xln(x)", (a + b) / 2, epsilon1, epsilon2);

  auto func = [](double x) { return x - x * log(x); };
  auto deriv = [](double x) { return -log(x); };
  auto newtonRaphson = NewtonRaphson(a, b, epsilon1, epsilon2, func, deriv);
  newtonRaphson.getX();

  printf("Metodo do Ponto Fixo:\nCalculando o valor da raiz da funcao %s para "
         "o x0: %.2f com epsilon₁: %e & epsilon₂: %e\n\n",
         "f(x) = x - xln(x)", (a + b) / 2, epsilon1, epsilon2);
  auto psi = [](double x) { return x / log(x); };
  auto pontoFixo = PontoFixo(a, b, epsilon1, epsilon2, func, psi);
  pontoFixo.getX();
}

void run_rapidos() {}

int main() {
  printf(">>> Questão 1: <<<\n");
  questao1();

  printf("\n>>> Questão 2: <<<\n");
  questao2();

  printf("\n>>> Questão 3: <<<\n");
  questao3();

  printf("\n>>> Questao 4 <<<\n");
  questao4();
  return EXIT_SUCCESS;
}
