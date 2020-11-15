#include "Opcode/Operand/Operand.h"
#include "Instruction/Instruction.h"

#include <string_view>

constexpr uint8_t CSd = 0;

OperandSize GetOperandSize(uint32_t notation, CPUMode cpuMode, uint8_t CSd, uint8_t REXW, bool x66x67OpAddPrefix) {
	switch (notation) {
	case 'c':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS16;
			else return OperandSize::BITS8;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BITS8;
				else return OperandSize::BITS16;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS16;
				else return OperandSize::BITS8;
			}
		case CPUMode::LONG_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS8;
			else return OperandSize::BITS16;
		}
		return OperandSize::BITS16;
	case 'a':
	case 'z':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS32;
			else return OperandSize::BITS16;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BITS16;
				else return OperandSize::BITS32;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS32;
				else return OperandSize::BITS16;
			}
		case CPUMode::LONG_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS16;
			else return OperandSize::BITS32;
		}
		return OperandSize::BITS32;
	case 'v':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS32;
			else return OperandSize::BITS16;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BITS16;
				else return OperandSize::BITS32;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS32;
				else return OperandSize::BITS16;
			}
		case CPUMode::LONG_MODE:
			if (REXW) {
				return OperandSize::BITS64;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS16;
				else return OperandSize::BITS32;
			}
		}
		return OperandSize::BITS32;
	case 'y':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS64;
			else return OperandSize::BITS32;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BITS32;
				else return OperandSize::BITS64;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS64;
				else return OperandSize::BITS32;
			}
		case CPUMode::LONG_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS32;
			else return OperandSize::BITS64;
		}
		return OperandSize::BITS64;
	case 'p':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS48;
			else return OperandSize::BITS32;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BITS32;
				else return OperandSize::BITS48;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BITS48;
				else return OperandSize::BITS32;
			}
		case CPUMode::LONG_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BITS32;
			else return OperandSize::BITS48;
		}
		return OperandSize::BITS48;
	case 'b':
	case 'pb':
	case 'pk':
		return OperandSize::BITS8;
	case 'w':
	case 'i':
	case 'ph':
	case 'pi':
	case 'pw':
		return OperandSize::BITS16;
	case 'd':
	case 'j':
	case 'pdw':
	case 'pj':
	case 'ps':
	case 'sj':
	case 'ss':
		return OperandSize::BITS32;
	case 'q':
	case 'o.q':
	case 'pd':
	case 'pq':
	case 'pqw':
	case 'sd':
		return OperandSize::BITS64;
	case 'o':
		return OperandSize::BITS128;
	case 'do':
		return OperandSize::BITS256;
	case 's':
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BYTES10;
			else return OperandSize::BYTES6;
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (x66x67OpAddPrefix) return OperandSize::BYTES6;
				else return OperandSize::BYTES10;
			} else {
				if (x66x67OpAddPrefix) return OperandSize::BYTES10;
				else return OperandSize::BYTES6;
			}
		case CPUMode::LONG_MODE:
			if (x66x67OpAddPrefix) return OperandSize::BYTES6;
			else return OperandSize::BYTES10;
		}
		return OperandSize::BYTES10;
	}

	switch (cpuMode) {
	case CPUMode::REAL_MODE:
		if (x66x67OpAddPrefix) return OperandSize::BITS32;
		else return OperandSize::BITS16;
	case CPUMode::PROTECTED_MODE:
		if (CSd) {
			if (x66x67OpAddPrefix) return OperandSize::BITS16;
			else return OperandSize::BITS32;
		} else {
			if (x66x67OpAddPrefix) return OperandSize::BITS32;
			else return OperandSize::BITS16;
		}
	case CPUMode::LONG_MODE:
		if (REXW) {
			return OperandSize::BITS64;
		} else {
			if (x66x67OpAddPrefix) return OperandSize::BITS16;
			else return OperandSize::BITS32;
		}
	}
	return OperandSize::BITS32;
}

