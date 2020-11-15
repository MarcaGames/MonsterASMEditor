#pragma once

#include "InstructionPrefixes.h"

#include <ostream>

struct OpcodeData;

struct Instruction : public InstructionPrefixes {
public:
	inline uint8_t GetOpcode() const { return this->opcode; };
	inline const ModRMSIB GetModRM() const { return this->ModRM; };
	inline const ModRMSIB GetSIB() const { return this->SIB; };
	inline uint8_t GetDisImm(uint8_t index) const { return this->DisImm[index]; };
	inline uint8_t GetByte(uint8_t index) const { return this->Bytes[index]; };
	inline uint8_t GetNumBytes() const { return this->NumBytes; };

	friend std::ostream& operator<<(std::ostream& lhs, const Instruction& rhs);

public:
	uint8_t opcode = 0;
	ModRMSIB ModRM = { 0 };
	ModRMSIB SIB = { 0 };
	uint8_t DisImm[8]{ 0, 0, 0, 0, 0, 0, 0, 0 };
	uint8_t Bytes[15]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	uint8_t NumBytes = 0;

	const OpcodeData* opcodeData;
};