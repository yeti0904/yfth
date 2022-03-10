#include "builtin.hh"

void BuiltIn::Init(Forth::Language_Components& components) {
	components.dictionary["+"]    = BuiltIn::Add;
	components.dictionary["-"]    = BuiltIn::Subtract;
	components.dictionary["*"]    = BuiltIn::Multiply;
	components.dictionary["/"]    = BuiltIn::Divide;
	components.dictionary["."]    = BuiltIn::PrintInt;
	components.dictionary["emit"] = BuiltIn::Emit;
	components.dictionary["dup"]  = BuiltIn::Dup;
	components.dictionary["drop"] = BuiltIn::Drop;
	components.dictionary["cr"]   = BuiltIn::Cr;
	components.dictionary["i"]    = BuiltIn::I;
}

bool BuiltIn::Add(Forth::Language_Components& components) { // +
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 1];
	int32_t num2 = components.stack[components.stack.size() - 2];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 + num2);
	return true;
}

bool BuiltIn::Subtract(Forth::Language_Components& components) { // -
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 2];
	int32_t num2 = components.stack[components.stack.size() - 1];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 - num2);
	return true;
}

bool BuiltIn::Multiply(Forth::Language_Components& components) { // +
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 1];
	int32_t num2 = components.stack[components.stack.size() - 2];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 * num2);
	return true;
}

bool BuiltIn::Divide(Forth::Language_Components& components) { // -
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 2];
	int32_t num2 = components.stack[components.stack.size() - 1];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 / num2);
	return true;
}

bool BuiltIn::Mod(Forth::Language_Components& components) { // -
	if (components.stack.size() < 2) {
		printf("Stack underflow\n");
		return false;
	}
	int32_t num1 = components.stack[components.stack.size() - 2];
	int32_t num2 = components.stack[components.stack.size() - 1];

	components.stack.pop_back();
	components.stack.pop_back();

	components.stack.push_back(num1 % num2);
	return true;
}

bool BuiltIn::PrintInt(Forth::Language_Components& components) { // .
	if (components.stack.size() < 1) {
		printf("Stack underflow");
		return false;
	}
	printf("%i", components.stack[components.stack.size() - 1]);
	components.stack.pop_back();
	return true;
}

bool BuiltIn::Emit(Forth::Language_Components& components) {
	if (components.stack.size() < 1) {
		printf("Stack underflow");
		return false;
	}
	putchar(components.stack[components.stack.size() - 1]);
	components.stack.pop_back();
	return true;
}

bool BuiltIn::Dup(Forth::Language_Components& components) {
	if (components.stack.size() < 1) {
		printf("Stack underflow");
		return false;
	}
	components.stack.push_back(components.stack[components.stack.size() - 1]);
	return true;
}

bool BuiltIn::Drop(Forth::Language_Components& components) {
	if (components.stack.size() < 1) {
		printf("Stack underflow");
		return false;
	}
	components.stack.pop_back();
	return true;
}

bool BuiltIn::Cr(Forth::Language_Components& components) {
	(void)components;
	printf("\r\n");
	return true;
}

bool BuiltIn::I(Forth::Language_Components& components) {
	components.stack.push_back(components.iterator);
	return true;
}
