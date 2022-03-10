#pragma once
#include "language.hh"

namespace BuiltIn {
	void Init(Forth::Language_Components& components);
	bool Add(Forth::Language_Components& components);      // +
	bool Subtract(Forth::Language_Components& components); // -
	bool Multiply(Forth::Language_Components& components); // *
	bool Divide(Forth::Language_Components& components);   // /
	bool Mod(Forth::Language_Components& components);      // mod
	bool PrintInt(Forth::Language_Components& components); // .
	bool Emit(Forth::Language_Components& components);     // emit
	bool Dup(Forth::Language_Components& components);      // dup
	bool Drop(Forth::Language_Components& components);     // drop
	bool Cr(Forth::Language_Components& components);       // CR
	bool I(Forth::Language_Components& components);        // i
};
