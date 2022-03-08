#include "_components.hh"
#include "util.hh"
#include "lexer.hh"
#include "fs.hh"
#include "interpreter.hh"
#include "language.hh"

int main(int argc, char** argv) {
	std::vector <std::string> args;
	for (size_t i = 0; i < (size_t)argc; ++i) {
		args.push_back(argv[i]);
	}

	// settings
	bool        lexerDebug = false;
	bool        stackDebug = false;
	std::string sourceFile;

	for (size_t i = 0; i<args.size(); ++i) {
		if (args[i][0] == '-') {
			if (Util::ValidateArgument(args[i], "--lexer-debug", "-ld")) {
				lexerDebug = !lexerDebug;
				printf("Note: lexer debug is %s\n", lexerDebug? "on": "off");
			}
			if (Util::ValidateArgument(args[i], "--stack-debug", "-sd")) {
				stackDebug = !stackDebug;
				printf("Note: stack debug is %s\n", stackDebug? "on": "off");
			}
		}
		else {
			sourceFile = args[i];
		}
	}

	std::string sourceCode = FS::Read(sourceFile);

	std::vector <Lexer::Token> tokens = Lexer::Lex(sourceCode);

	if (lexerDebug) {
		for (size_t i = 0; i<tokens.size(); ++i) {
			if (tokens[i].type == Lexer::TokenType::Word) {
				printf("(Word at %d) '%s'\n", (int) i, tokens[i].content.c_str());
			}
			else if (tokens[i].type == Lexer::TokenType::Integer) {
				printf("(Integer at %d) '%s'\n", (int) i, tokens[i].content.c_str());
			}
		}
		return 0;
	}

	// interpret
	Forth::Language_Components components;
	bool ok = Interpret(tokens, components); // line 53
	if (!ok) {
		printf("FAIL");
		return 1;
	}
	if (stackDebug) {
		for (size_t i = 0; i<components.stack.size(); ++i) {
			printf(" %05d | %d\n", (int) i, components.stack[i]);
			return 0;
		}
	}

	return 0;
}
