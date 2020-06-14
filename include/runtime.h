#ifndef _MT_RUNTIME_H_
#define _MT_RUNTIME_H_

#include <stdbool.h>
#include <stdint.h>

#include "./bytecode.h"
#include "./utils.h"

// maximum size of runtime stack
#define STACK_SIZE 1024

enum _RuntimeStatus {
  RUNTIME_SUCESS,
  RUNTIME_ERROR,
};
typedef enum _RuntimeStatus RuntimeStatus;

struct _Runtime {
  uint8_t* code;
  RuntimeStatus status;
  uint8_t stack[STACK_SIZE];
  uint32_t sp;  // stack pointer
  uint32_t pc;  // program counter
  uint8_t exit;
  bool running;
};
typedef struct _Runtime Runtime;

void runtime_start(Runtime*runtime);

// runtime stack functions

void push8(Runtime *r, uint8_t data);
void push16(Runtime *r, uint16_t data);
void push32(Runtime *r, uint32_t data);

uint8_t pop8(Runtime *r);
uint16_t pop16(Runtime *r);
uint32_t pop32(Runtime *r);

#endif  // _MT_RUNTIME_H_
