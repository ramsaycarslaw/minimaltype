// Copyright 2020 Ramsay Carslaw

#ifndef _MT_INCLUDE_UTILS_H_
#define _MT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#include "./bytebuffer.h"


char * read_file(const char *filename);

void read_binary_file(const char * filename, ByteBuffer* bb);

void write_binary_file(const char * filename, ByteBuffer* bb);


#endif // _MT_INCLUDE_UTILS_H_
