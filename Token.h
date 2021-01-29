//
// Created by eleno on 27.01.2021.
//

#ifndef CPPCOMPILER_TOKEN_H
#define CPPCOMPILER_TOKEN_H

#include <string>

struct Token {
  enum class Type { KEYWORD, IDENTIFIER, CONSTANT, STRING_LITERAL, PUNCTUATOR, OPERATOR, OTHER };
  Type name;
  std::string value;
};

#endif //CPPCOMPILER_TOKEN_H
