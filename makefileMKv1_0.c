#include <stdio.h>
#include <stdlib.h>
#include "makefileADT.h"
#include "inputManager.h"
#include "strQueue.h"

int main(int argc, char **argv){
	system("clear");
	printf("---Starting makefile maker---\n");

	makefilePtr newMKF=NULL;

	// Create and initialize the makefile entity
	if( (newMKF=CreateMakefile(newMKF))==NULL ){
		printf(" >> Fatal System Error: Failed to Create makefile\n");
		return 1;
	}

	// Update the entity data using given arguments
	if( handleArgs(newMKF, argc, argv)!=0 ){
		printInputFormat();
		return 1;
	}

	// Get the compilation parameters separately
	if( GetFlagPar(newMKF)==1 ){
		if(getParameters(newMKF)!=0){
			printf(" >> Fatal System Error: Failed to get Compiler parameters\n");
			return 1;
		}
	}

	// Generate System input file to check current dir files
	if( handleSystemInput(newMKF, GetFrmt(newMKF), GetFlagHid(newMKF))==NULL ){
		printf(" >> Fatal System Error: Failed Handle System input\n");
		return 1;
	}

	// Handle subdirs if needed



	// Generate Final Makefile




	return 0;
}

/*	printf("\n Name:     %s\n", GetName(newMKF));
	printf(" Compiler: %s\n", GetComp(newMKF));
	printf(" Format:   %s\n", GetFrmt(newMKF));
	printf(" SubDirs: %d\n", GetFlagDir(newMKF));
	printf(" Hidden:  %d\n", GetFlagHid(newMKF));
	printf(" Param:   %d\n", GetFlagPar(newMKF));*/