const char* GetRegisterName(uint8_t xReg, RegisterSize registerSize, bool REXUsed = false) {
	switch (registerSize) {
	case RegisterSize::BIT8:
		switch (xReg) {
		case 0x0:
			return "AL";
		case 0x1:
			return "CL";
		case 0x2:
			return "DL";
		case 0x3:
			return "BL";
		case 0x4:
			if (REXUsed) return "SPL";
			else return "AH";
		case 0x5:
			if (REXUsed) return "BPL";
			else return "CH";
		case 0x6:
			if (REXUsed) return "SIL";
			else return "DH";
		case 0x7:
			if (REXUsed) return "DIL";
			else return "BH";
		case 0x8:
			return "R8L";
		case 0x9:
			return "R9L";
		case 0xA:
			return "R10L";
		case 0xB:
			return "R11L";
		case 0xC:
			return "R12L";
		case 0xD:
			return "R13L";
		case 0xE:
			return "R14L";
		case 0xF:
			return "R15L";
		}
		break;
	case RegisterSize::BIT16:
		switch (xReg) {
		case 0x0:
			return "AX";
		case 0x1:
			return "CX";
		case 0x2:
			return "DX";
		case 0x3:
			return "BX";
		case 0x4:
			return "SP";
		case 0x5:
			return "BP";
		case 0x6:
			return "SI";
		case 0x7:
			return "DI";
		case 0x8:
			return "R8W";
		case 0x9:
			return "R9W";
		case 0xA:
			return "R10W";
		case 0xB:
			return "R11W";
		case 0xC:
			return "R12W";
		case 0xD:
			return "R13W";
		case 0xE:
			return "R14W";
		case 0xF:
			return "R15W";
		}
		break;
	case RegisterSize::BIT32:
		switch (xReg) {
		case 0x0:
			return "EAX";
		case 0x1:
			return "ECX";
		case 0x2:
			return "EDX";
		case 0x3:
			return "EBX";
		case 0x4:
			return "ESP";
		case 0x5:
			return "EBP";
		case 0x6:
			return "ESI";
		case 0x7:
			return "EDI";
		case 0x8:
			return "R8D";
		case 0x9:
			return "R9D";
		case 0xA:
			return "R10D";
		case 0xB:
			return "R11D";
		case 0xC:
			return "R12D";
		case 0xD:
			return "R13D";
		case 0xE:
			return "R14D";
		case 0xF:
			return "R15D";
		}
		break;
	case RegisterSize::BIT64:
		switch (xReg) {
		case 0x0:
			return "RAX";
		case 0x1:
			return "RCX";
		case 0x2:
			return "RDX";
		case 0x3:
			return "RBX";
		case 0x4:
			return "RSP";
		case 0x5:
			return "RBP";
		case 0x6:
			return "RSI";
		case 0x7:
			return "RDI";
		case 0x8:
			return "R8";
		case 0x9:
			return "R9";
		case 0xA:
			return "R10";
		case 0xB:
			return "R11";
		case 0xC:
			return "R12";
		case 0xD:
			return "R13";
		case 0xE:
			return "R14";
		case 0xF:
			return "R15";
		}
		break;
	case RegisterSize::BIT80:
		switch (xReg) {
		case 0x0:
			return "ST0";
		case 0x1:
			return "ST1";
		case 0x2:
			return "ST2";
		case 0x3:
			return "ST3";
		case 0x4:
			return "ST4";
		case 0x5:
			return "ST5";
		case 0x6:
			return "ST6";
		case 0x7:
			return "ST7";
		}
		break;
	case RegisterSize::MMX64:
		switch (xReg) {
		case 0x0:
		case 0x8:
			return "MMX0";
		case 0x1:
		case 0x9:
			return "MMX1";
		case 0x2:
		case 0xA:
			return "MMX2";
		case 0x3:
		case 0xB:
			return "MMX3";
		case 0x4:
		case 0xC:
			return "MMX4";
		case 0x5:
		case 0xD:
			return "MMX5";
		case 0x6:
		case 0xE:
			return "MMX6";
		case 0x7:
		case 0xF:
			return "MMX7";
		}
		break;
	case RegisterSize::XMM128:
		switch (xReg) {
		case 0x0:
			return "XMM0";
		case 0x1:
			return "XMM1";
		case 0x2:
			return "XMM2";
		case 0x3:
			return "XMM3";
		case 0x4:
			return "XMM4";
		case 0x5:
			return "XMM5";
		case 0x6:
			return "XMM6";
		case 0x7:
			return "XMM7";
		case 0x8:
			return "XMM8";
		case 0x9:
			return "XMM9";
		case 0xA:
			return "XMM10";
		case 0xB:
			return "XMM11";
		case 0xC:
			return "XMM12";
		case 0xD:
			return "XMM13";
		case 0xE:
			return "XMM14";
		case 0xF:
			return "XMM15";
		}
		break;
	case RegisterSize::YMM256:
		switch (xReg) {
		case 0x0:
			return "YMM0";
		case 0x1:
			return "YMM1";
		case 0x2:
			return "YMM2";
		case 0x3:
			return "YMM3";
		case 0x4:
			return "YMM4";
		case 0x5:
			return "YMM5";
		case 0x6:
			return "YMM6";
		case 0x7:
			return "YMM7";
		case 0x8:
			return "YMM8";
		case 0x9:
			return "YMM9";
		case 0xA:
			return "YMM10";
		case 0xB:
			return "YMM11";
		case 0xC:
			return "YMM12";
		case 0xD:
			return "YMM13";
		case 0xE:
			return "YMM14";
		case 0xF:
			return "YMM15";
		}
		break;
	case RegisterSize::SEG16:
		switch (xReg) {
		case 0x0:
		case 0x8:
			return "ES";
		case 0x1:
		case 0x9:
			return "CS";
		case 0x2:
		case 0xA:
			return "SS";
		case 0x3:
		case 0xB:
			return "DS";
		case 0x4:
		case 0xC:
			return "FS";
		case 0x5:
		case 0xD:
			return "GS";
		}
		break;
	case RegisterSize::CON32:
		switch (xReg) {
		case 0x0:
			return "CR0";
		case 0x1:
			return "CR1";
		case 0x2:
			return "CR2";
		case 0x3:
			return "CR3";
		case 0x4:
			return "CR4";
		case 0x5:
			return "CR5";
		case 0x6:
			return "CR6";
		case 0x7:
			return "CR7";
		case 0x8:
			return "CR8";
		case 0x9:
			return "CR9";
		case 0xA:
			return "CR10";
		case 0xB:
			return "CR11";
		case 0xC:
			return "CR12";
		case 0xD:
			return "CR13";
		case 0xE:
			return "CR14";
		case 0xF:
			return "CR15";
		}
		break;
	case RegisterSize::DBG32:
		switch (xReg) {
		case 0x0:
			return "DR0";
		case 0x1:
			return "DR1";
		case 0x2:
			return "DR2";
		case 0x3:
			return "DR3";
		case 0x4:
			return "DR4";
		case 0x5:
			return "DR5";
		case 0x6:
			return "DR6";
		case 0x7:
			return "DR7";
		case 0x8:
			return "DR8";
		case 0x9:
			return "DR9";
		case 0xA:
			return "DR10";
		case 0xB:
			return "DR11";
		case 0xC:
			return "DR12";
		case 0xD:
			return "DR13";
		case 0xE:
			return "DR14";
		case 0xF:
			return "DR15";
		}
		break;
	}
	return "INVALID";
}

