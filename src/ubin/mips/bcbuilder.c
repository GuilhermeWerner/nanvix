#include "bcbuilder.h"
#include "consts.h"
#include "reg.h"

int mips_typeR_bytecode(int mnem, int rd, int rs, int rt)
{
	int bytecode = 0x00000000;

	switch (mnem)
	{
	case ADD:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case ADDU:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case SUB:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case SUBU:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case AND:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case OR:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case SLT:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case SLTU:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (rd << 11) | (0 << 6);
		break;
	case SLL:
		bytecode |= mnem | (0 << 21) | (rt << 16) | (rd << 11) | (rt << 6);
		break;
	case SRL:
		bytecode |= mnem | (0 << 21) | (rt << 16) | (rd << 11) | (rt << 6);
		break;
	case JR:
		bytecode |= mnem | (rs << 21) | (0 << 16) | (0 << 11) | (0 << 6);
		break;
	default:
		printf("Operacao tipo R nao reconhecida\n");
		break;
	}

	return bytecode;
}

int mips_typeJ_bytecode(int mnem, int target)
{
	int bytecode = 0x00000000;

	switch (mnem)
	{
	case J:
		bytecode |= mnem | (target & 0x03FFFFFF);
		break;
	case JAL:
		bytecode |= mnem | (target & 0x03FFFFFF);
		break;
	default:
		printf("Operacao tipo J nao reconhecida\n");
		break;
	}

	return bytecode;
}

int mips_typeI_bytecode(int mnem, int rt, int rs, int imm)
{
	int bytecode = 0x00000000;

	switch (mnem)
	{
	case ADDI:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case ADDIU:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case ANDI:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case ORI:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case SLTI:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case SLTIU:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case LW:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case SW:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case BEQ:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	case BNE:
		bytecode |= mnem | (rs << 21) | (rt << 16) | (imm & 0xFFFF);
		break;
	default:
		printf("Operacao tipo I nao reconhecida\n");
		break;
	}

	return bytecode;
}