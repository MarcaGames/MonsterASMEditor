/* A	-> A far pointer encoded in the instruction. No ModRM byte in the instruction encoding. */
/* B	-> General-purpose register specified by the VEX or XOP vvvv field. */
/* C	-> Control register specified by the ModRM.reg field. */
/* D	-> Debug register specified by the ModRM.reg field. */
/* E	-> General purpose register or memory operand specified by the r/m field of the ModRM byte. For memory operands, the ModRM byte may be followed by a SIB byte to specify one of the indexed register-indirect addressing forms. */
/* F	-> rFlags register. */
/* G	-> General purpose register specified by the ModRM.reg field. */
/* H	-> YMM or XMM register specified by the ModRM.reg field. */
/* I	-> Immediate value encoded in the instruction immediate field. */
/* J	-> The instruction encoding includes a relative offset that is added to the rIP. */
/* L	-> YMM or XMM register specified using the most-significant 4 its of an 8-bit immediate value. */
/* M	-> A memory operand specified by the { mod, r/m } field of the ModRM byte. ModRM.mod != 11b. */
/* M*	-> A sparse array of memory operands addressed using the VSIB addressing mode. */
/* N	-> 64-bit MMX register specified by the ModRM.r/m field. The ModRM.mod field must be 11b. */
/* O	-> The offset of an operand is encoded in the instruction. There is no ModRM byte in the instruction encoding. Indexed register-indirect addressing using the SIB byte is not supported. */
/* P	-> 64-bit MMX register specified by the ModRM.reg field. */
/* Q	-> 64-bit MMX-register or memory operand specified by the { mod, r/m } field of the ModRM byte. For memory operands, the ModRM byte may be followed by a SIB byte to specify one of the indexed register-indirect addressing forms. */
/* R -> General purpose register specified by the ModRM.r/m field. The ModRM.mod field must be 11b. */
/* S -> Segment register specified by the ModRM.reg field. */
/* U -> YMM/XMM register specified by the ModRM.r/m field. The ModRM.mod field must be 11b. */
/* V -> YMM/XMM register specified by the ModRM.reg field. */
/* W -> YMM/XMM register or memory operand specified by the { mod, r/m } field of the ModRM byte. For memory operands, the ModRM byte may be followed by a SIB byte to specify one of the indexed register-indirect addressing forms. */
/* X -> A memory operand addressed by the DS.rSI registers. Used in string instructions. */
/* Y -> A memory operand addressed by the ES.rDI registers. Used in string instructions. */

