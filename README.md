# Makefile-Maker 
A small simple program that creates simple makefiles automatically

+ Parameters:

   Parameter | Correct input format |  Parameter type  | Default value 
1)    -n     |       -n name        |      string      |     a.out
2)    -f     |       -f cpp         |      string      |      cpp
3)    -h     |       -h hpp         |      string      |      hpp
4)    -c     |       -c g++         |      string      |      g++
5)    -db    |       -db            |      boolean     |     false
6)    -vg    |       -vg            |      boolean     |     false
7)    -p     |       -p             |      boolean     |     false
8)    -e     |       -e             |      boolean     |     false
9)    -org   |       -org           |      boolean     |     false (! -org NOT yet implemented !)
10)   --help |       --help


+ Parameter description and functionality:
1) (-n)		Set the name of the final executable 
2) (-f)		Set the format of the targeted source files
3) (-h)     Set the format of the targeted header files
4) (-c)		Set the compiler of choice
5) (-db) 	Enable debugging on the final makefile
6) (-vg)	   Enable valgrind on the final makefile
7) (-p)		Enables compiler parameter mode. The program will later ask the user to
type-in any needed parameters 
8) (-e)		Enables execution parameter mode. The program will later ask the user to
type-in any needed parameters
9) (-org)	The system will organise all selected files in folders
source files in ./source, header files in ./include and object files
in ./bin ( final executable + makefile will stay in the parent directory)
(! -org NOT yet implemented !)
10) ( --help)  Terminates Program and Prints Help

! Disclaimer ! To mess with the parameters, some basic programming knowledge is 
advised. This program was developed for pesonal use, so if configured 
incorrectly it will not work.

+ Dev list:
1) Change the final executable name to mfmk for simplicity
2) Turn the final release into a .deb package to make installation easier
and make the program executable from any directory if possible

+ Ideas/Features to add if i ever need them

1)If a makefile already exists on the current directory, the program will ask
if the user wants to edit the existing one or make a new one ( add the ability 
to parse an already existing makefile)
2) Implement "-org"
3) When the program runs always check if make + the selected compiler are
installed in the system

+ Created  v0.1 13/03/2019
+ Updated  v0.2 29/03/2019
+ Upgraded v1.0 16/05/2020
