#pragma once

#include "Bitfields.h"

struct InstructionPrefixes {
public:
	inline uint8_t GetLegacyPrefix(uint8_t index) const { return this->legacyPrefixes[index]; };
	inline const REX GetREX() const { return this->REX; };
	inline uint8_t GetVEX() const { return this->VEX; };
	inline uint8_t GetXOP() const { return this->XOP; };
	inline uint8_t GetEscape1() const { return this->Escape1; };
	inline const RXBMap_select GetRXBMap_select() const { return this->RXBMap_select; };
	inline uint8_t GetEscape2() const { return this->Escape2; };
	inline const XvvvvLpp GetXvvvvLpp() const { return this->XvvvvLpp; };

	friend bool operator<(const InstructionPrefixes& lhs, const InstructionPrefixes& rhs);

public:
	uint8_t legacyPrefixes[4]{ 0, 0, 0, 0 };
	union {
	public:
		REX REX = { 0 };
		uint8_t VEX;
		uint8_t XOP;
	};
	union {
	public:
		uint8_t Escape1 = 0;
		RXBMap_select RXBMap_select;
	};
	union {
	public:
		uint8_t Escape2 = 0;
		XvvvvLpp XvvvvLpp;
	};
};