#pragma once

#include "OpcodeMap.h"

constexpr uint8_t PrimaryOpcodeMap = 0x00;
constexpr uint8_t SecondaryOpcodeMap = 0x01;
constexpr uint8_t X0F_38OpcodeMap = 0x02;
constexpr uint8_t X0F_3AOpcodeMap = 0x03;
constexpr uint8_t VEXOpcodeMap1 = 0x04;
constexpr uint8_t VEXOpcodeMap2 = 0x05;
constexpr uint8_t VEXOpcodeMap3 = 0x06;
constexpr uint8_t XOPOpcodeMap8 = 0x07;
constexpr uint8_t XOPOpcodeMap9 = 0x08;
constexpr uint8_t XOPOpcodeMapA = 0x09;

struct OpcodeMaps {
public:
	const OpcodeMap* GetOpcodeMap(uint8_t map) const;

	OpcodeMap& CreateOpcodeMap(uint8_t map);

public:
	std::map<uint8_t, OpcodeMap> opcodeMaps;
};