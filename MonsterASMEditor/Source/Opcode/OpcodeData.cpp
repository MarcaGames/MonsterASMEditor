#include "Opcode/OpcodeData.h"
#include "Instruction/Instruction.h"
#include "Opcode/Operand/Operand.h"

#include <sstream>

bool HasString(const std::string& str, const std::string& otherStr) {
	uint64_t pos = str.find(otherStr);
	return pos < str.length();
}

bool ReplaceString(std::string& str, uint64_t offset, const std::string& from, const std::string& to) {
	uint64_t pos = str.find(from, offset);
	if (pos < str.length()) {
		str.replace(pos, from.length(), to);
		return true;
	}
	return false;
}

uint64_t FindFirstNonOperandCharacter(const std::string& str, uint64_t offset = 0) {
	while (offset < str.length()) {
		switch (str[offset]) {
		case 'A':
		case 'B':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case '*':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'i':
		case 'j':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'w':
		case 'h':
		case 'k':
		case 's':
		case 'v':
		case 'x':
		case 'y':
		case 'z':
		case '/':
			break;
		default:
			return offset;
		}
		offset++;
	}
	return offset;
}

std::string OpcodeData::Format(const Instruction& instruction) const {
	std::string str = syntax;
	uint64_t offset = 0;
	uint64_t start;
	while ((start = str.find_first_of('%', offset)) < str.length()) {
		uint64_t end = FindFirstNonOperandCharacter(str, start + 1);
		std::string operand = str.substr(start, end - start);
		ReplaceString(str, start, operand, FormatOperand(instruction, operand, CPUMode::REAL_MODE, 0));
		offset = end + 1;
		if (offset >= str.length())
			break;
	}
	return str;
}

std::ostream& operator<<(std::ostream& lhs, const OpcodeData& rhs) {
	lhs << "Opcode Data:" << std::endl;
	lhs << "\tSyntax: " << rhs.syntax;
	lhs << "\tHas ModRM: " << rhs.hasModRM << std::endl;
	lhs << "\tHas SIB: " << rhs.hasSIB << std::endl;
	lhs << "\tHas Disp: " << rhs.hasDisp << std::endl;
	lhs << "\tHas Imm: " << rhs.hasImm << std::endl;
	lhs << "\tDisp Count: " << rhs.dispCount << std::endl;
	lhs << "\tImm Count: " << rhs.immCount << std::endl;
	lhs << "\tValid: " << rhs.valid << std::endl;
	return lhs;
}