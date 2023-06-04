#include "mem.h"
#include "consts.h"
#include "decode.h"

int mips_read_mem(int addr)
{
	return mips_memory_buffer[addr];
}

void mips_write_mem(int addr, int val)
{
	mips_memory_buffer[addr] = val;
}

void mips_load(int *program, int size)
{
	mips_memory_len = size / sizeof(int);

	for (int i = 0; i < mips_memory_len; i++)
	{
		mips_memory_buffer[i] = program[i];
	}

	for (int i = 0; i < REGISTER_LEN; i++)
	{
		mips_reg_bank[i] = 10;
	}
}

void mips_clean()
{
	mips_counter = 0;
	memset(mips_reg_bank, 0, sizeof(mips_reg_bank));
	memset(mips_memory_buffer, 0, sizeof(mips_memory_buffer));
	mips_memory_len = 0;
	mips_cycles = 0;
}

void mips_exec()
{
	mips_counter = 0;
	mips_cycles = 0;
	int inst, ic = 0;

	while (mips_counter < mips_memory_len)
	{
		inst = mips_memory_buffer[mips_counter];
		mips_cycles++; // Instruction Fetch

		mips_decode_inst(inst);

		mips_counter++;
		ic++;
	}

	printf("CPI: %d / %d = %d\n", mips_cycles, ic, mips_cycles / ic);

	mips_clean();
}
