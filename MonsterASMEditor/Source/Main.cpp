#include "Instruction/InstructionParser.h"

#include <iostream>

int main() {
	OpcodeMaps opcodeMaps;
	OpcodeMap& primaryOpcodeMap = opcodeMaps.CreateOpcodeMap(PrimaryOpcodeMap);
	OpcodeMapEntry& addEbGb = primaryOpcodeMap.entries[0x00];
	addEbGb.SetOpcode({}, { "ADD %Eb, %Gb", true, false, false, false, 0, 0, true });
	OpcodeMapEntry& addGbEb = primaryOpcodeMap.entries[0x02];
	addGbEb.SetOpcode({}, { "ADD %Gb, %Eb", true, false, false, false, 0, 0, true });
	OpcodeMapEntry& adcEbGb = primaryOpcodeMap.entries[0x10];
	adcEbGb.SetOpcode({}, { "ADC %Eb, %Gb", true, false, false, false, 0, 0, true });
	OpcodeMapEntry& adcGbEb = primaryOpcodeMap.entries[0x12];
	adcGbEb.SetOpcode({}, { "ADC %Gb, %Eb", true, false, false, false, 0, 0, true });

	uint8_t instructions[]{ 0x10, 0xC3, 0x00, 0xC3, 0x12, 0xC3, 0x02, 0xC3 };

	InstructionParser parser = InstructionParser(opcodeMaps, instructions, sizeof(instructions));
	Instruction instruction;
	while (parser.GetNextInstruction(instruction = {})) {
		std::cout << instruction << std::endl;
		std::cout << instruction.opcodeData->Format(instruction) << std::endl;
	}
}