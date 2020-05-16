#ifndef INPUT
#define INPUT

#include "makefileS.hpp"

void InputManager(int argc, char const **argv, Makefile &mk);
void SystemInput(Makefile &mk);
void printInputFormat(void); // --help

#endif