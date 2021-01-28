//
// Created by eleno on 27.01.2021.
//

#include "LexicalAnalyzer.h"

#include <iostream>

LexicalAnalyzer::LexicalAnalyzer(const char* path) {}

Token LexicalAnalyzer::NextToken() {
  std::cout << "Begin\n";
  const char *path = "C:\\Users\\eleno\\CLionProjects\\CppCompiler\\input.txt";
  static std::ifstream input_text(path);
  if (input_text.is_open()) {
    while (!input_text.eof()) {
      char c = input_text.get();
      std::cout << int(c) << " ";
      if (isalpha(c)) {
        std::cout << "is alpha\n";
      } else {
        std::cout << "is not alpha\n";
      }
    }
  }
  return Token(TokenType::Operator, "");
}