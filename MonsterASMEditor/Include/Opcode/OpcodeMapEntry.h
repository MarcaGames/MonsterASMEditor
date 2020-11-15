#pragma once

#include "../Instruction/InstructionPrefixes.h"
#include "OpcodeData.h"

#include <map>

struct OpcodeMapEntry {
public:
	const OpcodeData* GetOpcodeData(const Instruction& instruction) const;

	void SetOpcode(const InstructionPrefixes& prefix, const OpcodeData& opcode);

public:
	std::map<InstructionPrefixes, OpcodeData> opcodes;
};