#include "gabrigas_math.hpp"
#include <string>

int pow(int base, int exp) {
  if (exp == 0)
    return 1;

  int acc = base;

  if (exp < 0)
    while (exp < 0) {
      acc /= base;
      exp++;
    }
  else
    while (exp > 1) {
      acc *= base;
      exp--;
    }

  return acc;
}

int bit_size(int num) {
  int i = 1;

  while (num >>= 1)
    i++;

  return i;
}

std::string decimal_to_binary(int decimal) {
  int binary = 0;
  int count = 1;

  while (decimal) {
    int rest = decimal % 2;
    decimal /= 2;

    binary += rest * count;
    count *= 10;
  }

  return std::to_string(binary);
}

int binary_to_decimal(std::string bin) {
  int decimal = 0;
  int count = 0;

  while (!bin.empty()) {
    int rest = bin.back() - '0';
    bin.pop_back();

    decimal += rest * pow(2, count);
    count++;
  }

  return decimal;
}

int binary_to_decimal_optimized(std::string bin) {
  int decimal = 0;

  auto size = static_cast<int>(bin.size());
  int idx = 0;

  while (idx < size) {
    int leftmost = bin[idx] - '0';
    decimal = 2 * decimal + leftmost;

    idx++;
  }

  return decimal;
}
