#include "gabrigas_math.hpp"

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

int decimal_to_binary(int decimal) {
  int binary = 0;
  int count = 1;

  while (decimal) {
    int rest = decimal % 2;
    decimal /= 2;

    binary += rest * count;
    count *= 10;
  }

  return binary;
}

int binary_to_decimal(int bin) {
  int decimal = 0;
  int count = 0;

  while (bin) {
    int rest = bin & 1;
    bin >>= 1;

    decimal += rest * pow(2, count);
    count++;
  }

  return decimal;
}

int binary_to_decimal_optimized(int bin) {
  int decimal = 0;
  int size = bit_size(bin) - 1;
  while (size >= 0) {
    int leftmost = (bin >> size) & 1;
    size--;
    decimal = 2 * decimal + leftmost;
  }

  return decimal;
}
