#include <string>
#include <limits>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "input.hpp"

using namespace std;

// Supported Arguments
#define NAME_A "-n"
#define FRMT_A "-f"
#define HEAD_A "-h"
#define COMP_A "-c"
#define DEBG_A "-db"
#define VALG_A "-vg"
#define PARM_A "-p"
#define EXEC_A "-e"
#define ORGN_A "-org"
#define HELP_A "--help"

// Support Functions - Keep them local
int HandleParameter(int &count, int &argc, char const **argv, Makefile &mk); // Gets a parameter and updates the Makefile (Used only from InputManager())
void changeFormat(string &str, const string frm); 	// Change the str String file format to frm
bool getDesision(const string msg); 				// Print the msg question and return a binary answer


void InputManager(int argc, char const **argv, Makefile &mk){

	// No parameters
	if(argc==1){ printf(" (i) > No arguments given using defaults..\n"); return; }
	
	// Only one parameter => use it as a name
	else if(argc==2){ 
		if( argv[1][0]!='-' ){
			printf(" (i) > Only one argument given. Using '%s' as a Name\n", argv[1]);
			mk.setName(argv[1]);
			return;
		}
	}

	// More than one parameter
	int count=1; // Start from 2nd argument
	argc=argc-1; // Use argc as a total counter

	while(count<=argc){
		// HandleParameter changes count for ease
		if( HandleParameter(count, argc, argv, mk)!=0 ){ exit(1); } 
	}

	// Compilation Parameter read mode
	if(mk.getCompParam()){ mk.readCompParam(); }

	// Execution Parameter read mode
	if(mk.getExecParam()){ mk.readExecParam(); }

	return;
}

int HandleParameter(int &count, int &argc, char const **argv, Makefile &mk){
	string param=argv[count];

	if(param.at(0)!='-'){
		cout << " \n(!) User Input Error: illegal argument. Exiting..." << endl;
		printInputFormat();
		return 1;
	}

	if(!param.compare(HELP_A)){
		printInputFormat();
		return 1;
	}
	else if(!param.compare(NAME_A)){
		if( count == argc || argv[count+1][0]=='-' ){
			cout << " \n(!) User Input Error: name missing. Exiting..." << endl;
			printInputFormat();
			return 1;
		}
		string tmp=argv[count+1];
		mk.setName(tmp);
		count+=2;
	}
	else if(!param.compare(FRMT_A)){
		if( count == argc || argv[count+1][0]=='-'){
			cout << " \n(!) User Input Error: source format missing. Exiting..." << endl;
			printInputFormat();
			return 1;
		}
		string tmp=argv[count+1];
		mk.setFormat(tmp);
		count+=2;
	}
	else if(!param.compare(HEAD_A)){
		if( count == argc || argv[count+1][0]=='-'){
			cout << " \n(!) User Input Error: header format missing. Exiting..." << endl;
			printInputFormat();
			return 1;
		}
		string tmp=argv[count+1];
		mk.setHeader(tmp);
		count+=2;
	}
	else if(!param.compare(COMP_A)){
		if( count == argc || argv[count+1][0]=='-'){
			cout << " \n(!) User Input Error: compiler missing. Exiting..." << endl;
			printInputFormat();
			return 1;
		}
		string tmp=argv[count+1];
		mk.setCompiler(tmp);
		count+=2;
	}
	else if(!param.compare(DEBG_A)){
		if(mk.getDebug()){
			mk.setDebug(0);
		}
		else{
			mk.setDebug(1);
		}
		count++;
	}
	else if(!param.compare(VALG_A)){
		if(mk.getValgrind()){
			mk.setValgrind(0);
		}
		else{
			mk.setValgrind(1);
		}
		count++;
	}
	else if(!param.compare(PARM_A)){
		if(mk.getCompParam()){
			mk.setCompParam(0);
		}
		else{
			mk.setCompParam(1);
		}
		count++;
	}
	else if(!param.compare(EXEC_A)){
		if(mk.getExecParam()){
			mk.setExecParam(0);
		}
		else{
			mk.setExecParam(1);
		}
		count++;
	}
	else if(!param.compare(ORGN_A)){
		if(mk.getOrganize()){
			mk.setOrganize(0);
		}
		else{
			mk.setOrganize(1);
		}
		count++;
	}
	else{
		cout << " \n(!) User Input Error: given argument does not exist. Exiting..." << endl;
		printInputFormat();
		return 1;
	}

	return 0;
}

