// Copyright 2020 Ramsay Carslaw

#ifndef _MT_BYTEBUFFER_H_
#define _MT_BYTEBUFFER_H_

#include <stdlib.h>
#include <stdint.h>

struct _ByteBuffer {
    uint8_t* buffer;
    int ptr;
    int size;
};
typedef struct _ByteBuffer ByteBuffer;

ByteBuffer* byte_buffer_create(int size);
void byte_buffer_write8(ByteBuffer * bytebuffer, uint8_t data);
void byte_buffer_write16(ByteBuffer * bytebuffer, uint16_t data);
void byte_buffer_write32(ByteBuffer * bytebuffer, uint32_t data);
void byte_buffer_destroy(ByteBuffer* bytebuffer);

#endif // _MT_BYTEBUFFER_H_