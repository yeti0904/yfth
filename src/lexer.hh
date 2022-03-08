#pragma once
#include "_components.hh"

namespace Lexer {
	enum class TokenType {
		Word = 0,
		Integer
	};
	struct Token {
		TokenType   type;
		std::string content;
	};
	std::vector <Token> Lex(std::string code);
};
