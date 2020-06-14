#ifndef _MT_RUNTIME_H_
#define _MT_RUNTIME_H_

#include "./bytecode.h"
#include "./bytebuffer.h"

enum _RuntimeStatus {
  RUNTIME_SUCESS,
  RUNTIME_ERROR,
};
typedef enum _RuntimeStatus RuntimeStatus;

struct _Runtime {
  ByteBuffer* code;
  RuntimeStatus status;
};
typedef struct _Runtime Runtime;

void runtime_start(Runtime*runtime, ByteBuffer *code);

#endif  // _MT_RUNTIME_H_
