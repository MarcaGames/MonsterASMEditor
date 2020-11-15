#include "Instruction/InstructionParser.h"

#include <iostream>

InstructionParser::InstructionParser(const OpcodeMaps& opcodeMaps, const uint8_t* bytes, uint64_t length, uint64_t offset)
	: OpcodeMapsRef(opcodeMaps), Bytes(bytes), Length(length), Offset(offset) {}

bool InstructionParser::GetNextInstruction(Instruction& instruction) {
	if (Offset >= Length) return false;

	ReadInstructionPrefixes(instruction);
	const OpcodeData* opcodeData = GetOpcodeData(instruction);
	if (opcodeData != nullptr) {
		ReadInstructionData(instruction, opcodeData);
		return true;
	}
	return false;
}

void InstructionParser::ReadInstructionPrefixes(Instruction& instruction) {
	uint8_t step = 0;

	for (; step <= 7;) {
		std::cout << "[Step: " << std::hex << (uint32_t)step << ", Offset: " << std::hex << Offset << "] ";
		uint8_t byte = Bytes[Offset];
		switch (step) {
			// Step 1 through 3: Read the legacy prefix at the current byte.
		case 0:
		case 1:
		case 2:
		case 3:
			if (IsByteLegacyPrefix(byte)) {
				instruction.legacyPrefixes[step] = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read legacy prefix: " << std::hex << (uint32_t)byte << std::endl;
			} else {
				step = 4;
				std::cout << "Skipped reading legacy prefix: " << std::hex << (uint32_t)byte << std::endl;
			}
			break;
			// Step 4: Read the REX/VEX/XOP prefix at the current byte.
		case 4:
			if (byte >= 0x40 && byte <= 0x4F) { // REX Prefix.
				instruction.REX.data = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read REX prefix: " << std::hex << (uint32_t)byte << std::endl;
			} else if (byte == 0xC4 || byte == 0xC5) {  // VEX Prefix.
				instruction.VEX = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read VEX prefix: " << std::hex << (uint32_t)byte << std::endl;
			} else if (byte == 0x8F) {  // XOP Prefix.
				instruction.XOP = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read XOP prefix: " << std::hex << (uint32_t)byte << std::endl;
			} else {
				step++;
				std::cout << "Skipped reading prefix: " << std::hex << (uint32_t)byte << std::endl;
			}
			break;
			// Step 5: Read the first Escape or RXBMap_select or RvvvvLpp.
		case 5:
			if (instruction.VEX == 0xC4 || instruction.XOP == 0X8F) {
				instruction.RXBMap_select.data = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read RXBMap_select: " << std::hex << (uint32_t)byte << std::endl;
			} else if (instruction.VEX == 0xC5) {
				instruction.XvvvvLpp.data = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step = 7;   // Skip second Escape.
				Offset++;
				std::cout << "Read RvvvvLpp: " << std::hex << (uint32_t)byte << std::endl;
			} else {
				if (byte == 0x0F) {
					instruction.Escape1 = byte;
					instruction.Bytes[instruction.NumBytes++] = byte;
					step++;
					Offset++;
					std::cout << "Read escape: " << std::hex << (uint32_t)byte << std::endl;
				} else {
					step = 7;
					std::cout << "Skipped reading escape: " << std::hex << (uint32_t)byte << std::endl;
				}
			}
			break;
			// Step 6: Read the second Escape or WvvvvLpp.
		case 6:
			if (instruction.VEX == 0xC4 || instruction.XOP == 0x8F) {
				instruction.XvvvvLpp.data = byte;
				instruction.Bytes[instruction.NumBytes++] = byte;
				step++;
				Offset++;
				std::cout << "Read WvvvvLpp: " << std::hex << (uint32_t)byte << std::endl;
			} else {
				switch (byte) {
				case 0x0F:
				case 0x38:
				case 0x3A:
					instruction.Escape2 = byte;
					instruction.Bytes[instruction.NumBytes++] = byte;
					step++;
					Offset++;
					std::cout << "Read escape: " << std::hex << (uint32_t)byte << std::endl;
					break;
				default:
					step = 7;
					std::cout << "Skipped reading escape: " << std::hex << (uint32_t)byte << std::endl;
				}
			}
			break;
			// Step 7: Finally read the opcode.
		case 7:
			instruction.opcode = byte;
			instruction.Bytes[instruction.NumBytes++] = byte;
			step++;
			Offset++;
			std::cout << "Read opcode: " << std::hex << (uint32_t)byte << std::endl;
			break;
		}
	}
}

