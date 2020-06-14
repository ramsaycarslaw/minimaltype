// Copyright 2020 Ramsay Carslaw

#ifndef _MT_TOKEN_H_
#define _MT_TOKEN_H_

#include <stdlib.h>

enum _TokenType {
  INST,
  NUMBER,
};

enum _TokenInst {
  PUSH,
  ADD,
  HLT,
};
typedef enum _TokenInst TokenInst;

/* Token is an implementation of the token data structure.
 It contains data, which refers to it's value in the source code.
Type is the type within MT's type system and line is it's place in
the source text*/
struct _Token {
  int data;
  int type;
  int line;
};
typedef struct _Token Token;

/* create_token is used to initialise a new pointer to the type Token */
Token* token_create(int type, int data, int line);

/* token_destroy free's the memory ascociated with the token */
void token_destroy(Token * tok);

/* TokenList is a cointaner for an array of *Tokens, it also contians
 a pointer to the list and the size of the list, both stored as int's*/
struct _TokenList {
  Token **data;
  int ptr;
  int size;
};
typedef struct _TokenList TokenList;

/* token_list_create is the constructor function for a TokenList */
void token_list_create(TokenList* list, int size);

/* token_list_add adds a Token pointer to the token list */
void token_list_add(TokenList* list, Token* tok);

/* token_list_get returns the token at the given index in the
 given TokenList*/
Token* token_list_get(TokenList* list, int index);

/* token_list_destroy free's the memory ascociated with a token list */
void token_list_destroy(TokenList* list);

#endif // _MT_TOKEN_H
