#include "Opcode/OpcodeMaps.h"

const OpcodeMap* OpcodeMaps::GetOpcodeMap(uint8_t map) const {
	auto itr = this->opcodeMaps.find(map);
	if (itr != this->opcodeMaps.end()) {
		return &itr->second;
	}
	return nullptr;
}

OpcodeMap& OpcodeMaps::CreateOpcodeMap(uint8_t map) {
	auto itr = this->opcodeMaps.find(map);
	if (itr != this->opcodeMaps.end())
		return itr->second;
	return this->opcodeMaps.insert({ map, {} }).first->second;
}