void printInputFormat(void){
	printf("\n          ------ Argument Format ------ \n // Default values on ()\n");
	printf(" >> Set Executable Name:     -n < name (a.out) >\n");
	printf(" >> Set Source file Format:  -f < source file format (.cpp) >\n");
	printf(" >> Set Header file Format:  -h < header file format (.hpp) >\n");
	printf(" >> Set Compiler:            -c < compiler name (g++) >\n");
	printf(" >> Toggle gdb:                     -db  (1)\n");
	printf(" >> Toggle valgrind:                -vg  (1)\n");
	printf(" >> Toggle compilation parameters:  -p   (0)\n");
	printf(" >> Toggle execution parameters:    -e   (0)\n");
	printf(" >> Toggle auto project organizer:  -org (0)\n");
	printf(" >> Print help:                     --help\n");
	
	printf("\n (i)> The <...> fields are REQUIRED right after their corresponding parameter\n");
	printf(" (i)> Rogue Strings and Non-Supported parameters will cause termination\n");
	printf(" (i)> Give Format by writing just the last chars (example: file.c => -f c) \n");
	return;
}

void SystemInput(Makefile &mk){
	string buf, tmp;
	printf(" => Searching for files in current directory...\n");
	printf(" > Files found:\n");

	// Get the files found in a temporary file
	string str="find *.";
	str+=mk.getFormat();
	str+=">mkfl.tmp";
	system(str.c_str());

	// Safely open tmp file
	ifstream file;
	file.open("mkfl.tmp");
	if(!file.is_open()){ cout << " Fatal Error: Failed to read files" <<endl; exit(1); }

	// Print available files if any
	file >> tmp;
	if( file.eof()){
		cout << " (!) No files found in the set format. Terminating..." << endl;
		file.close();
		exit(1);
	}
	while(!file.eof()){
		cout << "    " << tmp << endl;
		file >> tmp;
	}

	// return to beginning of file
	file.clear();
	file.seekg(0, ios::beg);

	// Add all files to list
	if( getDesision(" (i) Select all? (y/n)")){
		file >> tmp;
		while(!file.eof()){
			changeFormat(tmp, "o");
			buf+=tmp;
			buf+=" ";
			file >> tmp;
		}
	}
	else{
		// Let the user choose files one by one (maybe implement a toggle mode where you choose by numbers)
		cout << " (i) Select the ones to add: " << endl;
		file >> tmp;
		while(!file.eof()){
			cout << tmp;
			if( getDesision("\t: add? (y/n)") ){
				changeFormat(tmp, "o");
				buf+=tmp;
				buf+=" ";
			}
			file >> tmp;
		}

	}
	//cout << " (i) Buf: " << buf << endl;
	mk.setFileList(buf);

	// Close and delete the tmp file
	file.close();
	system("rm -f mkfl.tmp");
	return;
}

bool getDesision(const string msg){
	string str;
	cout << msg << ": ";
	
	while(1){
		cout << " ";
		cin >> str;

		if (cin.fail()){
	    	cin.clear(); 
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << " > Wrong input try again: (y/n)" << endl;
    	}
		else if(str=="y"){
			cin.get();
			return 1;
		}
		else if(str=="n"){
			cin.get();
			return 0;
		}
		else{
			cout << " > Wrong input try again: (y/n)" << endl;
		}
	}
}

void changeFormat(string &str, const string frm){
	int pos=str.find_last_of(".");
	int len=str.length() - pos;
	str.erase(pos+1, len);
	str+=frm;
}