// Copyright 2020 Ramsay Carslaw

#include "../include/compiler.h"

void compiler_start(Compiler* c) {
    c->bytecode = byte_buffer_create(1);

    for (int i = 0; i < c->tokens->ptr; i++) {
        Token *t = token_list_get(c->tokens, i);

        if (t->type == INST) {
            switch (t->data)
            {
            // Push
            case PUSH: {
                // Push #N
                if (token_list_get(c->tokens, i + 1)->type == NUMBER) {
                    byte_buffer_write8(c->bytecode, PUSH_CONST);
                    byte_buffer_write32(c->bytecode, token_list_get(c->tokens, i + 1)->data);
                    i++;
                } else {
                    printf("ERROR: Bad push instruction...\n");
                    c->status = COMPILER_ERROR;
                    return;
                }
                break;
            }

            // ADD
            case ADD: {
                byte_buffer_write8(c->bytecode, ADD_STACK);
                break;
            }
            // HLT
            case HLT: {
                byte_buffer_write8(c->bytecode, HLT_OP);
                break;
            }

            default: {
                printf("ERROR: what the actual hell have you done?\n");
                c->status = COMPILER_ERROR;
                break;
            }
            }
        }
    }
    c->status = COMPILER_SUCCESS;
}