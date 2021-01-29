//
// Created by eleno on 27.01.2021.
//

#ifndef CPPCOMPILER_LEXICALANALYZER_H
#define CPPCOMPILER_LEXICALANALYZER_H

#include "Token.h"

#include <fstream>

class LexicalAnalyzer {
 public:
  explicit LexicalAnalyzer(const char *filename);

  bool Empty();
  Token Get();

 private:
  static bool IsKeyword(const Token &);
  static bool IsPunctuator(char);
  static bool IsOperator(char);

  std::ifstream input_;
};

#endif //CPPCOMPILER_LEXICALANALYZER_H
