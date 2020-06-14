// Copyright 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../include/utils.h"
#include "../include/token.h"
#include "../include/parser.h"
#include "../include/compiler.h"
#include "../include/runtime.h"

int main(int argc, char **argv) {
  // have we got the correct arguments
  if (argc <3) {
    printf("ERROR: too few arguments...\n");
    return 1;
  }

  // build setting
  if (strcmp(argv[1], "build") == 0) {
    char * source = read_file(argv[2]);

    TokenList tokens;
    token_list_create(&tokens, 1);

    // create a new parser and parse
    ParserStatus pstat = parser_start(&tokens, source);
    // check no syntax errors
    if (pstat != PARSER_SUCCESS) {
      return 1;
    }

    // create a new compiler and compile the source tree
    Compiler compiler;
    compiler.tokens = &tokens;
    compiler_start(&compiler);
    if (compiler.status != COMPILER_SUCCESS) {
      return 1;
    }

    // WRITE executable
    write_binary_file("out.mtc", compiler.bytecode);

    // free all the memory ro avoid leaks later
    byte_buffer_destroy(compiler.bytecode);
    token_list_destroy(&tokens);
    free(source);

    return 0;
  } else if (strcmp(argv[1], "run") == 0) {
    ByteBuffer bb;
    read_binary_file(argv[2], &bb);

    Runtime runtime;
    runtime_start(&runtime, &bb);

    if (runtime.status == RUNTIME_ERROR) {
      return 1;
    }

    return 0;
  }

  return 1;
}
