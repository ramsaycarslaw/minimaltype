// Copyright 2020 Ramsay Carslaw

#include "../include/bytebuffer.h"

ByteBuffer* byte_buffer_create(int size) {
    ByteBuffer* bytebuffer = (ByteBuffer*) malloc(sizeof(ByteBuffer));
    bytebuffer->buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);
    bytebuffer->ptr = 0;
    bytebuffer->size = size;
    return bytebuffer;
}

void byte_buffer_write8(ByteBuffer * bytebuffer, uint8_t data) {
    if (bytebuffer->ptr >= bytebuffer->size) {
        bytebuffer->size *= 2;
        bytebuffer->buffer = (uint8_t*) realloc(bytebuffer->buffer, sizeof(uint8_t) * bytebuffer->size);
    }

    bytebuffer->buffer[bytebuffer->ptr++] = data;
}
void byte_buffer_write16(ByteBuffer * bytebuffer, uint16_t data) {
    byte_buffer_write8(bytebuffer, (data & 0xFF00) >> 8);
    byte_buffer_write8(bytebuffer, (data & 0xFF));
}

void byte_buffer_write32(ByteBuffer * bytebuffer, uint32_t data) {
    byte_buffer_write8(bytebuffer, (data & 0xFF000000) >> 24);
    byte_buffer_write8(bytebuffer, (data & 0x00FF0000) >> 16);
    byte_buffer_write8(bytebuffer, (data & 0x0000FF00) >> 8);
    byte_buffer_write8(bytebuffer, (data & 0x000000FF));
}

void byte_buffer_destroy(ByteBuffer* bytebuffer) {
    free(bytebuffer->buffer);
    free(bytebuffer);
}