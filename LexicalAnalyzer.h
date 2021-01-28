//
// Created by eleno on 27.01.2021.
//

#ifndef CPPCOMPILER_LEXICALANALYZER_H
#define CPPCOMPILER_LEXICALANALYZER_H

#include <fstream>
#include "Token.h"

class LexicalAnalyzer {
public:
    LexicalAnalyzer(const char* path);

    Token NextToken();

private:
  // std::ifstream input_text;
};

#endif //CPPCOMPILER_LEXICALANALYZER_H
