// Copyright 2020 Ramsay Carslaw

#include "../include/utils.h"

char *read_file(const char* filename) {
  // create a file pointer to filename
  FILE* file = fopen(filename, "r");

  // check file pointer exists
  if (!file) {
    printf("ERROR: could not open file %s...\n", filename);
    return NULL;
  }

  // get file size
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // read file
  char *buf = malloc(sizeof(char) * (size + 1));
  fread(buf, 1, size, file);
  buf[size]= '\0';
  fclose(file);

  return buf;
}

void read_binary_file(const char * filename, ByteBuffer *bb) {
  FILE *file = fopen(filename, "rb");

  if (!file) {
    printf("ERROR: Couldn't load binary file %s...", filename);
  }

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  uint8_t buffer[size];
  fread(buffer, 1, size, file);
  fclose(file);

  for (int i = 0; i < size; i++) {
    byte_buffer_write8(bb, buffer[i]);
  }
}

void write_binary_file(const char * path, ByteBuffer* bb) {
  FILE* file = fopen(path, "wb");

  if (!file) {
    printf("ERROR: could not write to binary file %s...\n", path);
    return;
  }

  fwrite(bb->buffer, 1, bb->ptr, file);
  fclose(file);
}
