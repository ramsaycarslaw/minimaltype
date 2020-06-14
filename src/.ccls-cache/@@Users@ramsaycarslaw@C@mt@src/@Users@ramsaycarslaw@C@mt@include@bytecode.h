// Copyright 2020 Ramsay Carslaw

#ifndef _MT_BYTECODE_H_
#define _MT_BYTECODE_H_

enum _Opcode {
    NOP = 0x00,
    PUSH_CONST = 0x01,
    ADD_STACK = 0x02,
    HLT_OP = 0xFF,
};

#endif // _MT_BYTECODE_H_