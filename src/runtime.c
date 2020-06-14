// Copyright 2020 Ramsay Carslaw

#include "../include/runtime.h"


void runtime_start(Runtime *runtime) {
  runtime->sp = -1;
  runtime->pc = 0;
  runtime->exit = 123;
  runtime->running = true;

  while (runtime->running) {
    switch (runtime->code[runtime->pc++]) {

      // PUSH #N -> push to stack
      case PUSH_CONST: {
        push32(runtime, read32(runtime->code, runtime->pc));
        runtime->pc += 4;
        break;
      }

      // ADD
      case ADD_STACK: {
        uint32_t a = pop32(runtime);
        uint32_t b = pop32(runtime);
        push32(runtime, a + b);
        break;
      }

        // HLT
      case HLT_OP: {
        runtime->exit = (uint8_t) pop32(runtime);
        runtime->status = RUNTIME_SUCESS;
        runtime->running = false;
        break;
      }
    }
  }
}

void push8(Runtime *r, uint8_t data) {
  r->stack[++r->sp] = data;
}

void push16(Runtime *r, uint16_t data) {
  push8(r, (data & 0xFF00) >> 8);
  push8(r, (data & 0x00FF));
}

void push32(Runtime *r, uint32_t data) {
  push8(r, (data & 0xFF000000) >> 24);
  push8(r, (data & 0x00FF0000) >> 16);
  push8(r, (data & 0x0000FF00) >> 8);
  push8(r, (data & 0x000000FF));
}

uint8_t pop8(Runtime *r) {
  return r->stack[r->sp--];
}

uint16_t pop16(Runtime *r) {
  uint8_t b = pop8(r);
  uint8_t a = pop8(r);
  return (a << 8) | b;
}

uint32_t pop32(Runtime *r) {
  uint8_t d = pop8(r);
  uint8_t c = pop8(r);
  uint8_t b = pop8(r);
  uint8_t a = pop8(r);
  return (d << 24) | (c << 16) | (b << 8) | a;
}


