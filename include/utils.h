// Copyright 2020 Ramsay Carslaw

#ifndef _MT_INCLUDE_UTILS_H_
#define _MT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "./bytebuffer.h"


char * read_file(const char *filename);

uint8_t* read_binary_file(const char * filename);

void write_binary_file(const char * filename, ByteBuffer* bb);

uint16_t read16(uint8_t* buffer, uint32_t index);
uint32_t read32(uint8_t* buffer, uint32_t index);

#endif // _MT_INCLUDE_UTILS_H_
