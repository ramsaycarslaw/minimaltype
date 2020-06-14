// Copyright 2020 Ramsay Carslaw

#ifndef _MT_COMPILER_H_
#define _MT_COMPILER_H_

#include <stdio.h>

#include "./token.h"
#include "./bytebuffer.h"
#include "./bytecode.h"

enum _CompilerStatus {
    COMPILER_SUCCESS,
    COMPILER_ERROR,
};
typedef enum _CompilerStatus CompilerStatus;

struct _Compiler {
    CompilerStatus status;
    TokenList* tokens;
    ByteBuffer* bytecode;
};
typedef struct _Compiler Compiler;

void compiler_start(Compiler* c);

#endif // _MT_COMPILER_H_
