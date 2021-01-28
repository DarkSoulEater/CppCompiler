//
// Created by eleno on 28.01.2021.
//

#ifndef CPPCOMPILER__SYNTACTICANALYZER_H_
#define CPPCOMPILER__SYNTACTICANALYZER_H_

#include "LexicalAnalyzer.h"

class SyntacticAnalyzer {
  SyntacticAnalyzer();

 private:
  LexicalAnalyzer lexical_analyzer_;
};

#endif //CPPCOMPILER__SYNTACTICANALYZER_H_
