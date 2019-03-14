# Makefile-Maker //created 13/03/2019
A small simple program that creates makefiles automatically 

Repository includes:

-source code makefileMK.c 
-a linux executable (maker)
-an example makefile that was made with the program about itshelf

NOTES:
1) The program takes one parameter only (the wanted name for the final executable)
2) The names of the project files can be given manually after (with .c extention)
3) The proposed way to give the project file names is with: ls *c | ./maker myprog
4) You can change the compiler or the compilation flags from the #defines

Features to add:
1) Make it optional to give a parameter that makes the makefile create an executable with name a.out or a default defined one

Known bugs:
1) None for now :))
