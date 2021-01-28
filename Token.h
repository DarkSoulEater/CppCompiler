//
// Created by eleno on 27.01.2021.
//

#ifndef CPPCOMPILER_TOKEN_H
#define CPPCOMPILER_TOKEN_H
#include <string>

struct Token {
  std::string type;
  std::string data;

  Token(const char *type, const char *data) : type(type), data(data) {}
};

#endif //CPPCOMPILER_TOKEN_H