#include "instr.h"
#include "consts.h"
#include "mem.h"
#include "reg.h"

void mips_add(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) + mips_get_reg(rt));
	printf("%d + %d = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), mips_get_reg(rd));
}

void mips_addu(int rd, int rs, int rt)
{
	mips_set_reg_unsigned(rd, (unsigned int)mips_get_reg(rs) + (unsigned int)mips_get_reg(rt));
	printf("%d + %d = %d\n\n", (unsigned int)mips_get_reg(rs), (unsigned int)mips_get_reg(rt), mips_get_reg(rd));
}

void mips_addi(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) + imm);
	printf("%d + %d = %d\n\n", mips_get_reg(rs), imm, mips_get_reg(rt));
}

void mips_addiu(int rt, int rs, int imm)
{
	mips_set_reg_unsigned(rt, (unsigned int)mips_get_reg(rs) + (unsigned int)imm);
	printf("%d + %d = %d\n\n", (unsigned int)mips_get_reg(rs), (unsigned int)imm, mips_get_reg(rt));
}

void mips_and(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) & mips_get_reg(rt));
	printf("%d & %d = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), mips_get_reg(rd));
}

void mips_andi(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) & imm);
	printf("%d & %d = %d\n\n", mips_get_reg(rs), imm, mips_get_reg(rt));
}

void mips_beq(int rs, int rt, int imm)
{
	if (mips_get_reg(rs) == mips_get_reg(rt))
	{
		mips_counter = imm;
		printf("%d == %d -> true ; PC = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), imm);
	}
	else 
	{
		printf("%d == %d -> false\n\n", mips_get_reg(rs), mips_get_reg(rt));
	}
}

void mips_bne(int rs, int rt, int imm)
{
	if (mips_get_reg(rs) != mips_get_reg(rt))
	{
		mips_counter = imm;
		printf("%d != %d -> true ; PC = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), imm);
	}
	else 
	{
		printf("%d != %d -> false\n\n", mips_get_reg(rs), mips_get_reg(rt));
	}
}

void mips_j(int target)
{
	mips_counter = target;
	printf("PC = %d\n\n", target);
}

void mips_jal(int target)
{
	mips_reg_bank[ra] = mips_counter++;
	mips_counter = target;
	printf("ra = PC + 1 ; PC = %d\n\n", target);
}

void mips_jr(int rs)
{
	mips_counter = mips_get_reg(rs);
	printf("PC = %d\n\n", mips_get_reg(rs));
}

void mips_lw(int rt, int imm, int rs)
{
	mips_set_reg(rt, mips_read_mem(imm + mips_get_reg(rs)));
	printf("%s = mem[%d]\n\n", mips_get_reg_name(rt), mips_get_reg(rs) + imm);
}

void mips_or(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) | mips_get_reg(rt));
	printf("%d | %d = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), mips_get_reg(rd));
}

void mips_ori(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) | imm);
	printf("%d | %d = %d\n\n", mips_get_reg(rs), imm, mips_get_reg(rt));
}

void mips_slt(int rd, int rs, int rt)
{
	if (mips_get_reg(rs) < mips_get_reg(rt))
	{
		mips_set_reg(rd, 1);
	}
	else
	{
		mips_set_reg(rd, 0);
	}
	printf("%d < %d = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), mips_get_reg(rd));
}

void mips_sltu(int rd, int rs, int rt)
{
	if ((unsigned int) mips_get_reg(rs) < (unsigned int) mips_get_reg(rt))
	{
		mips_set_reg_unsigned(rd, 1);
	}
	else
	{
		mips_set_reg_unsigned(rd, 0);
	}
	printf("%d < %d = %d\n\n", (unsigned int) mips_get_reg(rs), (unsigned int) mips_get_reg(rt), mips_get_reg(rd));
}

void mips_slti(int rt, int rs, int shamt)
{
	if (mips_get_reg(rs) < shamt)
	{
		mips_set_reg(rt, 1);
	}
	else
	{
		mips_set_reg(rt, 0);
	}
	printf("%d < %d = %d\n\n", mips_get_reg(rs), shamt, mips_get_reg(rt));
}


void mips_sltiu(int rt, int rs, int shamt)
{
	if ((unsigned int) mips_get_reg(rs) < (unsigned int) shamt)
	{
		mips_set_reg_unsigned(rt, 1);
	}
	else
	{
		mips_set_reg_unsigned(rt, 0);
	}
	printf("%d < %d = %d\n\n", (unsigned int) mips_get_reg(rs), (unsigned int) shamt, mips_get_reg(rt));
}

void mips_sll(int rd, int rs, int shamt)
{
	mips_set_reg(rd, mips_get_reg(rs) << shamt);
	printf("%d << %d = %d\n\n", mips_get_reg(rs), shamt, mips_get_reg(rd));
}

void mips_srl(int rd, int rs, int shamt)
{
	mips_set_reg_unsigned(rd, (unsigned int) mips_get_reg(rs) >> shamt);
	printf("%d >> %d = %d\n\n", mips_get_reg(rs), shamt, mips_get_reg(rd));
}

void mips_sw(int rt, int imm, int rs)
{
	mips_write_mem(imm + mips_get_reg(rs), mips_get_reg(rt));
	printf("mem[%d] = %d\n\n", mips_get_reg(rs) + imm, mips_get_reg(rt));
}

void mips_sub(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) - mips_get_reg(rt));
	printf("%d - %d = %d\n\n", mips_get_reg(rs), mips_get_reg(rt), mips_get_reg(rd));
}

void mips_subu(int rd, int rs, int rt)
{
	mips_set_reg_unsigned(rd, (unsigned int)mips_get_reg(rs) - (unsigned int)mips_get_reg(rt));
	printf("%d - %d = %d\n\n", (unsigned int)mips_get_reg(rs), (unsigned int)mips_get_reg(rt), mips_get_reg(rd));
}