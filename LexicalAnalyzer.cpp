//
// Created by eleno on 27.01.2021.
//

#include "LexicalAnalyzer.h"

#include <iostream>
#include <unordered_set>

LexicalAnalyzer::LexicalAnalyzer(const char* filename) : input_(filename) {
  if (!input_) {
    throw std::logic_error("could not open the file");
  }
  while (input_.peek() == ' ' || input_.peek() == '\n') {
    input_.ignore();
  }
}

bool LexicalAnalyzer::Empty() {
  return input_.peek() == std::ifstream::traits_type::eof();
}

Token LexicalAnalyzer::Get() {
  Token token;
  if (isalpha(input_.peek()) || input_.peek() == '_') {
    do {
      token.value.push_back(input_.get());
    } while (isalpha(input_.peek()) || input_.peek() == '_' || isdigit(input_.peek()));
    token.name = IsKeyword(token) ? Token::Type::KEYWORD : Token::Type::IDENTIFIER;
  } else if (isdigit(input_.peek())) {
    do {
      token.value.push_back(input_.get());
    } while (isdigit(input_.peek()));
    token.name = Token::Type::CONSTANT;
  } else if (input_.peek() == '"') {
    input_.ignore();
    do {
      token.value.push_back(input_.get());
      if (Empty()) {
        token.name = Token::Type::OTHER;
        return token;
      }
    } while (input_.peek() != '"');
    input_.ignore();
    token.name = Token::Type::STRING_LITERAL;
  } else if (input_.peek() == '\'') {
    input_.ignore();
    do {
      token.value.push_back(input_.get());
      if (Empty()) {
        token.name = Token::Type::OTHER;
        return token;
      }
    } while (input_.peek() != '\'');
    input_.ignore();
    token.name = Token::Type::STRING_LITERAL;
  } else if (IsPunctuator(input_.peek())) {
    token.value.push_back(input_.get());
    token.name = Token::Type::PUNCTUATOR;
  } else if (IsOperator(input_.peek())) {
    token.value.push_back(input_.get());
    if (IsOperator(input_.peek())) {
      token.value.push_back(input_.get());
    }
    token.name = Token::Type::OPERATOR;
  } else {
    while (input_.peek() != ' ' && input_.peek() != '\n') {
      token.value.push_back(input_.get());
    }
    token.name = Token::Type::OTHER;
  }
  while (input_.peek() == ' ' || input_.peek() == '\n') {
    input_.ignore();
  }
  return token;
}

bool LexicalAnalyzer::IsKeyword(const Token &token) {
  static const std::unordered_set<std::string> keywords{
      "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
      "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr",
      "constinit", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
      "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for",
      "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
      "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
      "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch",
      "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union",
      "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
  };
  return keywords.find(token.value) != keywords.end();
}

bool LexicalAnalyzer::IsPunctuator(char c) {
  static const std::unordered_set<char> punctuators{
      '{', '}', '(', ')', ',', ';', '[', ']'
  };
  return punctuators.find(c) != punctuators.end();
}

bool LexicalAnalyzer::IsOperator(char c) {
  static const std::unordered_set<char> operators{
      '+', '-', '*', '/', '>', '=', '<', '?', '%', '!', '~', '&', '|', '^', '.', ':'
  };
  return operators.find(c) != operators.end();
}
