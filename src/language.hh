#pragma once
#include "_components.hh"

namespace Forth {
	struct Language_Components;
	typedef bool (*BuiltIn_Function)(Language_Components&);
	struct Language_Components {
		std::vector <int32_t>                      stack;
		std::unordered_map <std::string, BuiltIn_Function> dictionary;
	};
	Language_Components Init();
};
