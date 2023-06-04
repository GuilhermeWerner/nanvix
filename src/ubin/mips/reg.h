#pragma once

#include "types.h"

enum MipsRegisters
{
	zero =  0,
	at   =  1,
	v0   =  2,
	v1   =  3,
	a0   =  4,
	a1   =  5,
	a2   =  6,
	a3   =  7,
	t0   =  8,
	t1   =  9,
	t2   = 10,
	t3   = 11,
	t4   = 12,
	t5   = 13,
	t6   = 14,
	t7   = 15,
	s0   = 16,
	s1   = 17,
	s2   = 18,
	s3   = 19,
	s4   = 20,
	s5   = 21,
	s6   = 22,
	s7   = 23,
	t8   = 24,
	t9   = 25,
	k0   = 26,
	k1   = 27,
	gp   = 28,
	sp   = 29,
	fp   = 30,
	ra   = 31,
};

/**
 * @brief Retorna o valor do registrador especificado.
 *
 * @param reg O registrador para o qual o valor é desejado.
 * @return O valor do registrador especificado.
 */
int mips_get_reg(int reg);

/**
 * @brief Define o valor do registrador especificado.
 *
 * @param reg O registrador a ser definido.
 * @param val O valor a ser atribuído ao registrador.
 * @return O valor atribuído ao registrador.
 */
void mips_set_reg(int reg, int val);

/**
 * @brief Define o valor (unsigned) do registrador especificado.
 *
 * @param reg O registrador a ser definido.
 * @param val O valor a ser atribuído ao registrador.
 * @return O valor atribuído ao registrador.
 */
void mips_set_reg_unsigned(int reg, unsigned int val);

/**
 * @brief Retorna o nome do registrador especificado.
 *
 * @param reg O registrador para o qual o nome é desejado.
 * @return O nome do registrador especificado.
 */
char *mips_get_reg_name(int reg);
