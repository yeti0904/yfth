#include "language.hh"
#include "builtin.hh"

Forth::Language_Components Forth::Init() {
	Forth::Language_Components ret;
	ret.dictionary["+"] = BuiltIn::Add;

	return ret;
}
