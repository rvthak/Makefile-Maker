# Makefile-Maker 
// Created 13/03/2019 - Updated to Version 0.2 at 29/03/2019

// Started working on a new version 1.0, update coming

A small simple program that creates simple makefiles automatically 

How to use:
1) Compile the object file makefileMKv0_2.o with: gcc -o maker makefileMKv0_2.o
2) Move the source file to your project directory
3) Run the program with: ./maker myprog (myprog=your desired program's final executable name)
5) Your makefile should be ready! Test with command: make
6) Whenever you need clean up with: make clean
7) If you are having problems understanding the previous steps download and watch the tutorial.mp4 video
8) In case you come across any issues/bugs feel free to contact me

Notes:
1) The program currently takes one parameter only (the wanted name for the final executable)
if you dont give any parameter or give more the program will use the default name a.out

Features to add: (coming with next update)
1) Add c++ support (choose compiler as a parameter)
2) Add the choice to add source files from sub-directories to the makefile
3) Add the choice to also give compilation parameters without the need to edit the makefile manually

Known bug/issues
1) Some problems when strange input is given ( will probably be fixed with next update )
