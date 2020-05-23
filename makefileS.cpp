#include <iostream>
#include "makefileS.hpp"

using namespace std;

// Default Data member values
#define NAME "a.out"
#define FRMT "cpp"
#define HEAD "hpp"
#define COMP "g++"
#define DEBG 1
#define VALG 1
#define INST 1
#define PARM 0
#define EXEC 0
#define ORGN 0


Makefile::Makefile(){
	Name=NAME;
	Compiler=COMP;
	SourceFormat=FRMT;
	HeaderFormat=HEAD;
	debugEnable=DEBG;
	valgrindEnable=VALG;
	installEnable=INST;
	parameterEnable=PARM;
	execParamEnable=EXEC;
	organizeEnable=ORGN;
}

Makefile::Makefile(const Makefile &mkfl){
	Name=mkfl.Name;
	Compiler=mkfl.Compiler;
	SourceFormat=mkfl.SourceFormat;
	HeaderFormat=mkfl.HeaderFormat;
	debugEnable=mkfl.debugEnable;
	valgrindEnable=mkfl.valgrindEnable;
	installEnable=mkfl.installEnable;
	parameterEnable=mkfl.parameterEnable;
	execParamEnable=mkfl.execParamEnable;
	organizeEnable=mkfl.organizeEnable;
}

std::string Makefile::getName(void)const{ return Name; }
std::string Makefile::getCompiler(void)const{ return Compiler; }
std::string Makefile::getFormat(void)const{ return SourceFormat; }
std::string Makefile::getHeader(void)const{ return HeaderFormat; }
bool Makefile::getDebug(void)const{ return debugEnable; }
bool Makefile::getValgrind(void)const{ return valgrindEnable; }
bool Makefile::getInstall(void)const{ return installEnable; }
bool Makefile::getCompParam(void)const{ return parameterEnable; }
bool Makefile::getExecParam(void)const{ return execParamEnable; }
bool Makefile::getOrganize(void)const{ return organizeEnable; }
std::string Makefile::getCompParamList(void)const{ return CompParameters; }
std::string Makefile::getExecParamList(void)const{ return ExecParameters; }
std::string Makefile::getFileList(void)const{ return FileList; }

void Makefile::setName(const std::string &name){ Name=name; }
void Makefile::setCompiler(const std::string &comp){ Compiler=comp; }
void Makefile::setFormat(const std::string &format){ SourceFormat=format; }
void Makefile::setHeader(const std::string &format){ HeaderFormat=format; }
void Makefile::setDebug(const bool &db){ debugEnable=db; }
void Makefile::setValgrind(const bool &vg){ valgrindEnable=vg; }
void Makefile::setInstall(const bool &inst){ installEnable=inst; }
void Makefile::setCompParam(const bool &param){ parameterEnable=param; }
void Makefile::setExecParam(const bool &param){ execParamEnable=param; }
void Makefile::setOrganize(const bool &org){ organizeEnable=org; }
void Makefile::setFileList(const std::string &files){ FileList=files; }

void Makefile::print(void)const{
	cout << " (i) Current Makefile State:" << endl;
	cout << " Name:            " << Name << endl;
	cout << " Compiler:        " << Compiler << endl;
	cout << " SourceFormat:    " << SourceFormat << endl;
	cout << " HeaderFormat:    " << HeaderFormat << endl;
	cout << " debugEnable:     " << debugEnable << endl;
	cout << " valgrindEnable:  " << valgrindEnable << endl;
	cout << " parameterEnable: " << parameterEnable << endl;
	if(parameterEnable){
		cout << " Compilation parameters: " << CompParameters << endl;
	}
	cout << " execparamEnable: " << execParamEnable << endl;
	if(execParamEnable){
		cout << " Execution parameters: " << ExecParameters << endl;
	}
	cout << " organizeEnable:  " << organizeEnable << endl;
	cout << " File List: " << FileList << endl;
}

void Makefile::readCompParam(void){
	cout << " > Type the Compilation parameters and press enter: " << endl;
	cin >> CompParameters;
}

void Makefile::readExecParam(void){
	cout << " > Type the Execution parameters and press enter: " << endl;
	cin >> ExecParameters;
}

