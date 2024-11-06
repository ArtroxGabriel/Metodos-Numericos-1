#include "gabrigas_math.hpp"
#include <iostream>

int main() {
  std::cout << decimal_to_binary(27) << std::endl;
  std::cout << binary_to_decimal(0b11011) << std::endl;
  std::cout << binary_to_decimal_optimized(0b11011) << std::endl;

  return 0;
}
