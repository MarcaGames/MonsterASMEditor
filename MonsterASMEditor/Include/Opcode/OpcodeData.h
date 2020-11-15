#pragma once

#include "../Instruction/Instruction.h"

#include <stdint.h>
#include <string>

struct OpcodeData {
public:
	std::string Format(const Instruction& instruction) const;

	friend std::ostream& operator<<(std::ostream& lhs, const OpcodeData& rhs);

public:
	const char* syntax = "INVALID";
	bool hasModRM = false;
	bool hasSIB = false;
	bool hasDisp = false;
	bool hasImm = false;
	uint8_t dispCount = 0;
	uint8_t immCount = 0;
	bool valid = false;
};