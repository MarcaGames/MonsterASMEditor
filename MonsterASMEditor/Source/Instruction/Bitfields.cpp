#include "Instruction/Bitfields.h"

constexpr uint8_t REX_B_BIT = 0;
constexpr uint8_t REX_X_BIT = 1;
constexpr uint8_t REX_R_BIT = 2;
constexpr uint8_t REX_W_BIT = 3;
constexpr uint8_t REX_B_MASK = 0b00000001;	// 1
constexpr uint8_t REX_X_MASK = 0b00000010;	// 2
constexpr uint8_t REX_R_MASK = 0b00000100;	// 4
constexpr uint8_t REX_W_MASK = 0b00001000;	// 8

constexpr uint8_t RXBMAP_SELECT_MAP_SELECT_BIT = 0;
constexpr uint8_t RXBMAP_SELECT_B_BIT = 5;
constexpr uint8_t RXBMAP_SELECT_X_BIT = 6;
constexpr uint8_t RXBMAP_SELECT_R_BIT = 7;
constexpr uint8_t RXBMAP_SELECT_MAP_SELECT_MASK = 0b00011111;	// 31
constexpr uint8_t RXBMAP_SELECT_B_MASK = 0b00100000;	// 32
constexpr uint8_t RXBMAP_SELECT_X_MASK = 0b01000000;	// 64
constexpr uint8_t RXBMAP_SELECT_R_MASK = 0b10000000;	// 128

constexpr uint8_t XVVVVLPP_PP_BIT = 0;
constexpr uint8_t XVVVVLPP_L_BIT = 2;
constexpr uint8_t XVVVVLPP_VVVV_BIT = 3;
constexpr uint8_t XVVVVLPP_W_BIT = 7;
constexpr uint8_t XVVVVLPP_R_BIT = 7;
constexpr uint8_t XVVVVLPP_PP_MASK = 0b00000011;	// 3
constexpr uint8_t XVVVVLPP_L_MASK = 0b00000100;	// 4
constexpr uint8_t XVVVVLPP_VVVV_MASK = 0b01111000;	// 120
constexpr uint8_t XVVVVLPP_W_MASK = 0b10000000;	// 128
constexpr uint8_t XVVVVLPP_R_MASK = 0b10000000;	// 128

// !(REX.R && VEX.R && XOP.R && REX.B && VEX.B && XOP.B)
constexpr uint8_t MODRM_RM_BIT = 0;
constexpr uint8_t MODRM_REG_BIT = 3;
constexpr uint8_t MODRM_MOD_BIT = 6;
constexpr uint8_t MODRM_RM_MASK = 0b00000111;	// 7
constexpr uint8_t MODRM_REG_MASK = 0b00111000;	// 56
constexpr uint8_t MODRM_MOD_MASK = 0b11000000;	// 192
// (REX.R && VEX.R && XOP.R) && !(REX.B && VEX.B && XOP.B)
constexpr uint8_t MODRM_RM_BIT_R = 0;
constexpr uint8_t MODRM_REG_BIT_R = 4;
constexpr uint8_t MODRM_MOD_BIT_R = 7;
constexpr uint8_t MODRM_RM_MASK_R = 0b00001111;	// 15
constexpr uint8_t MODRM_REG_MASK_R = 0b01110000;	// 112
constexpr uint8_t MODRM_MOD_MASK_R = 0b10000000;	// 128
// !(REX.R && VEX.R && XOP.R) && (REX.B && VEX.B && XOP.B)
constexpr uint8_t MODRM_RM_BIT_B = 0;
constexpr uint8_t MODRM_REG_BIT_B = 3;
constexpr uint8_t MODRM_MOD_BIT_B = 7;
constexpr uint8_t MODRM_RM_MASK_B = 0b00000111;	// 7
constexpr uint8_t MODRM_REG_MASK_B = 0b01111000;	// 120
constexpr uint8_t MODRM_MOD_MASK_B = 0b10000000;	// 128
// (REX.R && VEX.R && XOP.R && REX.B && VEX.B && XOP.B)
constexpr uint8_t MODRM_RM_BIT_RB = 0;
constexpr uint8_t MODRM_REG_BIT_RB = 4;
constexpr uint8_t MODRM_MOD_BIT_RB = 8;
constexpr uint8_t MODRM_RM_MASK_RB = 0b00001111;	// 15
constexpr uint8_t MODRM_REG_MASK_RB = 0b11110000;	// 240
constexpr uint8_t MODRM_MOD_MASK_RB = 0b00000000;	// 0

