#ifndef gabrigas_math_hpp
#define gabrigas_math_hpp

/**
 * @brief calcula a potenciação dado uma base e um expoente
 *
 * @param base O numero da base
 * @param exp O numero do expoente
 * @return Resultado de B elevado a exp
 */
int pow(int base, int exp);

/**
 * @brief Calcula o numero de bits para representar um numero
 *
 * @param num O Numero para se calcular a quantidade de bits
 * @return O numero de bits para representar o numero
 */
int bit_size(int num);

/**
 * @brief Converte um numero decimal inteiro para binary_to_decimal_optimized
 *
 * A representação binaria adotada por essa implementação foi atraves de numeros
 * inteiros
 *
 * @param decimal O numero a ser convertido
 * @return A representação binaria do numero
 */
int decimal_to_binary(int decimal);

/**
 * @brief Converte u
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
