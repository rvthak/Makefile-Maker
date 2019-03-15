// --- Malefile Maker ---
// Made by Ioannis Rovithakis at 13/03/2019 as a usefull tool to help him in the future
// With the default settings it can make a makefile with parameters for up to 15 files
// To use it:
// 1st) cd to the directory where the source files of your project are (make sure that there are no other random .c files in this directory)
// 2nd) compile the sourcefile with any name you want (i will use maker from here on)
// 3rd) type: ls *c|./maker myprog (<-myprog==name of your final executable) // takes only 1 parameter
// 4rth) Makefile ready!!
// Usefull advice! Consider making it an alias in your system to make it super easy to use

#include <stdio.h>
#include <stdlib.h>

//compiler and compilation parameters
#define compiler "gcc"
#define flags " " //-Wall

//amounts of files supported (up tp MAXFILES)
#define MAXFILES 15

//char array memory managment functions
char **tballoc(char n, char n1, char init); 	// allocates n x n1 array of chars, initialized as init | returns the table pointer in succes and NULL at error
void tbfree(char **table, char n);		// frees a table n x anything table
void strExtClean(char *str, char *trg);		// takes the input from ls in .c and removes the extention (the .c)


int main(int argc, char **argv){

	char i;
	char count=0;
	char *str;
	char **files;

	FILE *makefile;

	if(argc!=2){
		printf(" Type the name of the file that contains the main function (WITHOUT .c) while being in the project files directory\n");
		return 1;
	}

	if( (str=malloc(25*sizeof(char)))==NULL || (files=tballoc(MAXFILES, 25, 0))==NULL ){
		fprintf(stderr, "Fatal error: failed to allocate memory\n");
		return 1;
	}

	if( (makefile=fopen("makefile", "w"))==NULL ){
		fprintf(stderr, "Fatal error: failed to open file\n");
		return 1;
	}

	fprintf(makefile, "CC=%s\n", compiler);
	fprintf(makefile, "CFLAGS=%s\n\n", flags);

	fprintf(makefile, "all: %s\n\n", argv[1]);

	fprintf(makefile, "%s:", argv[1]);


	while( scanf("%s", str )!=EOF ){

		strExtClean(str, files[count]);
		fprintf(makefile, " %s.o", files[count]);
		count++;

		if(count==MAXFILES-1){
			printf("Error too many files given change the MAXFILES parameter according to your needs and run the program again\n");
			return 1;
		}
	}
	
	fprintf(makefile, "\n\t$(CC) $(CFLAGS) -o %s", argv[1]);
	
	for(i=0; i<count; i++){
		fprintf(makefile, " %s.o", files[i]);
	}
	fprintf(makefile, "\n\n");

	for(i=0; i<count; i++){
		fprintf(makefile, "%s.o: %s.c", files[i], files[i]);
		fprintf(makefile, "\n");
		fprintf(makefile, "\t$(CC) $(CFLAGS) -c %s.c \n\n", files[i]);
	}


	fprintf(makefile, ".PHONY: clean\n\nclean:\n");
	fprintf(makefile, "\trm -f *o %s\n",argv[1]);

	free(str);
	tbfree(files, MAXFILES);
	fclose(makefile);
	return 0;
}


char **tballoc(char n, char n1, char init){
	char x,y;
	char **table;
			
	table=malloc(n*sizeof(char *));

	if(table==NULL){
		fprintf(stderr, " FATAL ERROR: Failed to allocate space for main table\n");
		return NULL;
	}

	for(x=0; x<n; x++){
		table[x]=malloc(n1*sizeof(char));
		if(table[x]==NULL){
			fprintf(stderr, " FATAL ERROR: Failed to allocate space for main table\n");
			return NULL;
		}
		for(y=0; y<n1; y++){
			table[x][y]=init;
		}
	}
	return table;
}

void tbfree(char **table, char n){
	char x;
	for(x=0; x<n; x++){
		free(table[x]);
	}  
	free(table);
}

void strExtClean(char *str, char* trg){
	char ch=0;
	while( str[ch] != '.'){
		trg[ch]=str[ch];
		ch++;
	}
	return;
}
