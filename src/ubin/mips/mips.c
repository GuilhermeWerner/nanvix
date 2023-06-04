#include "mips.h"

void test1()
{
	printf("\n-- TESTE 1 --\n");

	int size = 9 * sizeof(int);
	int *program = (int *)malloc(size);

	program[0] = mips_typeR_bytecode(ADD, t0, s0, s1); // add $t0, $s0, $s1
	program[1] = mips_typeR_bytecode(SUB, s4, t0, t1); // sub $s4, $t0, $t1
	program[2] = mips_typeI_bytecode(ADDI, t7, t0, 7); // addi $t7, $t0, 7
	program[3] = mips_typeI_bytecode(SW, t0, s4, 0);   // sw $t0, 0($s4)
	program[4] = mips_typeI_bytecode(SW, t0, s4, 23);  // sw $t0, 23($s4)
	program[5] = mips_typeI_bytecode(LW, s2, s4, 0);   // lw $s2, 0($s4)
	program[6] = mips_typeI_bytecode(LW, s2, s4, 23);  // lw $s2, 23($s4)
	program[7] = mips_typeI_bytecode(SW, t0, s4, -4);  // sw $t0, -4($s4)
	program[8] = mips_typeI_bytecode(LW, s2, s4, -4);  // lw $s2, -4($s4)

	mips_load(program, size);
	mips_exec();
}

void test2()
{
	printf("\n-- TESTE 2 --\n");

	int size = 10 * sizeof(int);
	int *program = (int *)malloc(size);

	program[0] = mips_typeI_bytecode(ADDI, s0, t0, 2); // addi $s0, $t0, 2
	program[1] = mips_typeI_bytecode(ADDI, s1, t0, 3); // addi $s1, $t0, 3
	program[2] = mips_typeI_bytecode(ADDI, s2, t0, 4); // addi $s2, $t0, 4
	program[3] = mips_typeI_bytecode(ADDI, s3, t0, 5); // addi $s3, $t0, 5
	program[4] = mips_typeR_bytecode(ADD, t0, s0, s1); // add $t0, $s0, $s1
	program[5] = mips_typeR_bytecode(ADD, t1, s2, s3); // add $t1, $s2, $s3
	program[6] = mips_typeR_bytecode(SUB, s4, t0, t1); // sub $s4, $t0, $t1
	program[7] = mips_typeR_bytecode(SUB, t3, s0, s1); // sub $t3, $s0, $s1
	program[8] = mips_typeR_bytecode(ADD, s5, t3, s4); // add $s5, $t3, $s4
	program[9] = mips_typeR_bytecode(SUB, s1, s4, s5); // sub $s1, $s4, $s5

	mips_load(program, size);
	mips_exec();
}

void test3()
{
	printf("\n-- TESTE 3 --\n");

	int size = 12 * sizeof(int);
	int *program = (int *)malloc(size);

	program[0] = mips_typeI_bytecode(ORI, t0, t0, 0x7fff);
	program[1] = mips_typeI_bytecode(ORI, s0, t0, 0xffff);
	program[2] = mips_typeI_bytecode(ADDI, t1, t0, 30000);
	program[3] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[4] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[5] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[6] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[7] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[8] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[9] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[10] = mips_typeI_bytecode(ADDI, t1, t1, 30000);
	program[11] = mips_typeI_bytecode(ADDI, s1, t1, 30000);

	mips_load(program, size);
	mips_exec();
}

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}
