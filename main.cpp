#include "LexicalAnalyzer.h"

#include <iostream>

int main(int argc, char *argv[]) {
  LexicalAnalyzer lexical_analyzer(argv[1]);
  while (!lexical_analyzer.Empty()) {
    auto token = lexical_analyzer.Get();
    std::cout << token.value << " - ";
    switch (static_cast<int>(token.name)) {
      case 0: std::cout << "KEYWORD";
        break;
      case 1: std::cout << "IDENTIFIER";
        break;
      case 2: std::cout << "CONSTANT";
        break;
      case 3: std::cout << "STRING_LITERAL";
        break;
      case 4: std::cout << "PUNCTUATOR";
        break;
      case 5: std::cout << "OPERATOR";
        break;
      case 6: std::cout << "OTHER";
        break;
    }
    std::cout << '\n';
  }
}
