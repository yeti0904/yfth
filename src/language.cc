#include "language.hh"

Forth::Language_Components Forth::Init() {
	Forth::Language_Components ret;
	ret.iterator = 0;

	return ret;
}
