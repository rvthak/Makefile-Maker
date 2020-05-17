# Makefile-Maker 
A small simple program that creates simple makefiles automatically

+ Parameters:

Parameter | Correct input format |  Parameter type  | Default value 
----------|----------------------|------------------|---------------
   -n     |       -n name        |      string      |     a.out
   -f     |       -f cpp         |      string      |      cpp
   -h     |       -h hpp         |      string      |      hpp
   -c     |       -c g++         |      string      |      g++
   -db    |       -db            |      boolean     |     false
   -vg    |       -vg            |      boolean     |     false
   -p     |       -p             |      boolean     |     false
   -e     |       -e             |      boolean     |     false
   -org   |       -org           |      boolean     |     false (! -org NOT yet implemented !)
   --help |       --help

+ Installation:
1) Download zip and unzip or git clone
2) In Terminal: cd into the project directory
3) In Terminal: make install
4) You will be asked your admin privileges password to complete the installation
5) Delete the downloaded folder

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

+ Ideas/Features to add if i ever need them:
1) If a makefile already exists on the current directory, the program will ask
if the user wants to edit the existing one or make a new one ( add the ability 
to parse an already existing makefile)
2) Implement "-org"
3) When the program runs always check if make + the selected compiler are
installed in the system
4) Add -i toggle argument to enable/disable make install option

+ Created  v0.1 13/03/2019
+ Updated  v0.2 29/03/2019
+ Upgraded v1.0 16/05/2020
