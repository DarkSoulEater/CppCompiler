#include "LexicalAnalyzer.h"

#include <iostream>

int main(int argc, char *argv[]) {
  LexicalAnalyzer lexical_analyzer(argv[1]);
  while (!lexical_analyzer.Empty()) {
    auto token = lexical_analyzer.Get();
    std::cout << token.value << " - " << static_cast<int>(token.name) << '\n';
  }
}
