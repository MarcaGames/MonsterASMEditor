#pragma once

#include "OpcodeMapEntry.h"

struct OpcodeMap {
public:
	const OpcodeData* GetOpcodeData(const Instruction& instruction) const;

public:
	OpcodeMapEntry entries[0x100];
};