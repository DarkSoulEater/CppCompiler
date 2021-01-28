//
// Created by eleno on 27.01.2021.
//

#ifndef CPPCOMPILER_TOKEN_H
#define CPPCOMPILER_TOKEN_H
#include <string>

enum class TokenType {
  ReservedWrold,
  Operator,
  ID,
  Const
};

struct Token {
  TokenType type;
  std::string data;

  Token(TokenType type, const char *data) : type(type), data(data) {}
};

#endif //CPPCOMPILER_TOKEN_H