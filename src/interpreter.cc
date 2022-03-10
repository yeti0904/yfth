#include "interpreter.hh"

bool Interpret(std::vector <Lexer::Token> tokens, Forth::Language_Components& components) {
	for (size_t i = 0; i<tokens.size(); ++i) {
		switch (tokens[i].type) {
			case Lexer::TokenType::Integer: {
				int32_t push;
				try {
					push = std::stoi(tokens[i].content);
				}
				catch (...) {
					printf("Error pushing integer %s\n", tokens[i].content.c_str());
					exit(0);
				}
				components.stack.push_back(push);
				break;
			}
			case Lexer::TokenType::Word: {
				// hardcoded words (lol)
				if (tokens[i].content == ".\"") {
					// print string
					for (++i; i<tokens.size(); ++i) {
						if (tokens[i].content[tokens[i].content.length() - 1] == '"') {
							printf("%s", tokens[i].content.substr(0, tokens[i].content.length() - 1).c_str());
							break;
						}
						else
							printf("%s ", tokens[i].content.c_str());
					}
					break;
				}
				if (tokens[i].content == "do") {
					if (components.stack.size() < 1) {
						printf("Stack underflow");
						return false;
					}
					size_t num = 1;
					std::vector <Lexer::Token> loopTokens;
					for (++i; i<tokens.size(); ++i) {
						if (tokens[i].type == Lexer::TokenType::Word) {
							if (tokens[i].content == "do")   ++ num;
							if (tokens[i].content == "loop") -- num;
						}
						if (num == 0)
							break;
						else
							loopTokens.push_back(tokens[i]);
					}
					int32_t incStart = components.stack[components.stack.size() - 1];
					int32_t incMax   = components.stack[components.stack.size() - 2];
					components.stack.pop_back();
					components.stack.pop_back();
					for (int32_t i = incStart; i<incMax; ++i) {
						components.iterator = i;
						if (!Interpret(loopTokens, components))
							return false;
					}
					break;
				}
				if (components.dictionary[tokens[i].content] != NULL) {
					if (!components.dictionary[tokens[i].content](components)) {
						return false;
					}
					break;
				}
				printf("\nWord '%s' not recognised\n", tokens[i].content.c_str());
				return false;
				break;
			}
		}
	}
	return true;
}
