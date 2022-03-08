#include "interpreter.hh"

bool Interpret(std::vector <Lexer::Token> tokens, Forth::Language_Components& components) {
	for (size_t i = 0; i<tokens.size(); ++i) {
		switch (tokens[i].type) {
			case Lexer::TokenType::Integer: {
				components.stack.push_back(std::stoi(tokens[i].content));
				break;
			}
			case Lexer::TokenType::Word: {
				if (components.dictionary[tokens[i].content] != NULL)
					components.dictionary[tokens[i].content](components);
				break;
			}
		}
	}
	return true;
}