const char* FormatOperand(const Instruction& instruction, const std::string& operand, CPUMode cpuMode, uint8_t CSd) {
	if (operand == "%AL") {
		return "AL";
	} else if (operand == "%rAX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EAX";
			} else {
				return "AX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "AX";
				} else {
					return "EAX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EAX";
				} else {
					return "AX";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RAX";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "AX";
				} else {
					return "EAX";
				}
			}
		}
	} else if (operand == "%rCX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ECX";
			} else {
				return "CX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "CX";
				} else {
					return "ECX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ECX";
				} else {
					return "CX";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RCX";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "CX";
				} else {
					return "ECX";
				}
			}
		}
	} else if (operand == "%rDX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EDX";
			} else {
				return "DX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DX";
				} else {
					return "EDX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EDX";
				} else {
					return "DX";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RDX";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DX";
				} else {
					return "EDX";
				}
			}
		}
	} else if (operand == "%rBX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EBX";
			} else {
				return "BX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "BX";
				} else {
					return "EBX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EBX";
				} else {
					return "BX";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RBX";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "BX";
				} else {
					return "EBX";
				}
			}
		}
	} else if (operand == "%rSP") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ESP";
			} else {
				return "SP";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SP";
				} else {
					return "ESP";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ESP";
				} else {
					return "SP";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RSP";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SP";
				} else {
					return "ESP";
				}
			}
		}
	} else if (operand == "%rBP") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EBP";
			} else {
				return "BP";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "BP";
				} else {
					return "EBP";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EBP";
				} else {
					return "PB";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RBP";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "PB";
				} else {
					return "EBP";
				}
			}
		}
	} else if (operand == "%rSI") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ESI";
			} else {
				return "SI";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SI";
				} else {
					return "ESI";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ESI";
				} else {
					return "SI";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RSI";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SI";
				} else {
					return "ESI";
				}
			}
		}
	} else if (operand == "%rDI") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EDI";
			} else {
				return "DI";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DI";
				} else {
					return "EDI";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EDI";
				} else {
					return "DI";
				}
			}
		case CPUMode::LONG_MODE:
			if (instruction.GetREX().GetWBits()) {
				return "RDI";
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DI";
				} else {
					return "EDI";
				}
			}
		}
	} else if (operand == "%eAX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EAX";
			} else {
				return "AX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "AX";
				} else {
					return "EAX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EAX";
				} else {
					return "AX";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eCX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ECX";
			} else {
				return "CX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "CX";
				} else {
					return "ECX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ECX";
				} else {
					return "CX";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eDX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EDX";
			} else {
				return "DX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DX";
				} else {
					return "EDX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EDX";
				} else {
					return "DX";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eBX") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EBX";
			} else {
				return "BX";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "BX";
				} else {
					return "EBX";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EBX";
				} else {
					return "BX";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eSP") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ESP";
			} else {
				return "SP";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SP";
				} else {
					return "ESP";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ESP";
				} else {
					return "SP";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eBP") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EBP";
			} else {
				return "BP";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "BP";
				} else {
					return "EBP";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EBP";
				} else {
					return "BP";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eSI") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "ESI";
			} else {
				return "SI";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "SI";
				} else {
					return "ESI";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "ESI";
				} else {
					return "SI";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%eDI") {
		switch (cpuMode) {
		case CPUMode::REAL_MODE:
			if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
				return "EDI";
			} else {
				return "DI";
			}
		case CPUMode::PROTECTED_MODE:
			if (CSd) {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "DI";
				} else {
					return "EDI";
				}
			} else {
				if (instruction.GetLegacyPrefix(0) == 0x66 || instruction.GetLegacyPrefix(1) == 0x66 || instruction.GetLegacyPrefix(2) == 0x66 || instruction.GetLegacyPrefix(3) == 0x66) {
					return "EDI";
				} else {
					return "DI";
				}
			}
		case CPUMode::LONG_MODE:
			return "INVALID";
		}
	} else if (operand == "%ES") {
		return "ES";
	} else if (operand == "%CS") {
		return "CS";
	} else if (operand == "%SS") {
		return "SS";
	} else if (operand == "%DS") {
		return "DS";
	} else if (operand == "%ES") {
		return "ES";
	} else if (operand == "%ES") {
		return "ES";
	} else if (operand == "%ES") {
		return "ES";
	} else if (operand == "%r8") {
		return "r8";
	} else if (operand == "%r9") {
		return "r9";
	} else if (operand == "%r10") {
		return "r10";
	} else if (operand == "%r11") {
		return "r11";
	} else if (operand == "%r12") {
		return "r12";
	} else if (operand == "%r13") {
		return "r13";
	} else if (operand == "%r14") {
		return "r14";
	} else if (operand == "%r15") {
		return "r15";
	}

	// Get it according to other data:
	char firstNotation = operand[1];
	std::string_view secondNotation = operand;
	secondNotation = secondNotation.substr(2);

	OperandSize operandSize = OperandSize::BITS32;
	if (secondNotation.size() > 2) {
		int secondNotationInt = secondNotation[0] | secondNotation[1] << 8 | secondNotation[2] << 16;
		bool hasX66X67 = false;
		for (uint8_t i = 0; i < 4; i++) {
			uint8_t prefix = instruction.GetLegacyPrefix(i);
			if (prefix == 0x66 || prefix == 0x67) {
				hasX66X67 = true;
				break;
			}
		}

		operandSize = GetOperandSize(secondNotationInt, cpuMode, CSd, instruction.GetREX().GetWBits(), hasX66X67);
	} else if (secondNotation.size() > 1) {
		int secondNotationInt = secondNotation[0] | secondNotation[1] << 8;
		bool hasX66X67 = false;
		for (uint8_t i = 0; i < 4; i++) {
			uint8_t prefix = instruction.GetLegacyPrefix(i);
			if (prefix == 0x66 || prefix == 0x67) {
				hasX66X67 = true;
				break;
			}
		}

		operandSize = GetOperandSize(secondNotationInt, cpuMode, CSd, instruction.GetREX().GetWBits(), hasX66X67);
	} else if (secondNotation.size() > 0) {
		int secondNotationInt = secondNotation[0];
		bool hasX66X67 = false;
		for (uint8_t i = 0; i < 4; i++) {
			uint8_t prefix = instruction.GetLegacyPrefix(i);
			if (prefix == 0x66 || prefix == 0x67) {
				hasX66X67 = true;
				break;
			}
		}

		operandSize = GetOperandSize(secondNotationInt, cpuMode, CSd, instruction.GetREX().GetWBits(), hasX66X67);
	}

	switch (firstNotation) {
	case 'E':
	{
		uint8_t rmField = instruction.GetModRM().GetRmBits();
		return GetRegisterName(rmField, (RegisterSize)(uint32_t)operandSize, instruction.GetREX().GetData() >= 0x40 && instruction.GetREX().GetData() <= 0x4F);
		break;
	}
	case 'G':
	{
		uint8_t regField = instruction.GetModRM().GetRegBits();
		return GetRegisterName(regField, (RegisterSize)(uint32_t)operandSize, instruction.GetREX().GetData() >= 0x40 && instruction.GetREX().GetData() <= 0x4F);
		break;
	}
	}
	return "INVALID";
}
