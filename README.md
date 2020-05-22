# Makefile-Maker 
( At the moment, it works on small projects that have all their files in a single directory )

## Argument list:

Argument  |     Correct Usage    |   Argument Meaning    |  Argument type  | Default value 
----------|----------------------|-----------------------|-----------------|---------------
   -n     |       -n name        |        Set name          |     string      |     a.out
   -f     |       -f cpp         |  Set source files format  |     string      |      cpp
   -h     |       -h hpp         |  Set header files format  |     string      |      hpp
   -c     |       -c g++         |      Set compiler        |     string      |      g++
   -db    |       -db            |      gdb toggle       |     boolean     |     true
   -vg    |       -vg            |    valgrind toggle    |     boolean     |     true
   -i     |       -i             |   make install toggle       |     boolean     |     true
   -p     |       -p             |  Compilation argument toggle|     boolean     |     false
   -e     |       -e             |   Execution argument  toggle|     boolean     |     false
   --help |       --help         |    Print Help
   --version|     --version      |    Print Version

  ###(Compilation/Execution toggle will ask the user for the parameters later)

## Installation:
1) Download zip and unzip or git clone
2) cd into the project directory
3) make install
4) You will be asked your admin privileges password to complete the installation
5) Delete the downloaded folder
6) You can now run the program from your project's directory with: mkfl

### Installation Example: (In terminal)
    git clone https://github.com/rvthak/Makefile-Maker.git
    cd Makefile-Maker
    make install
    #(program installation asks for your password and finishes)
    cd ..
    rm -rf Makefile-Maker/

! __Important Note__ ! To mess with the parameters, some basic programming knowledge is 
advised. This program was developed for pesonal use, so if configured 
incorrectly it will not work.

## Ideas/Features to add if i ever need them:
1) If a makefile already exists on the current directory, the program will ask
if the user wants to edit the existing one or make a new one ( add the ability 
to parse an already existing makefile)
2) Implement "-org" The system will organise all selected files in folders
source files in ./source, header files in ./include and object files
in ./bin ( final executable + makefile will stay in the parent directory)
3) When the program runs always check if make + the selected compiler are
installed in the system
4) Add -i toggle argument to enable/disable make install option
5) Add a --version argument

+ Created  v0.1 13/03/2019
+ Updated  v0.2 29/03/2019
+ Upgraded v1.0 16/05/2020
