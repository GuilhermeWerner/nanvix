#pragma once

#include "types.h"

/**
 * @brief Gera bytecode para instruções do tipo R (registrador) do MIPS.
 *
 * @param mnem Identificador da instrução desejada (mnemônico).
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
int mips_typeR_bytecode(int mnem, int rd, int rs, int rt);

/**
 * @brief Gera bytecode para instruções do tipo J (jump) do MIPS.
 *
 * @param mnem Identificador da instrução desejada (mnemônico).
 * @param target Endereço de destinho da operação (label).
 */
int mips_typeJ_bytecode(int mnem, int target);

/**
 * @brief Gera bytecode para instruções do tipo I (imediato) do MIPS.
 *
 * @param mnem Identificador da instrução desejada (mnemônico).
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param imm Valor imediato.
 */
int mips_typeI_bytecode(int mnem, int rt, int rs, int imm);