const OpcodeData* InstructionParser::GetOpcodeData(const Instruction& instruction) const {
	uint8_t opcodeMapIndex = 0;
	switch (instruction.Escape1) {
	case 0x00:
		opcodeMapIndex = PrimaryOpcodeMap;
		break;
	case 0x0F:
		switch (instruction.Escape2) {
		case 0x0F:
			// 3D Now!
			break;
		case 0x38:
			opcodeMapIndex = X0F_38OpcodeMap;
			break;
		case 0x3A:
			opcodeMapIndex = X0F_3AOpcodeMap;
			break;
		default:
			opcodeMapIndex = SecondaryOpcodeMap;
		}
		break;
	default:
	{
		switch (instruction.REX.data) {
		case 0xC5:
			opcodeMapIndex = VEXOpcodeMap1;
			break;
		case 0xC4:
			switch (instruction.RXBMap_select.data & 0b11111) {
			case 0x01:
				opcodeMapIndex = VEXOpcodeMap1;
				break;
			case 0x02:
				opcodeMapIndex = VEXOpcodeMap2;
				break;
			case 0x03:
				opcodeMapIndex = VEXOpcodeMap3;
				break;
			}
			break;
		case 0x8F:
			switch (instruction.RXBMap_select.data & 0b11111) {
			case 0x08:
				opcodeMapIndex = XOPOpcodeMap8;
				break;
			case 0x09:
				opcodeMapIndex = XOPOpcodeMap9;
				break;
			case 0x0A:
				opcodeMapIndex = XOPOpcodeMapA;
				break;
			}
			break;
		}
	}
	}
	const OpcodeMap* map = OpcodeMapsRef.GetOpcodeMap(opcodeMapIndex);
	if (map != nullptr) {
		return map->GetOpcodeData(instruction);
	}
	return nullptr;
}

void InstructionParser::ReadInstructionData(Instruction& instruction, const OpcodeData* opcode) {
	if (!opcode->valid)
		return;

	if (opcode->hasModRM) {
		instruction.ModRM.data = Bytes[Offset++];
		instruction.Bytes[instruction.NumBytes++] = instruction.ModRM.data;
		std::cout << "Read ModRM: " << std::hex << (uint32_t)instruction.ModRM.data << std::endl;
		if (opcode->hasSIB) {
			instruction.SIB.data = Bytes[Offset++];
			instruction.Bytes[instruction.NumBytes++] = instruction.SIB.data;
			std::cout << "Read SIB: " << std::hex << (uint32_t)instruction.SIB.data << std::endl;
		}
	}
	uint8_t dispImmOffset = 0;
	if (opcode->hasDisp) {
		for (uint8_t i = 0; i < opcode->dispCount && dispImmOffset < 8; i++) {
			uint8_t byte = Bytes[Offset++];
			instruction.DisImm[dispImmOffset] = byte;
			instruction.Bytes[instruction.NumBytes++] = byte;
			std::cout << "Read Disp[" << i << "]: " << std::hex << (uint32_t)byte << std::endl;
			dispImmOffset++;
		}
	}

	if (opcode->hasImm) {
		for (uint8_t i = 0; i < opcode->immCount && dispImmOffset < 8; i++) {
			uint8_t byte = Bytes[Offset++];
			instruction.DisImm[dispImmOffset] = byte;
			instruction.Bytes[instruction.NumBytes++] = byte;
			std::cout << "Read Imm[" << i << "]: " << std::hex << (uint32_t)byte << std::endl;
			dispImmOffset++;
		}
	}

	instruction.opcodeData = opcode;
}

bool InstructionParser::IsByteLegacyPrefix(uint8_t byte) const {
	switch (byte) {
	case 0xF0:
	case 0xF2:
	case 0xF3:
	case 0x2E:
	case 0x36:
	case 0x3E:
	case 0x26:
	case 0x64:
	case 0x65:
	case 0x66:
	case 0x67:
		return true;
	default:
		return false;
	}
}