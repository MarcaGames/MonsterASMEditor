#pragma once

#include "../../Instruction/Instruction.h"

#include <string>

enum class CPUMode {
	REAL_MODE,
	PROTECTED_MODE,
	LONG_MODE
};

enum class RegisterSize : uint8_t {
	BIT8 = 0x0,
	BIT16 = 0x1,
	BIT32 = 0x2,
	BIT64 = 0x3,
	BIT80 = 0x4,
	MMX64 = 0x5,
	XMM128 = 0x6,
	YMM256 = 0x7,
	SEG16 = 0x8,
	CON32 = 0x9,
	DBG32 = 0xA
};

enum class OperandSize : uint8_t {
	BITS8 = (uint8_t)RegisterSize::BIT8,
	BITS16 = (uint8_t)RegisterSize::BIT16,
	BITS32 = (uint8_t)RegisterSize::BIT32,
	BITS64 = (uint8_t)RegisterSize::BIT64,
	BITS80 = (uint8_t)RegisterSize::BIT80,
	BITS128 = (uint8_t)RegisterSize::XMM128,
	BITS256 = (uint8_t)RegisterSize::YMM256,
	BITS48,
	BYTES6,
	BYTES10
};

const char* FormatOperand(const Instruction& instruction, const std::string& operand, CPUMode cpuMode, uint8_t CSd);