/* a -> Two 16-bit or 32-bit memory operands, depending on the effective operand size. Used in the BOUND instruction. */
/* b -> A byte, irrespective of the effective operand size. */
/* c -> A byte or a word, depending on the effetive operand size. */
/* d -> A doubleword (32 bits), irrespective of the effective operand size. */
/* do -> A double octword (256 bits), irrespective of the effective operand size. */
/* i -> A 16-bit integer. */
/* j -> A 32-bit integer. */
/* m -> A bit mask of size equal to the source operand. */
/* mn -> Where n = 2,4,8 or 16. A bit mask of size n. */
/* o -> An octword (128 bits), irrespective of the effective operand size. */
/* o.q -> Operand is either the upper or lower half of a 128-bit value. */
/* p -> A 32- or 48-bit far pointer, depending on 16- or 32-bit effective operand size. */
/* pb -> Vector with byte-wide (8-bit) elements (packed byte). */
/* pd -> A double-precision (64-bit) floating-point vector operand (packed double-precision). */
/* pdw -> Vector composed of 32-bit doublewords. */
/* ph -> A half-precision (16-bit) floating-point vector operand (packed half-precision). */
/* pi -> Vector composed of 16-bit integers (packed integer). */
/* pj -> Vector composed of 32-bit integers (packed double integer). */
/* pk -> Vector composed of 8-bit integers (packed half-word integer). */
/* pq -> Vector composed of 64-bit integers (packed quadword integer). */
/* pqw -> Vector composed of 64-bit quadwords (packed quadword). */
/* ps -> A single-precision floating-point vector operand (packed single-precision). */
/* pw -> Vector composed of 16-bit words (packed word). */
/* q -> A quadword (64-bits), irrespective of the effective operand size. */
/* s -> A 6-byte or 10-byte pseudo-descriptor. */
/* sd -> A scalar double-precision floating-point operand (scalar double). */
/* sj -> A scalar doubleword (32-bit) integer operand (scalar double integer). */
/* ss -> A scalar single-precision floating-point operand (scalar single). */
/* v -> A word, doubleword, quadword (int 64-bit mode), depending on the effective operand size. */
/* w -> A word, irrespective of the effective operand size. */
/* x -> Instruction supports both vector sizes (128 bits or 256 bits). Size is encoded using the VEX/XOP.L field. (L=0: 128 bits; L=1: 256 bits). This symbol may be appended to ps or pd to represent a packed single- or double-precision float-point vector of either size; or to pk,pi,pj, or pq, to represent a packet 8-bit, 16-bit, 32-bit, or 64-bit packed integer vector of either size. */
/* y -> A doubleword or quadword depending on effective operand size. */
/* z -> A word if the effective operand size is 16 bits, or a doubleword if the effective operand size is 32 or 64-bits. */

/* /n -> A ModRM-byte reg field or SIB-byte base field, where n is a value between zero (000b) and 7 (111b). */

