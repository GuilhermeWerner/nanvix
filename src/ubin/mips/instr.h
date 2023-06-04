#pragma once

#include "types.h"

/**
 * @brief Realiza a operação de adição entre os registradores rs e rt, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_add(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de adição entre os registradores rs e rt sem sinal, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_addu(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de adição entre o registrador rs e o valor imediato imm, e armazena o resultado no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param imm Valor imediato.
 */
void mips_addi(int rt, int rs, int imm);

/**
 * @brief Realiza a operação de adição entre o registrador rs e o valor imediato imm sem sinal, e armazena o resultado no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param imm Valor imediato.
 */
void mips_addiu(int rt, int rs, int imm);

/**
 * @brief Realiza a operação de and bit a bit entre os registradores rs e rt, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_and(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de and bita a bit entre o registrador rs e o valor imediato imm, e armazena o resultado no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param imm Valor imediato.
 */
void mips_andi(int rt, int rs, int imm);

/**
 * @brief Realiza a operação de branch se igual (beq) entre os registradores rs e rt, desviando para o endereço imediato imm se forem iguais.
 *
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 * @param imm Valor imediato representando o deslocamento do salto.
 */
void mips_beq(int rs, int rt, int imm);

/**
 * @brief Realiza a operação de branch se diferente (bne) entre os registradores rs e rt, desviando para o endereço imediato imm se forem diferentes.
 *
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 * @param imm Valor imediato representando o deslocamento do salto.
 */
void mips_bne(int rs, int rt, int imm);

/**
 * @brief Realiza a operação de pulo (jump) para o endereço de destino.
 *
 * @param target Endereço de destinho da operação (label).
 */
void mips_j(int target);

/**
 * @brief Realiza a operação de jump and link (jal) para o endereço de destino.
 *
 * @param target Endereço de destinho da operação (label).
 */
void mips_jal(int target);

/**
 * @brief Realiza a operação de jump register (jr) para o endereço contido no registrador rs.
 *
 * @param rs Registrador fonte contendo o endereço de destino.
 */
void mips_jr(int rs);

/**
 * @brief Carrega uma palavra (word) da memória na registrador rd.
 *
 * @param rt Registrador destino para armazenar a palavra carregada.
 * @param imm Deslocamento com sinal de 16 bits que é adicionado ao registrador rs para obter o endereço da memória.
 * @param rs Registrador fonte que contém o endereço base da memória.
 */
void mips_lw(int rd, int imm, int rs);

/**
 * @brief Realiza a operação or bit a bit entre os registradores rs e rt, e armazena o resultado 0 ou 1 no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_or(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de or bit a bit entre o registrador rs e o valor imediato imm, e armazena o resultado no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param imm Valor imediato.
 */
void mips_ori(int rt, int rs, int imm);

/**
 * @brief Realiza a operação de o menor entre os registradores rs e rt, e armazena o resultado 0 ou 1 no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_slt(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de o menor entre os registradores rs e rt sem sinal, e armazena o resultado 0 ou 1 no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_sltu(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de o menor entre o registrador rs e o valor imediato shamt, e armazena o resultado 0 ou 1 no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param shamt Valor imediato.
 */
void mips_slti(int rt, int rs, int shamt);

/**
 * @brief Realiza a operação de o menor entre o registradores rs e o imediato shamt sem sinal, e armazena o resultado no registrador rt.
 *
 * @param rt  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param shamt Valor imediato.
 */
void mips_sltiu(int rt, int rs, int shamt);

/**
 * @brief Realiza a operação de deslocamento à esquerda lógica, e armazena o resultado no registrador rt.
 *
 * @param rd  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param shamt Valor imediato.
 */
void mips_sll(int rd, int rs, int shamt);

/**
 * @brief Realiza a operação de deslocamento à direita lógica, e armazena o resultado no registrador rt.
 *
 * @param rd  Registrador de destino da operação.
 * @param rs  Registrador de origem da operação.
 * @param shamt Valor imediato.
 */
void mips_srl(int rd, int rs, int shamt);

/**
 * @brief Armazena uma palavra (word) do registrador rd na memória.
 *
 * @param rt Registrador fonte que contém a palavra a ser armazenada.
 * @param imm Deslocamento com sinal de 16 bits que é adicionado ao registrador rs para obter o endereço da memória.
 * @param rs Registrador fonte que contém o endereço base da memória.
 */
void mips_sw(int rd, int imm, int rs);

/**
 * @brief Realiza a operação de subtração entre os registradores rs e rt, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_sub(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de subtração entre os registradores rs e rt sem sinal, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_subu(int rd, int rs, int rt);
