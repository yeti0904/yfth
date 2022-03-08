#pragma once
#include "lexer.hh"
#include "language.hh"

bool Interpret(std::vector <Lexer::Token> tokens, Forth::Language_Components& components);
