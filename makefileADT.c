#include <string.h>
#include <stdlib.h>
#include <stdio.h> // Remove this include if i remove printf

#include "makefileADT.h"

// DEFAULT INITIAL MEMBER VALUES
#define DEF_NAME "a.out"
#define DEF_COMP "gcc"
#define DEF_FORM "c"
#define DEF_DB 0
#define DEF_VG 0

typedef struct makefileADT {
	char *Name;
	char *Compiler;
	char *FileFormat;
	
	char FlagDebug;
	char FlagValgrind;
}makefile;


makefilePtr CreateMakefile(makefilePtr new){
	int tmp;
	// Allocate the required memory
	if( (new=malloc(sizeof(struct makefileADT)))==NULL ){
		return NULL;
	}

	new->Name=NULL;
	new->Compiler=NULL;
	new->FileFormat=NULL;

	// Initialize new makefile 
	if( (tmp=InitializeMakefile(new))!=0 ){
		return NULL;
	}

	return new;
}

char InitializeMakefile(makefilePtr ptr){

	if( SetName(ptr, DEF_NAME)!=0 ){ return 1; }
	if( SetComp(ptr, DEF_COMP)!=0 ){ return 2; }
	if( SetFrmt(ptr, DEF_FORM)!=0 ){ return 3; }

	if( SetFlagDeb(ptr, DEF_DB)!=0 ){ return 4; }
	if( SetFlagVal(ptr, DEF_VG)!=0  ){ return 5; }

	return 0;
}

char SetName(makefilePtr ptr, char *newName){
	if(ptr->Name!=NULL){
		free(ptr->Name);
	}
	if( (ptr->Name=malloc((strlen(newName)+1)*sizeof(char)))==NULL ){ return 1; }
	strcpy(ptr->Name, newName);
	return 0;
}

char SetComp(makefilePtr ptr, char *newComp){
	if(ptr->Compiler!=NULL){
		free(ptr->Compiler);
	}
	if( (ptr->Compiler=malloc((strlen(newComp)+1)*sizeof(char)))==NULL ){ return 1; }
	strcpy(ptr->Compiler, newComp);

	return 0;
}

char SetFrmt(makefilePtr ptr, char *newFormat){
	if(ptr->FileFormat!=NULL){
		free(ptr->FileFormat);
	}
	if( (ptr->FileFormat=malloc((strlen(newFormat)+1)*sizeof(char)))==NULL ){ return 1; }
	strcpy(ptr->FileFormat, newFormat);

	return 0;
}

char SetFlagDeb(makefilePtr ptr, char value){
	ptr->FlagDebug=value;
	return 0;
}

char SetFlagVal(makefilePtr ptr, char value){
	ptr->FlagValgrind=value;
	return 0;
}

char *GetName(makefilePtr ptr){

	return ptr->Name;
}

char *GetComp(makefilePtr ptr){

	return ptr->Compiler;
}

char *GetFrmt(makefilePtr ptr){

	return ptr->FileFormat;
}

char GetFlagDeb(makefilePtr ptr){

	return ptr->FlagDebug;
}

char GetFlagVal(makefilePtr ptr){

	return ptr->FlagValgrind;
}

void DestroyMakefile(makefilePtr ptr){
	free(ptr->Name);
	free(ptr->Compiler);
	free(ptr->FileFormat);

	free(ptr);
	ptr=NULL;
	return;
}