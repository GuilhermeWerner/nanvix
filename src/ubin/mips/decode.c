#include "consts.h"
#include "decode.h"
#include "instr.h"
#include "reg.h"

void mips_typeR_inst(int inst, int opcode)
{
	int rs = (inst >> 21) & 0x1F;
	int rt = (inst >> 16) & 0x1F;
	int rd = (inst >> 11) & 0x1F;
	int shamt = (inst >> 6) & 0x1F;
	int funct = inst & 0x3F;

	opcode = opcode << 26;
	opcode = opcode | funct;

	switch (opcode)
	{
	case ADD:
		printf("ADD %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_add(rd, rs, rt);
		break;
	case ADDU:
		printf("ADDU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SUB:
		printf("SUB %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_sub(rd, rs, rt);
		break;
	case SUBU:
		printf("SUBU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case AND:
		printf("AND %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case OR:
		printf("OR %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLT:
		printf("SLT %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLTU:
		printf("SLTU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLL:
		printf("SLL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case SRL:
		printf("SRL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case JR:
		printf("JR %d\n", rs);
		break;
	default:
		printf("Instrução R não reconhecida\n");
		break;
	}
}

void mips_typeJ_inst(int inst, int opcode)
{
	int target = inst & 0x03FFFFFF;

	opcode = opcode << 26;

	switch (opcode)
	{
	case J:
		printf("J %x\n", target);
		mips_j(target);
		break;
	case JAL:
		printf("JAL %x\n", target);
		break;
	default:
		printf("Instrução J não reconhecida\n");
		break;
	}
}

void mips_typeI_inst(int inst, int opcode)
{
	int rs = (inst >> 21) & 0x1F;
	int rt = (inst >> 16) & 0x1F;
	int imm = inst & 0xFFFF;

	opcode = opcode << 26;

	switch (opcode)
	{
	case ADDI:
		printf("ADDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		mips_addi(rt, rs, imm);
		break;
	case ADDIU:
		printf("ADDIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ANDI:
		printf("ANDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ORI:
		printf("ORI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTI:
		printf("SLTI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTIU:
		printf("SLTIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case LUI:
		printf("LUI %s, %x\n", mips_get_reg_name(rt), imm);
		break;
	case LW:
		printf("LW %s, %d(%s)\n", mips_get_reg_name(rt), imm, mips_get_reg_name(rs));
		mips_lw(rt, imm, rs);
		break;
	case SW:
		printf("SW %s, %d(%s)\n", mips_get_reg_name(rt), imm, mips_get_reg_name(rs));
		mips_sw(rt, imm, rs);
		break;
	case BEQ:
		printf("BEQ %s, %d, %x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case BNE:
		printf("BNE %s, %d, %x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	default:
		printf("Instrução I não reconhecida\n");
		break;
	}
}

void mips_decode_inst(int inst)
{
	// Os 6 bits mais significativos da instrução contêm o opcode, que identifica a operação a ser executada.
	int opcode = inst >> 26;

	// Determina o tipo da instrução com base no opcode.
	if (opcode == 0)
	{
		mips_typeR_inst(inst, opcode);
	}
	else if (opcode == 2 || opcode == 3)
	{
		mips_typeJ_inst(inst, opcode);
	}
	else
	{
		mips_typeI_inst(inst, opcode);
	}
}
