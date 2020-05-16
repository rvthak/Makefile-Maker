#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "makefileS.hpp"

using namespace std;

int main(int argc, char const **argv){

	// Create a Makefile with default values
	Makefile mk;

	// Parse the user arguments and update Makefile values
	InputManager(argc, argv, mk);

	// Get a list of files from the targeted directory
	SystemInput(mk);

	// Create and write the actual makefile
	Output(mk);

	return 0;
}
