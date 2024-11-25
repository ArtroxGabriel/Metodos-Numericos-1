#include "gabrigas_math.hpp"
#include <iostream>
#include <string>

using namespace std;

void menu();

int main() {
  menu();

  return 0;
}

void menu() {
  int choice;
  int dec;
  string bin;
  while (true) {
    cout << "\tEscolha a função a se testar" << endl;
    cout << "\t1 - Conversão Decimal para Binario" << endl;
    cout << "\t2 - Conversão Binario para Decimal" << endl;
    cout << "\t3 - Conversão Binario para Decimal Otimizado" << endl;
    cout << "\t0 - sair" << endl;
    cin >> choice;

    switch (choice) {
    case 0:
      return;
    case 1:
      cout << "Digite o numero decimal para conversão" << endl;
      cin >> dec;

      cout << "\t Numero decimal " << dec << " em binario é "
           << decimal_to_binary(dec) << endl;
      break;
    case 2:
      cout << "Digite o numero binario para conversão" << endl;
      cin >> bin;

      cout << "\t Numero binario " << bin << " em dec é "
           << binary_to_decimal(bin) << endl;
      break;
    case 3:
      cout << "Digite o numero binario para conversão" << endl;
      cin >> bin;

      cout << "\t Numero binario " << bin << " em dec é "
           << binary_to_decimal_optimized(bin) << endl;
      break;
    default:
      cout << "Não é uma opção" << endl;
    }
    cout << endl;
  }
}
