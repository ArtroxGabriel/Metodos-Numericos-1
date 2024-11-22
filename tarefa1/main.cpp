#include "../metodo raizes/robustos.hpp"
#include <iostream>
// #include "gabrigas_math.hpp"
// #include <string>

using namespace std;

void menu();

int main() {
  auto biseccao = Biseccao();
  auto posFalsa = PosFalsa();
  double a = 0, b = 1, epsilon = 0.001f;
  auto func = [](double x) { return std::pow(x, 3) - 9 * x + 3; };

  biseccao.getX(a, b, epsilon, func);
  cout << endl << endl << endl;
  epsilon = 5e-4;
  posFalsa.getX(a, b, epsilon, func);
  return 0;
}

// void menu() {
//   int choice;
//   int dec;
//   string bin;
//   while (true) {
//     cout << "\tEscolha a função a se testar" << endl;
//     cout << "\t1 - Conversão Decimal para Binario" << endl;
//     cout << "\t2 - Conversão Binario para Decimal" << endl;
//     cout << "\t3 - Conversão Binario para Decimal Otimizado" << endl;
//     cout << "\t0 - sair" << endl;
//     cin >> choice;
//
//     switch (choice) {
//     case 0:
//       return;
//     case 1:
//       cout << "Digite o numero decimal para conversão" << endl;
//       cin >> dec;
//
//       cout << decimal_to_binary(dec) << endl;
//       break;
//     case 2:
//       cout << "Digite o numero binario para conversão" << endl;
//       cin >> bin;
//
//       cout << binary_to_decimal(bin /* stoi(bin, nullptr, 2) */) << endl;
//       break;
//     case 3:
//       cout << "Digite o numero binario para conversão" << endl;
//       cin >> bin;
//
//       cout << binary_to_decimal_optimized(bin) << endl;
//       break;
//     default:
//       cout << "Não é uma opção" << endl;
//     }
//     cout << endl;
//   }
// }
