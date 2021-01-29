#include <string>

int f(std::string s) {
  return 0;
}

int g(const char* s) {
  return 1;
}

#include "LexicalAnalyzer.h"
//#define a i
//#define b a

int main() {
  //a+b;
  LexicalAnalyzer lexical_analyzer("C:\\Users\\eleno\\CLionProjects\\CppCompiler\\input.txt");
  //LexicalAnalyzer lexical_analyzer("\\nput.txt");
  lexical_analyzer.NextToken();
  return 0;
  std::string s = "s";
  f("a");
  f(s);
  g("a");
  g(s.c_str());
  int a = 2;
  a += 4;
  a += 2;
  int b = 0;
  b += a + 1;
  return 0;
}
