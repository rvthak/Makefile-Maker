# Makefile-Maker //created 13/03/2019
A small simple program that creates makefiles automatically 

Repository includes:
1) Source code makefileMK.c 
2) A linux executable (maker) //compiled in ubuntu 64 bit
3) An example makefile that was made with the program about itshelf

Notes:
1) The program takes one parameter only (the wanted name for the final executable)
2) The names of the project files can be given manually after (with .c extention)
3) The proposed way to give the project file names is with: ls *c | ./maker myprog
4) You can change the compiler or the compilation flags from the #defines

Features to add:
1) Make it optional to give a parameter that makes the makefile create an executable with name a.out or a default defined one

Known bugs:
1) None for now :))