// !(REX.R && VEX.R && XOP.R && REX.B && VEX.B && XOP.B)
constexpr uint8_t SIB_BASE_BIT = 0;
constexpr uint8_t SIB_INDEX_BIT = 3;
constexpr uint8_t SIB_SCALE_BIT = 6;
constexpr uint8_t SIB_BASE_MASK = 0b00000111;	// 7
constexpr uint8_t SIB_INDEX_MASK = 0b00111000;	// 56
constexpr uint8_t SIB_SCALE_MASK = 0b11000000;	// 192
// (REX.R && VEX.R && XOP.R && REX.B && VEX.B && XOP.B)
constexpr uint8_t SIB_BASE_BIT_R = 0;
constexpr uint8_t SIB_INDEX_BIT_R = 4;
constexpr uint8_t SIB_SCALE_BIT_R = 7;
constexpr uint8_t SIB_BASE_MASK_R = 0b00001111;	// 15
constexpr uint8_t SIB_INDEX_MASK_R = 0b01110000;	// 112
constexpr uint8_t SIB_SCALE_MASK_R = 0b10000000;	// 128
// (REX.R && VEX.R && XOP.R) && !(REX.B && VEX.B && XOP.B)
constexpr uint8_t SIB_BASE_BIT_B = 0;
constexpr uint8_t SIB_INDEX_BIT_B = 3;
constexpr uint8_t SIB_SCALE_BIT_B = 7;
constexpr uint8_t SIB_BASE_MASK_B = 0b00000111;	// 7
constexpr uint8_t SIB_INDEX_MASK_B = 0b01111000;	// 120
constexpr uint8_t SIB_SCALE_MASK_B = 0b10000000;	// 128
// !(REX.R && VEX.R && XOP.R) && (REX.B && VEX.B && XOP.B)
constexpr uint8_t SIB_BASE_BIT_RB = 0;
constexpr uint8_t SIB_INDEX_BIT_RB = 4;
constexpr uint8_t SIB_SCALE_BIT_RB = 8;
constexpr uint8_t SIB_BASE_MASK_RB = 0b00001111;	// 15
constexpr uint8_t SIB_INDEX_MASK_RB = 0b11110000;	// 240
constexpr uint8_t SIB_SCALE_MASK_RB = 0b00000000;	// 0

#define GET_BITS(data, offset, mask)	((data & mask) >> offset)

uint8_t REX::GetData() const {
	return this->data;
}

uint8_t REX::GetBBits() const {
	return GET_BITS(this->data, REX_B_BIT, REX_B_MASK);
}

uint8_t REX::GetXBits() const {
	return GET_BITS(this->data, REX_X_BIT, REX_X_MASK);
}

uint8_t REX::GetRBits() const {
	return GET_BITS(this->data, REX_R_BIT, REX_R_MASK);
}

uint8_t REX::GetWBits() const {
	return GET_BITS(this->data, REX_W_BIT, REX_W_MASK);
}

uint8_t RXBMap_select::GetData() const {
	return this->data;
}

uint8_t RXBMap_select::GetMapSelectBits() const {
	return GET_BITS(this->data, RXBMAP_SELECT_MAP_SELECT_BIT, RXBMAP_SELECT_MAP_SELECT_MASK);
}

uint8_t RXBMap_select::GetBBits() const {
	return GET_BITS(this->data, RXBMAP_SELECT_B_BIT, RXBMAP_SELECT_B_MASK);
}

uint8_t RXBMap_select::GetXBits() const {
	return GET_BITS(this->data, RXBMAP_SELECT_X_BIT, RXBMAP_SELECT_X_MASK);
}

uint8_t RXBMap_select::GetRBits() const {
	return GET_BITS(this->data, RXBMAP_SELECT_R_BIT, RXBMAP_SELECT_R_MASK);
}

uint8_t XvvvvLpp::GetData() const {
	return this->data;
}

