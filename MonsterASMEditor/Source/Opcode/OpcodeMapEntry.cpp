#include "Opcode/OpcodeMapEntry.h"
#include "Instruction/Instruction.h"

const OpcodeData* OpcodeMapEntry::GetOpcodeData(const Instruction& instruction) const {
	auto itr = this->opcodes.find(*reinterpret_cast<const InstructionPrefixes*>(&instruction));
	if (itr != this->opcodes.end()) {
		return &itr->second;
	}
	return nullptr;
}

void OpcodeMapEntry::SetOpcode(const InstructionPrefixes& prefix, const OpcodeData& opcode) {
	this->opcodes.insert_or_assign(prefix, opcode);
}
