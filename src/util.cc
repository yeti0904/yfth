#include "util.hh"

bool Util::ValidateArgument(std::string arg, std::string big, std::string small) {
	return (
		(arg == big) ||
		(arg == small)
	);
}

bool Util::IsNumber(std::string str) {
	for (size_t i = 0; i<str.length(); ++i) {
		if (!(
			((str[i] >= '0') && (str[i] <= '9')) ||
			((i == 0) && (str[i] == '-'))
		)) return false;
	}
	return true;
}
