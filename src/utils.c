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

uint8_t* read_binary_file(const char * filename) {
  FILE *file = fopen(filename, "rb");

  if (!file) {
    printf("ERROR: Couldn't load binary file %s...", filename);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  uint8_t* buffer = (uint8_t*) malloc(sizeof(uint8_t) * size);
  fread(buffer, 1, size, file);
  fclose(file);

  return buffer;
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

uint16_t read16(uint8_t* buffer, uint32_t index) {
  return (buffer[index] << 8) | (buffer[index + 1]);
}

uint32_t read32(uint8_t* buffer, uint32_t index) {
  return (buffer[index] << 24) | (buffer[index + 1] << 16) |
      (buffer[index + 2] << 8) | (buffer[index+3]);
}