uint8_t XvvvvLpp::GetppBits() const {
	return GET_BITS(this->data, XVVVVLPP_PP_BIT, XVVVVLPP_PP_MASK);
}

uint8_t XvvvvLpp::GetLBits() const {
	return GET_BITS(this->data, XVVVVLPP_L_BIT, XVVVVLPP_L_MASK);
}

uint8_t XvvvvLpp::GetvvvvBits() const {
	return GET_BITS(this->data, XVVVVLPP_VVVV_BIT, XVVVVLPP_VVVV_MASK);
}

uint8_t XvvvvLpp::GetWBits() const {
	return GET_BITS(this->data, XVVVVLPP_W_BIT, XVVVVLPP_W_MASK);
}

uint8_t XvvvvLpp::GetRBits() const {
	return GET_BITS(this->data, XVVVVLPP_R_BIT, XVVVVLPP_R_MASK);
}

uint8_t ModRMSIB::GetData() const {
	return this->data;
}

uint8_t ModRMSIB::GetRmBits(bool R, bool B) const {
	if (R) {
		if (B) {
			return GET_BITS(this->data, MODRM_RM_BIT_RB, MODRM_RM_MASK_RB);
		} else {
			return GET_BITS(this->data, MODRM_RM_BIT_R, MODRM_RM_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, MODRM_RM_BIT_B, MODRM_RM_MASK_B);
		} else {
			return GET_BITS(this->data, MODRM_RM_BIT, MODRM_RM_MASK);
		}
	}
}

uint8_t ModRMSIB::GetRegBits(bool R, bool B) const {
	if (R) {
		if (B) {
			return GET_BITS(this->data, MODRM_REG_BIT_RB, MODRM_REG_MASK_RB);
		} else {
			return GET_BITS(this->data, MODRM_REG_BIT_R, MODRM_REG_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, MODRM_REG_BIT_B, MODRM_REG_MASK_B);
		} else {
			return GET_BITS(this->data, MODRM_REG_BIT, MODRM_REG_MASK);
		}
	}
}

uint8_t ModRMSIB::GetModBits(bool R, bool B) const {
	if (R) {
		if (B) {
			return GET_BITS(this->data, MODRM_MOD_BIT_RB, MODRM_MOD_MASK_RB);
		} else {
			return GET_BITS(this->data, MODRM_MOD_BIT_R, MODRM_MOD_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, MODRM_MOD_BIT_B, MODRM_MOD_MASK_B);
		} else {
			return GET_BITS(this->data, MODRM_MOD_BIT, MODRM_MOD_MASK);
		}
	}
}

uint8_t ModRMSIB::GetBaseBits(bool X, bool B) const {
	if (X) {
		if (B) {
			return GET_BITS(this->data, SIB_BASE_BIT_RB, SIB_BASE_MASK_RB);
		} else {
			return GET_BITS(this->data, SIB_BASE_BIT_R, SIB_BASE_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, SIB_BASE_BIT_B, SIB_BASE_MASK_B);
		} else {
			return GET_BITS(this->data, SIB_BASE_BIT, SIB_BASE_MASK);
		}
	}
}

uint8_t ModRMSIB::GetIndexBits(bool X, bool B) const {
	if (X) {
		if (B) {
			return GET_BITS(this->data, SIB_INDEX_BIT_RB, SIB_INDEX_MASK_RB);
		} else {
			return GET_BITS(this->data, SIB_INDEX_BIT_R, SIB_INDEX_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, SIB_INDEX_BIT_B, SIB_INDEX_MASK_B);
		} else {
			return GET_BITS(this->data, SIB_INDEX_BIT, SIB_INDEX_MASK);
		}
	}
}

uint8_t ModRMSIB::GetScaleBits(bool X, bool B) const {
	if (X) {
		if (B) {
			return GET_BITS(this->data, SIB_SCALE_BIT_RB, SIB_SCALE_MASK_RB);
		} else {
			return GET_BITS(this->data, SIB_SCALE_BIT_R, SIB_SCALE_MASK_R);
		}
	} else {
		if (B) {
			return GET_BITS(this->data, SIB_SCALE_BIT_B, SIB_SCALE_MASK_B);
		} else {
			return GET_BITS(this->data, SIB_SCALE_BIT, SIB_SCALE_MASK);
		}
	}
}