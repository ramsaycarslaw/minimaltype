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
