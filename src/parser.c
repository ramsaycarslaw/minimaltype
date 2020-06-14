// Copyright 2020 Ramsay Carslaw

#include "../include/parser.h"

ParserStatus parser_start(TokenList *list, const char * source) {
  char lex[256];
  int lexi = 0;
  int i = 0;
  int line = 1;

  while (1) {
    // memset(lex, 0, 256);

    while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0') {
      lex[lexi++] = source[i++];
    }

    lex[lexi] = '\0';

    Token token;

    //TODO care about empty lines
    //TODO care about tabs

    // must be numerical constant
    if (lex[0] == '#') {
      int num = parser_get_number(lex);
      //printf("Number: %d\n", num);
      token_create(&token, NUMBER, num, line);
      token_list_add(list, token);
    }

    // Must be an instruction
    else {
      int inst = parser_get_inst(lex);
      if (inst >= 0) {
          //printf("Instruction: %s\n", lex);
          token_create(&token, INST, inst, line);
          token_list_add(list, token);
        } else {
            printf("ERROR: no such instruction %s at %d\n", lex, line);
            return PARSER_SYNTAX_ERROR;
        }
    }

    if (source[i] == '\n') {
      line++;
    } else if (source[i] == '\0') {
      break;
    }

    lexi = 0;
    i++;
  }
  return PARSER_SUCCESS;
}

uint32_t parser_get_number(const char *buf) {
  long num = atoi(&buf[1]);
  return (num <= UINT32_MAX) ? num : 0;
}

TokenInst parser_get_inst(const char *buf) {
  if (strcmp(buf, "push") == 0) {
    return PUSH;
  } else if (strcmp(buf, "add") == 0) {
    return ADD;
  } else if (strcmp(buf, "hlt") == 0) {
    return HLT;
  }
  return (TokenInst) - 1;
}