/* 0x00	ADD Eb, Gb										*/
/* 0x01	ADD Ev, Gv										*/
/* 0x02	ADD Gb, Eb										*/
/* 0x03	ADD Gv, Ev										*/
/* 0x04	ADD AL, Ib										*/
/* 0x05	ADD rAX, Iz										*/
/* 0x06	PUSH ES											*/
/* 0x07	POP ES											*/
/* 0x08	OR Eb, Gb										*/
/* 0x09	OR Ev, Gv										*/
/* 0x0A	OR Gb, Eb										*/
/* 0x0B	OR Gv, Ev										*/
/* 0x0C	OR AL, Ib										*/
/* 0x0D	OR rAX, Iz										*/
/* 0x0E	PUSH CS											*/
/* 0x0F	ESCAPE											*/
/* 0x10	ADC Eb, Gb										*/
/* 0x11	ADC Ev, Gv										*/
/* 0x12	ADC Gb, Eb										*/
/* 0x13	ADC Gv, Ev										*/
/* 0x14	ADC AL, Ib										*/
/* 0x15	ADC rAX, Iz										*/
/* 0x16	PUSH SS											*/
/* 0x17	POP SS											*/
/* 0x18	SBB Eb, Gb										*/
/* 0x19	SBB Ev, Gv										*/
/* 0x1A	SBB Gb, Eb										*/
/* 0x1B	SBB Gv, Ev										*/
/* 0x1C	SBB AL, Ib										*/
/* 0x1D	SBB rAX, Iz										*/
/* 0x1E	PUSH DS											*/
/* 0x1F	POP DS											*/
/* 0x20	AND Eb, Gb										*/
/* 0x21	AND Ev, Gv										*/
/* 0x22	AND Gb, Eb										*/
/* 0x23	AND Gv, Ev										*/
/* 0x24	AND AL, Ib										*/
/* 0x25	AND rAX, Iz										*/
/* 0x26	SEG ES											*/
/* 0x27	DAA												*/
/* 0x28	SUB Eb, Gb										*/
/* 0x29	SUB Ev, Gv										*/
/* 0x2A	SUB Gb, Eb										*/
/* 0x2B	SUB Gv, Ev										*/
/* 0x2C	SUB AL, Ib										*/
/* 0x2D	SUB rAX, Iz										*/
/* 0x2E	SEG CS											*/
/* 0x2F	DAS												*/
/* 0x30	XOR Eb, Gb										*/
/* 0x31	XOR Ev, Gv										*/
/* 0x32	XOR Gb, Eb										*/
/* 0x33	XOR Gv, Ev										*/
/* 0x34	XOR AL, Ib										*/
/* 0x35	XOR rAX, Iz										*/
/* 0x36	SEG SS											*/
/* 0x37	AAA												*/
/* 0x38	CMP Eb, Gb										*/
/* 0x39	CMP Ev, Gv										*/
/* 0x3A	CMP Gb, Eb										*/
/* 0x3B	CMP Gv, Ev										*/
/* 0x3C	CMP AL, Ib										*/
/* 0x3D	CMP rAX, Iz										*/
/* 0x3E	SEG DS											*/
/* 0x3F	AAS												*/
/* 0x40	INC eAX / REX prefix							*/
/* 0x41	INC eCX / REX prefix							*/
/* 0x42	INC eDX / REX prefix							*/
/* 0x43	INC eBX / REX prefix							*/
/* 0x44	INC eSP / REX prefix							*/
/* 0x45	INC eBP / REX prefix							*/
/* 0x46	INC eSI / REX prefix							*/
/* 0x47	INC eDI / REX prefix							*/
/* 0x48	DEC eAX / REX prefix							*/
/* 0x49	DEC eCX / REX prefix							*/
/* 0x4A	DEC eDX / REX prefix							*/
/* 0x4B	DEC eBX / REX prefix							*/
/* 0x4C	DEC eSP / REX prefix							*/
/* 0x4D	DEC eBP / REX prefix							*/
/* 0x4E	DEC eSI / REX prefix							*/
/* 0x4F	DEC eDI / REX prefix							*/
/* 0x50	PUSH rAX/r8										*/
/* 0x51	PUSH rCX/r9										*/
/* 0x52	PUSH rDX/r10									*/
/* 0x53	PUSH rBX/r11									*/
/* 0x54	PUSH rSP/r12									*/
/* 0x55	PUSH rBP/r13									*/
/* 0x56	PUSH rSI/r14									*/
/* 0x57	PUSH rDI/r15									*/
/* 0x58	POP rAX/r8										*/
/* 0x59	POP rCX/r9										*/
/* 0x5A	POP rDX/r10										*/
/* 0x5B	POP rBX/r11										*/
/* 0x5C	POP rSP/r12										*/
/* 0x5D	POP rBP/r13										*/
/* 0x5E	POP rSI/r14										*/
/* 0x5F	POP rDI/r15										*/
/* 0x60	PUSHA / PUSHAD									*/
/* 0x61	POPA / POPAD									*/
/* 0x62	BOUND Gv, Ma									*/
/* 0x63	ARPL Ew, Gw / MOVSXD Gv, Ez						*/
/* 0x64	SEG FS Prefix									*/
/* 0x65	SEG GS Prefix									*/
/* 0x66	Operand Size Override Prefix					*/
/* 0x67	Address Size Override Prefix					*/
/* 0x68	PUSH Iz											*/
/* 0x69	IMUL Gv, Ev, Iz									*/
/* 0x6A	PUSH Ib											*/
/* 0x6B	IMUL Gv, Ev, Ib									*/
/* 0x6C	INSB Yb, Dx										*/
/* 0x6D	INSW Yz, Dx / INSD Yz, Dx						*/
/* 0x6E	OUTS Dx, Xb / OUTSB Dx, Xb						*/
/* 0x6F	OUTS Dx, Xz / OUTSW Dx, Xz / OUTSD Dx, Xz		*/
/* 0x70	JO Jb											*/
/* 0x71	JNO Jb											*/
/* 0x72	JB Jb											*/
/* 0x73	JNB Jb											*/
/* 0x74	JZ Jb											*/
/* 0x75	JNZ Jb											*/
/* 0x76	JBE Jb											*/
/* 0x77	JNBE Jb											*/
/* 0x78	JS Jb											*/
/* 0x79	JNS Jb											*/
/* 0x7A	JP Jb											*/
/* 0x7B	JNP Jb											*/
/* 0x7C	JL Jb											*/
/* 0x7D	JNL Jb											*/
/* 0x7E	JLE Jb											*/
/* 0x7F	JNLE Jb											*/
/* 0x80	Group 1 Eb, Ib									*/
/* 0x81	Group 1 Ev, Iz									*/
/* 0x82	Group 1	Eb, Ib									*/
/* 0x83	Group 1	Ev, Ib									*/
/* 0x84	TEST Eb, Gb										*/
/* 0x85	TEST Ev, Gv										*/
/* 0x86	XCHG Eb, Gb										*/
/* 0x87	XCHG Ev, Gv										*/
/* 0x88	MOV Eb, Gb										*/
/* 0x89	MOV	Ev, Gv										*/
/* 0x8A	MOV Gb, Eb										*/
/* 0x8B	MOV Gv, Ev										*/
/* 0x8C	MOV Mw/Rv, Sw									*/
/* 0x8D	LEA Gv, M										*/
/* 0x8E	MOV Sw, Ew										*/
/* 0x8F	Group 1a / XOP escape prefix					*/
/* 0x90	XCHG r8, rAX, NOP, PAUSE						*/
/* 0x91	XCHG rCX/r9, rAX								*/
/* 0x92	XCHG rDX/r10, rAX								*/
/* 0x93	XCHG rBX/r11, rAX								*/
/* 0x94	XCHG rSP/r12, rAX								*/
/* 0x95	XCHG rBP/r13, rAX								*/
/* 0x96	XCHG rSI/r14, rAX								*/
/* 0x97	XCHG rDI/r15, rAX								*/
/* 0x98	CBW / CWDE / CDQE								*/
/* 0x99	CWD / CDQ / CQO									*/
/* 0x9A	CALL Ap											*/
/* 0x9B	WAIT / FWAIT									*/
/* 0x9C	PUSHF Fv / PUSHD Fv / PUSHQ Fv					*/
/* 0x9D	POPF Fv / POPD Fv / POPQ Fv						*/
/* 0x9E	SAHF											*/
/* 0x9F	LAHF											*/
/* 0xA0	MOV	AL, Ob										*/
/* 0xA1	MOV	rAX, Ov										*/
/* 0xA2	MOV Ob, AL										*/
/* 0xA3	MOV	Ov, rAX										*/
/* 0xA4	MOVSB Yb, Xb									*/
/* 0xA5	MOVSW Yv, Xv / MOVSD Yv, Xv / MOVSQ Yv Xv		*/
/* 0xA6	CMPSB Xb, Yb									*/
/* 0xA7	CMPSW Xv, Yv / CMPSD Xv, Yv / CMPSQ Xv, Yv		*/
/* 0xA8	TEST AL, Ib										*/
/* 0xA9	TEST rAX, Iz									*/
/* 0xAA	STOSB Yb, AL									*/
/* 0xAB	STOSW Yv, rAX / STOSD Yv, rAX / STOSQ Yv, rAX	*/
/* 0xAC	LODSB AL, xB									*/
/* 0xAD	LODSW rAX, Xv / LODSD rAX, Xv / LODSQ rAX, Xv	*/
/* 0xAE	SCASB AL, Yb									*/
/* 0xAF	SCASW rAX, Yv / SCASD rAX, Yv / SCASQ rAX, Yv	*/
/* 0xB0	MOV AL/r8b, Ib									*/
/* 0xB1	MOV CL/r9b, Ib									*/
/* 0xB2	MOV DL/r10b, Ib									*/
/* 0xB3	MOV BL/r11b, Ib									*/
/* 0xB4	MOV AH/r12b, Ib									*/
/* 0xB5	MOV CH/r13b, Ib									*/
/* 0xB6	MOV DH/r14b, Ib									*/
/* 0xB7	MOV BH/r15b, Ib									*/
/* 0xB8	MOV rAX/r8, Iv									*/
/* 0xB9	MOV rCX/r9, Iv									*/
/* 0xBA	MOV rDX/r10, Iv									*/
/* 0xBB	MOV rBX/r11, Iv									*/
/* 0xBC	MOV rSP/r12, Iv									*/
/* 0xBD	MOV rBP/r13, Iv									*/
/* 0xBE	MOV rSI/r14, Iv									*/
/* 0xBF	MOV rDI/r15, Iv									*/
/* 0xC0	Group 2	Eb, Ib									*/
/* 0xC1	Group 2	Ev, Ib									*/
/* 0xC2	RET near Iw										*/
/* 0xC3	RET near										*/
/* 0xC4	LES Gz, Mp / VEX escape prefix					*/
/* 0xC5	LDS Gz, Mp / VEX escape prefix					*/
/* 0xC6	Group 11 Eb, Ib									*/
/* 0xC7	Group 11 Ev, Iz									*/
/* 0xC8	ENTER Iw, Ib									*/
/* 0xC9	LEAVE											*/
/* 0xCA	RET far Iw										*/
/* 0xCB	RET far											*/
/* 0xCC	INT3											*/
/* 0xCD	INT Ib											*/
/* 0xCE	INTO											*/
/* 0xCF	IRET / IRETD / IRETQ							*/
/* 0xD0	Group 2 Eb, 1									*/
/* 0xD1	Group 2 Ev, 1									*/
/* 0xD2	Group 2 Eb, CL									*/
/* 0xD3	Group 2 Ev, CL									*/
/* 0xD4	AAM Ib											*/
/* 0xD5	AAD Ib											*/
/* 0xD6	Invalid											*/
/* 0xD7	XLAT / XLATB									*/
/* 0xD8	x87 instructions								*/
/* 0xD9	x87 instructions								*/
/* 0xDA	x87 instructions								*/
/* 0xDB	x87 instructions								*/
/* 0xDC	x87 instructions								*/
/* 0xDD	x87 instructions								*/
/* 0xDE	x87 instructions								*/
/* 0xDF	x87 instructions								*/
/* 0xE0	LOO-PNE / LOO-NZJb								*/
/* 0xE1	LOOPE Jb / LOOPZ Jb								*/
/* 0xE2	LOOP Jb											*/
/* 0xE3	JrCXZ Jb										*/
/* 0xE4	IN AL, Ib										*/
/* 0xE5	IN eAX, Ib										*/
/* 0xE6	OUT Ib, AL										*/
/* 0xE7	OUT Ib, eAX										*/
/* 0xE8	CALL Jz											*/
/* 0xE9	JMP Jz											*/
/* 0xEA	JMP Ap											*/
/* 0xEB	JMP Jb											*/
/* 0xEC	IN AL, DX										*/
/* 0xED	IN eAX, DX										*/
/* 0xEE	OUT DX, AL										*/
/* 0xEF	OUT DX, eAX										*/
/* 0xF0	LOCK Prefix										*/
/* 0xF1	INT1											*/
/* 0xF2	REPNE Prefix									*/
/* 0xF3	REP Prefix / REPE Prefix						*/
/* 0xF4	HLT												*/
/* 0xF5	CMC												*/
/* 0xF6	Group 3 Eb										*/
/* 0xF7	Group 3 Ev										*/
/* 0xF8	CLC												*/
/* 0xF9	STC												*/
/* 0xFA	CLI												*/
/* 0xFB	STI												*/
/* 0xFC	CLD												*/
/* 0xFD	STD												*/
/* 0xFE	Group 4 Eb										*/
/* 0xFF	Group 5											*/