#pragma once

#include "Instruction.h"
#include "../Opcode/OpcodeMaps.h"

class InstructionParser {
public:
	InstructionParser(const OpcodeMaps& opcodeMaps, const uint8_t* bytes, uint64_t length, uint64_t offset = 0);

	bool GetNextInstruction(Instruction& instruction);

private:
	void ReadInstructionPrefixes(Instruction& instruction);
	const OpcodeData* GetOpcodeData(const Instruction& instruction) const;
	void ReadInstructionData(Instruction& instruction, const OpcodeData* opcode);

	bool IsByteLegacyPrefix(uint8_t byte) const;

private:
	const OpcodeMaps& OpcodeMapsRef;
	const uint8_t* Bytes;
	uint64_t Length;
	uint64_t Offset;
};