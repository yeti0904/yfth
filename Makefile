cc  = g++
src = src/*.cc
arg = -std=c++17 -Wall -Wextra -Werror -pedantic
out = bin/yforth

build:
	mkdir -p bin
	$(cc) $(src) -s $(arg) -o $(out)

debug:
	mkdir -p bin
	$(cc) $(src) -g $(arg) -o $(out)
