# Makefile-Maker // created 13/03/2019 - last updated 29/03/2019
A small simple program that creates makefiles automatically 

How to use:
1) Compile the object file makefileMKv0_2.o with: gcc -o maker makefileMKv0_2.o
2) Move the source file to your project directory
3) Run the program with: ./maker myprog (myprog=your desired program's final executable name)
5) Your makefile should be ready! Test with command: make
6) Whenever you need clean up with: make clean

Notes:
1) The program takes one parameter only (the wanted name for the final executable)
if you dont give any parameter or give more the program will use the default name a.out
2) Haven't tried the program in a 32 bit system

Features to add:
1) Add c++ support

Known bug/problems:
1) Some problems when strange input is given
