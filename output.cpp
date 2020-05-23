#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "output.hpp"

using namespace std;

// Support Functions - Keep them local
// They add the corresponding text to the makefile
string mkflBody(void);			// Adds main body
string mkflInst(void);			// Adds install segment
string mkflDB(void);			// Adds gdb
string mkflVal(bool dbflag);	// Adds valgrind
string mkflClean(void);			// Adds Clean

void Output(Makefile &mk){
	// Safely Create the output file
	ofstream file;
	file.open("makefile");
	if(!file.is_open()){
		cout << " (!) Fatal Error: Failed to create makefile. Exiting.. " << endl;
		exit(1);
	}

	// Write the Makefile info 
	file << "OUT=" << mk.getName() << endl;
	file << "OBJS=" << mk.getFileList() << endl;
	file << "CXX=" << mk.getCompiler() << endl;

	if(mk.getCompParam()){
		file << "CXXFLAGS=" << mk.getCompParamList() << endl;
	}
	else{
		file << "CXXFLAGS=" << endl;
	}

	if(mk.getExecParam()){
		file << "EXECUTION_PARAMETERS=" << mk.getExecParamList() << endl;
	}
	else{
		file << "EXECUTION_PARAMETERS=" << endl;
	}
	
	// Write Body + any other part
	file << mkflBody();

	if(mk.getInstall()){
		file << mkflInst();
	}

	if(mk.getDebug()){
		file << mkflDB();
	}

	if(mk.getValgrind()){
		file << mkflVal(mk.getDebug());
	}

	file << mkflClean();

	file.close();
	return;
}

string mkflBody(void){
	string buf;
	buf+="\nall: $(OUT)\n\n";
	buf+="$(OUT): $(OBJS)\n";
	buf+="\t$(CXX) -o $(OUT) $(OBJS)\n\n";
	buf+="%.o: %.c\n";
	buf+="\t$(CXX) -c -o $@ $<\n\n";
	buf+="run: $(OUT)\n";
	buf+="\t./$(OUT) $(EXECUTION_PARAMETERS)\n\n";
	return buf;
}

string mkflInst(void){
	string buf;
	buf+="\ninstall: $(OUT)\n";
	buf+="\tsudo cp $(OUT) /usr/local/bin\n";
	buf+="\t@echo Program Installed in /usr/local/bin\n";
	buf+="\t@echo You can now delete this folder safely\n\n";
	return buf;
}

string mkflDB(void){
	string buf;
	buf+="db: clean param\n";
	buf+="param: CXXFLAGS += -g\n";
	buf+="param: $(OUT)\n\n";
	buf+="gdb: db\n";
	buf+="\tgdb $(OUT)\n\n";
	return buf;
}

string mkflVal(bool dbflag){
	string buf;

	if(!dbflag){
		buf+="db: clean param\n";
		buf+="param: CXXFLAGS += -g\n";
		buf+="param: $(OUT)\n\n";
	}
	
	buf+="vg: db\n";
	buf+="\tvalgrind $(EXECUTION_PARAMETERS) ./$(OUT)\n\n";

	buf+="vgleak: db\n";
	buf+="\tvalgrind --leak-check=full ./$(OUT) $(EXECUTION_PARAMETERS)\n\n";

	buf+="vgext: db\n";
	buf+="\tvalgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(OUT) $(EXECUTION_PARAMETERS)\n\n";

	return buf;
}

string mkflClean(void){
	string buf;

	buf+=".PHONY: clean\n";
	buf+="clean:\n";
	buf+="\trm -f *.o\n";
	
	return buf;
}
