#include "builtin.hh"

bool BuiltIn::Add(Forth::Language_Components& components) {
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 1];
	int32_t num2 = components.stack[components.stack.size() - 2];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 + num2);
	printf("hi\n");
	return true;
}
