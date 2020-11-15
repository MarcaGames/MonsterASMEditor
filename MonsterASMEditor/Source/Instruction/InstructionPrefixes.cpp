#include "Instruction/InstructionPrefixes.h"

constexpr uint64_t InstructionPrefixesSize = sizeof(InstructionPrefixes);

bool operator<(const InstructionPrefixes& lhs, const InstructionPrefixes& rhs) {
	const uint8_t* lhsBytes = reinterpret_cast<const uint8_t*>(&lhs);
	const uint8_t* rhsBytes = reinterpret_cast<const uint8_t*>(&rhs);

	for (uint64_t i = 0; i < InstructionPrefixesSize; i++)
		if (lhsBytes[i] < rhsBytes[i])
			return true;
	return false;
}