#include <iostream>
#include "makefileS.hpp"
#include "input.hpp"
#include "output.hpp"

using namespace std;

int main(int argc, char const **argv){

	Makefile mk;
	InputManager(argc, argv, mk);
	SystemInput(mk);
	Output(mk);
	return 0;
}
