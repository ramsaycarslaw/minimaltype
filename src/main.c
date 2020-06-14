// Copyright 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/token.h"
#include "../include/parser.h"
#include "../include/compiler.h"

int main(int argc, char **argv) {
  if (argc <3) {
    printf("ERROR: too few arguments...\n");
    return 1;
  }

  if (strcmp(argv[1], "build") == 0) {
    char * source = read_file(argv[2]);

    TokenList tokens;
    token_list_create(&tokens, 1);

    ParserStatus pstat = parser_start(&tokens, source);
    if (pstat != PARSER_SUCCESS) {
      return 1;
    }

    Compiler compiler;
    compiler.tokens = &tokens;
    compiler_start(&compiler);
    if (compiler.status != COMPILER_SUCCESS) {
      return 1;
    }

    write_binary_file("out.mtc", compiler.bytecode);

    byte_buffer_destroy(compiler.bytecode);
    token_list_destroy(&tokens);
    free(source);
  }

  return 0;
}
