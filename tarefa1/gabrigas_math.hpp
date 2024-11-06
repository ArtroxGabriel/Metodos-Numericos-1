#ifndef gabrigas_math_hpp
#define gabrigas_math_hpp

/**
 * @brief Calculates the power of a base raised to an exponent.
 *
 * @param base The base number.
 * @param exp The exponent to raise the base to.
 * @return The result of base raised to the power of exp.
 */
int pow(int base, int exp);

/**
 * @brief Calculates the number of bits required to represent a number.
 *
 * @param num The number to calculate the bit size for.
 * @return The number of bits required to represent the number.
 */
int bit_size(int num);

/**
 * @brief Converts a decimal number to its binary representation.
 *
 * @param decimal The decimal number to convert.
 * @return The binary representation of the decimal number. in format 0bXXXXX
 */
int decimal_to_binary(int decimal);

/**
 * @brief Converts a binary number to its decimal representation.
 *
 * @param bin The binary number to convert.
 * @return The decimal representation of the binary number.
 */
int binary_to_decimal(int bin);

/**
 * @brief Optimized conversion of a binary number to its decimal representation.
 *
 * @param bin The binary number to convert.
 * @return The decimal representation of the binary number.
 */
int binary_to_decimal_optimized(int bin);
#endif // !gabrigas_math_hpp
