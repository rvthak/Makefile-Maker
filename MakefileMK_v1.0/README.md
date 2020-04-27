+ Dev list:

1) Rewrite the program in c++
2) Change the final executable name to mfmk for simplicity
3) Turn the final release into a .deb package to make installation easier
and make the program executable from any directory
4) Add a select all files choice
5) Store the "makefile template text" in a file and get the needed strings 
using functions for better upgradeability (or think of a cleaner way)
6) When the program runs always check if make + the selected compiler are
installed in the system
7) If a makefile already exists on the current directory, the program will ask
if the user wants to edit the existing one or make a new one ( add the ability 
to parse an already existing makefile)
8) In case user gives only one parameter (not a flag) it is considered the 
(-n) name
9) Make it built a whole directory list with subdirs with lists...
to model the whole filesystem structure below the targeted directory
and be able to get the files it needs ( deside exactly the cases + 
"formats/structures" that can be used) ?


+ Parameters:

   Parameter | Correct input format |  Parameter type  | Default value 
1)    -n     |       -n name        |      string      |     a.out
2)    -f     |       -f cpp         |      string      |      cpp
3)    -h     |       -h  h          |      string      |      hpp
4)    -c     |       -c g++         |      string      |      g++
5)    -db    |       -db            |      boolean     |     false
6)    -vg    |       -vg            |      boolean     |     false
7)    -dir   |       -dir           |      boolean     |     false
8)    -p     |       -p             |      boolean     |     false
9)    -org   |       -org           |      boolean     |     false


+ Parameter description and functionality:
1) (-n)		Set the name of the final executable 
2) (-f)		Set the format of the targeted source files
3) (-h)     Set the format of the targeted header files
4) (-c)		Set the compiler of choice
5) (-db)	Enable debugging on the final makefile
6) (-vg)	Enable valgrind on the final makefile
7) (-dir)	The program will also search sub-directories for files
8) (-p)		Enables parameter mode. The program will later ask the user to
type-in any needed parameters 
9) (-org)	The system will organise all selected files in folders
source files in ./source, header files in ./include and object files
in ./bin ( final executable + makefile will stay in the parent directory)


! Disclaimer ! To mess with the parameters, some basic c/c++ knowledge is 
advised. This program was developed for pesonal use, so if configured 
incorrectly it will not work.
