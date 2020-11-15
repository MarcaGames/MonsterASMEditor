#include "Instruction/Instruction.h"

std::ostream& operator<<(std::ostream& lhs, const Instruction& rhs) {
	lhs << "Instruction:" << std::endl;
	lhs << "\tLegacy Prefix 1: " << std::hex << (uint32_t)rhs.legacyPrefixes[0] << std::endl;
	lhs << "\tLegacy Prefix 2: " << std::hex << (uint32_t)rhs.legacyPrefixes[1] << std::endl;
	lhs << "\tLegacy Prefix 3: " << std::hex << (uint32_t)rhs.legacyPrefixes[2] << std::endl;
	lhs << "\tLegacy Prefix 4: " << std::hex << (uint32_t)rhs.legacyPrefixes[3] << std::endl;
	lhs << "\tREX/VEX/XOP: " << std::hex << (uint32_t)rhs.REX.data << std::endl;
	lhs << "\tEscape 1/RXBMap_select: " << std::hex << (uint32_t)rhs.Escape1 << std::endl;
	lhs << "\tEscape 2/WvvvvLpp/RvvvvLpp: " << std::hex << (uint32_t)rhs.Escape2 << std::endl;
	lhs << "\tOpcode: " << std::hex << (uint32_t)rhs.opcode << std::endl;
	lhs << "\tModRM: " << std::hex << (uint32_t)rhs.ModRM.data << std::endl;
	lhs << "\tSIB: " << std::hex << (uint32_t)rhs.SIB.data << std::endl;
	lhs << "\tDisp Imm: ";
	for (uint8_t i = 0; i < 8; i++) {
		if (rhs.DisImm[i] == 0)
			break;
		lhs << std::hex << (uint32_t)rhs.DisImm[i] << "\t";
	}
	lhs << std::endl << "\tBytes: ";
	for (uint8_t i = 0; i < 15; i++) {
		if (rhs.Bytes[i] == 0)
			break;
		lhs << std::hex << (uint32_t)rhs.Bytes[i] << "\t";
	}
	return lhs;
}