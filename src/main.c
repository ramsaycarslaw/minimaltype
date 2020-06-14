// Copyright 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/token.h"
#include "../include/parser.h"

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

    // TODO remove for loop for debug
    for (int i = 0; i < tokens.ptr; i++) {
      Token* t = token_list_get(&tokens, i);
      printf("%d, %d, %d\n", t->type, t->data, t->line);
    }

    token_list_destroy(&tokens);
    free(source);
  }

  return 0;
}
