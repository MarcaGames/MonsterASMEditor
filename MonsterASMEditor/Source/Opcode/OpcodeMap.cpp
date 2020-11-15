#include "Opcode/OpcodeMap.h"

#include "Instruction/Instruction.h"

const OpcodeData* OpcodeMap::GetOpcodeData(const Instruction& instruction) const {
	return this->entries[instruction.GetOpcode()].GetOpcodeData(instruction);
}