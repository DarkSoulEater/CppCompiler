cmake_minimum_required(VERSION 3.17)
project(CppCompiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppCompiler main.cpp LexicalAnalyzer.cpp LexicalAnalyzer.h Token.h)