#ifndef gabrigas_math_hpp
#define gabrigas_math_hpp

#include <string>

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
std::string decimal_to_binary(int decimal);

/**
 * @brief Converte um numero binario para decimal
 *
 * @param bin O numero binario a ser convertido, no formato de string
 * @return O numero decimal representado pelo binario
 */
int binary_to_decimal(std::string bin);

/**
 * @brief Converte um numero binario para decimal de forma otimizada
 *
 * @param bin O numero binario a ser convertido, no formato de string
 * @return O numero decimal representado pelo binario
 */
int binary_to_decimal_optimized(std::string bin);

#endif // !gabrigas_math_hpp
