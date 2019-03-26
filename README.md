# Makefile-Maker //created 13/03/2019
A small simple program that creates makefiles automatically 

How to use:
1) compile the source file makefileMK.c with gcc -o maker makefileMK.c
2) run the program with ./maker myprog (myprog=your programs desired name)
3) write down all the names of the .c files of your project that you would like to add to your makefile
WITH .c in the end, for example  test.c 
4) After you write them all down press enter to go to a new line and then control+D to give EOF signal and end the program
5) Your makefile should be ready! Test with command make

6) Bonus if your system does not have an alias set for ls to ls -l you can save yourself from writing down the names by
making sure that there are no .c files that you dont want to your makefile in the folder you are working in and then use the command
ls *c | ./make myprog

Repository includes:
1) Source code makefileMK.c 
2) An example makefile that was made with the program about itshelf
3) A video tutorial on how to download and set up the makefile maker from windows to linux

Notes:
1) The program takes one parameter only (the wanted name for the final executable)
2) The names of the project files can be given manually after (with .c extention)
3) The proposed way to give the project file names is with: ls *c | ./maker myprog
(IMPORTANT: if like di's pcs your linux machine has set as alias for ls => ls -l the program 
WILL FAIL, so in this case you should follow the other method of writitng down the names yourself)
4) You can change the compiler or the compilation flags from the #defines

Features to add:
1) Make it optional to give a parameter that makes the makefile create an executable with name a.out or a default defined one

Known bugs:
1) When the program runs with ls -l  it throws segmentation fault since its not expecting any string that does not end with .c
(not exacly a bug ik)
