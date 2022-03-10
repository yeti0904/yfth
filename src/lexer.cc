#include "lexer.hh"
#include "util.hh"

void AddToken(std::string& reading, std::vector <Lexer::Token>& ret) {
	Lexer::Token add;
	if (Util::IsNumber(reading)) {
		add.type    = Lexer::TokenType::Integer;
		add.content = reading;
	}
	else {
		add.type    = Lexer::TokenType::Word;
		for (size_t i = 0; i<reading.length(); ++i) {
			if ((reading[i] >= 'A') && (reading[i] <= 'Z')) {
				reading[i] = tolower(reading[i]);
			}
		}
		add.content = reading;
	}
	ret.push_back(add);
	reading = "";
}

std::vector <Lexer::Token> Lexer::Lex(std::string code) {
	std::vector <Lexer::Token> ret;
	std::string                reading;

	for (size_t i = 0; i<code.length(); ++i) {
		switch (code[i]) {
			case '\n':
			case '\t':
			case ' ': {
				if (reading != "")
					AddToken(reading, ret);
				break;
			}
			default: {
				reading += code[i];
				break;
			}
		}
	}
	if (reading != "")
		AddToken(reading, ret);
	
	return ret;
}
