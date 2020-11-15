#pragma once

#include <stdint.h>

struct REX {
public:
	uint8_t GetData() const;

	uint8_t GetBBits() const;
	uint8_t GetXBits() const;
	uint8_t GetRBits() const;
	uint8_t GetWBits() const;

public:
	uint8_t data;
};

struct RXBMap_select {
public:
	uint8_t GetData() const;

	uint8_t GetMapSelectBits() const;
	uint8_t GetBBits() const;
	uint8_t GetXBits() const;
	uint8_t GetRBits() const;

public:
	uint8_t data;
};

struct XvvvvLpp {
public:
	uint8_t GetData() const;

	uint8_t GetppBits() const;
	uint8_t GetLBits() const;
	uint8_t GetvvvvBits() const;
	uint8_t GetWBits() const;
	uint8_t GetRBits() const;

public:
	uint8_t data;
};

struct ModRMSIB {
public:
	inline uint8_t GetData() const;

	/// <param name="R">REX.R, VEX.R or XOP.R</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetRmBits(bool R = false, bool B = false) const;
	/// <param name="R">REX.R, VEX.R or XOP.R</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetRegBits(bool R = false, bool B = false) const;
	/// <param name="R">REX.R, VEX.R or XOP.R</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetModBits(bool R = false, bool B = false) const;

	/// <param name="R">REX.X, VEX.X or XOP.X</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetBaseBits(bool X = false, bool B = false) const;
	/// <param name="R">REX.X, VEX.X or XOP.X</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetIndexBits(bool X = false, bool B = false) const;
	/// <param name="R">REX.X, VEX.X or XOP.X</param>
	/// <param name="B">REX.B, VEX.B or XOP.B</param>
	uint8_t GetScaleBits(bool X = false, bool B = false) const;

public:
	uint8_t data;
};