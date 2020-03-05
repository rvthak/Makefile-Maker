#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputManager.h"

#define ARG_NAME "-n"
#define ARG_COMP "-c"
#define ARG_FORM "-f"
#define ARG_DIRS "-d"
#define ARG_HID  "-h" // to remove
#define ARG_PAR  "-p"


#define MAX_PARAMETER_LENGTH 40
#define BUFFER_SIZE 100

char wtName=0;
char wtCompiler=0;
char wtFormat=0;

char handleArgs(makefilePtr newMKF, int argc, char **argv){
	printf("\n => Handling Input...\n");
	if(argc==2){ // only one argument given (=set it as a name)
		if( argv[1][0]=='-' ){
			if( handleParameter(newMKF, argv[1])!=0 ){ return 1; }
			
			if( wtName==1 ){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Name(-n) parameter awaits a string but get another parameter\n");
				return 1;
			}
			else if( wtCompiler==1 ){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Compiler(-c) parameter awaits a string but get another parameter\n");
				return 1;
			}
			else if( wtFormat==1 ){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Format(-f) parameter awaits a string but get another parameter\n");
				return 1;
			}
		}
		else{
			if( (SetName(newMKF, argv[1]))!=0 ){ 
				printf(" >> Fatal System Error: Setting Name\n"); 
				return 1; 
			}
			printf(" (-n) > Makefile Name set to:      %s\n", argv[1]);
		}
	}
	else if(argc==1){
		printf("  (!) > No args given using defaults..\n");
	}
	else{
		//handle them all one by one
		int tmp=1;
		argc=argc-1;

		while(tmp<=argc){
			if( handleParameter(newMKF, argv[tmp])!=0 ){ return 1; }
			tmp++;
		}
	}
	printf("\n");
	return 0;
}

char handleParameter(makefilePtr newMKF, char *param){

	if( (*param)=='-' ){ // If the string starts with - (=is a parameter)
		//printf(" --Parameter--\n");
		if( wtName==1 ){
			printf(" >> Fatal User Error: Wrong parameters given\n");
			printf(" >> Name(-n) parameter awaits a string but get another parameter\n");
			return 1;
		}
		else if( wtCompiler==1 ){
			printf(" >> Fatal User Error: Wrong parameters given\n");
			printf(" >> Compiler(-c) parameter awaits a string but get another parameter\n");
			return 1;
		}
		else if( wtFormat==1 ){
			printf(" >> Fatal User Error: Wrong parameters given\n");
			printf(" >> Format(-f) parameter awaits a string but get another parameter\n");
			return 1;
		}


		if( strcmp(param, ARG_NAME)==0 ){
			//printf(" Name\n");
			if(wtName!=0){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Name parameter given twice\n");
				return 1;
			}
			wtName++;
		}
		else if( strcmp(param, ARG_COMP)==0 ){
			//printf(" Compiler\n");
			if(wtCompiler!=0){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Compiler parameter given twice\n");
				return 1;
			}
			wtCompiler++;
		}
		else if( strcmp(param, ARG_FORM)==0 ){
			//printf(" Format\n");
			if(wtFormat!=0){
				printf(" >> Fatal User Error: Wrong parameters given\n");
				printf(" >> Format parameter given twice\n");
				return 1;
			}
			wtFormat++;
		}
		else if( strcmp(param, ARG_DIRS)==0 ){
			if( SetFlagDir(newMKF, 1)!=0 ){
				printf(" >> Fatal System Error: Setting Subdirectory Flag\n"); 
				return 1;
			}
			printf(" (-d) > Enabled Subdirectory Search\n");
		}
		else if( strcmp(param, ARG_HID)==0 ){
			if( SetFlagHid(newMKF, 1)!=0 ){
				printf(" >> Fatal System Error: Setting Hidden Directory Flag\n"); 
				return 1;
			}
			printf(" (-h) > Enabled Hidden Directory Search\n");
		}
		else if( strcmp(param, ARG_PAR)==0 ){
			if( SetFlagPar(newMKF, 1)!=0 ){
				printf(" >> Fatal System Error: Setting Parameter Flag\n"); 
				return 1;
			}
			printf(" (-p) > Enabled Compilation Parameter Functionality: You will be able\n");
			printf("      > to add your custom compilation parameters in the next step\n");
		}
		else{
			printf("  (!) > Unknown Parameter Given: Skipping...\n");
		}
	}
	else{ // Not a parameter (=string)
		//printf(" --Not Parameter--\n");
		if( wtName==1 ){
			if( (SetName(newMKF, param))!=0 ){ 
				printf(" >> Fatal System Error: Setting Name\n"); 
				return 1; 
			}
			printf(" (-n) > Makefile Name set to:      %s\n", param);
			wtName++;
		}
		else if( wtCompiler==1 ){
			if( (SetComp(newMKF, param))!=0 ){ 
				printf(" >> Fatal System Error: Setting Compiler\n"); 
				return 1; 
			}
			printf(" (-c) > Makefile Compiler set to:  %s\n", param);
			wtCompiler++;
		}
		else if( wtFormat==1 ){
			if( (SetFrmt(newMKF, param))!=0 ){ 
				printf(" >> Fatal System Error: Setting Format\n"); 
				return 1; 
			}
			printf(" (-f) > Makefile Format set to:    .%s\n", param);
			wtFormat++;
		}
		else{
			printf("  (!) > Rogue String: %s given: Skipping...\n", param);
		}
	}

	return 0;
}

void printInputFormat(void){
	printf("\n > Correct Use:\n");
	printf(" >> Set Makefile Name:     -n <name>\n");
	printf(" >> Set Makefile Compiler: -c <compiler name>\n");
	printf(" >> Set Makefile Format:   -f <file format>\n");
	printf(" >> Enable Subdirectory Search:      -d\n");
	printf(" >> Enable Hidden Directory Search:  -h\n");
	printf(" >> Enable Compiler Parameter Funct: -p\n");
	printf("\n (!)> The <...> fields are REQUIRED right after their corresponding parameter\n");
	printf(" (!)> Using the SAME parameter TWICE will be considered user error and terminate\n");
	printf(" (!)> Flag parameters are allowed to be used twice but it will be like using them once\n");
	printf(" (!)> Rogue Strings and Non-Supported parameter will be skipped\n");
	printf(" (!)> Give Format by writing just the last chars (example file.c => -f c \n");
	return;
}

int dotcheck(char *str, char *format, char hidden){
	char *ptr;
	char dotfound; // there is ONE . in str
	char flag=0; // check for non-dot chars before the first .

	ptr=str;

	if( hidden==0 ){ // if hidden mode inactive
		if((*ptr)== '.'){ // it starts with . => reject it
			return 1;
		}
	}
	else{
		ptr++; // consider the next one first char
	}

	while( (*ptr) != '\0' ){ // until we reach the end of the string

		if( (dotfound==0) && ((*ptr)== '.') ){ // if found first .
			dotfound=1;
		}
		else if( (dotfound==0) ){ // we have a char before first .
			flag=1;
		}
		else if( dotfound==1 ){
			if( strcmp(ptr, format)==0 && flag!=0){
				return 0; // format matches
			}
			else{
				return 1; // format doesnt match
			}
		}

		ptr++; // move to next char of str
	}

	return 1; // reached end => reject it to be safe
}

char getParameters(makefilePtr newMKF){
	char *buf;
	char *format;

	int div=MAX_PARAMETER_LENGTH;
	int mod;
	int count=0;

	printf(" => Getting Compilation parameters...\n");
	printf(" > Please type the compilation parameters you need:\n");
	printf(" > Type 0 and press enter to end parameter input.\n");

	if( (buf=malloc( (MAX_PARAMETER_LENGTH+1)*sizeof(char) ))==NULL ){ return 1; }
	if( (format=malloc((MAX_PARAMETER_LENGTH+3)*sizeof(char)))==NULL){ return 1; }

	format[count]='%';
	count++;

	mod=div%10;
	div=div/10;
	format[count]=mod+'0';
	count++;

	while(div!=0){
		mod=div%10;
		div=div/10;
		format[count]=mod+'0';
		count++;
	}

	format[count]='s';

	flipStrPrt(format, 1, count-1);

	newMKF=SetParameters(newMKF);

	printf("     ");
	scanf(format, buf);
	if( AddParameter(newMKF, buf)!=0 ){ return 1; }

	while( checkZero(buf)==0 ){
		printf("     ");
		scanf(format, buf);
		if( AddParameter(newMKF, buf)!=0 ){ return 1; }
	}

	printf(" > Given parameters taken into account\n\n");

	free(format);
	free(buf);
	return 0;
}

makefilePtr handleSystemInput(makefilePtr newMKF, char *format, char hidden){
	FILE *file;
	int wordcount=0;
	int filecount=0;
	char *buffer=NULL;

	int ch;
	int count;
	char spaceArea=0;
	char wordNum=1;
	char firstChar=1;
	int offset=0;

	printf(" => Searching for files in current directory...\n");
	printf(" > Files found:\n");

	newMKF=SetFiles(newMKF);
	system("ls -la>makefileMKtemp.txt");

	if( (file=fopen("makefileMKtemp.txt", "r"))==NULL){ return NULL; }

	skipLine(file);

	while( (ch=getc(file))!=EOF ){
		if(firstChar==1){
			if(ch=='d'){
				printf(" Directory: ");
			}
			firstChar=0;
		}

		if(ch==' '){
			if(spaceArea==0){
				spaceArea=1;
				wordNum++;
			}
		}
		else{
			spaceArea=0;
		}

		if(wordNum==9&&spaceArea==0){
			ungetc(ch, file);

			count=1;
			while( (ch=getc(file))!='\n' ){
				count++;
			}

			if( (fseek(file, (-1)*count, SEEK_CUR))!=0 ){ return NULL;}
			
			if( buffer!=NULL){ free(buffer); }
			if( (buffer=malloc((count+1)*sizeof(char)))==NULL){ return NULL; }
			
			offset=0;
			while( (ch=getc(file))!='\n' ){
				buffer[offset]=ch;
				offset++;
			}
			buffer[offset]='\0';
			
			if( dotcheck(buffer, format, hidden)==0 ){
				strExtClean(buffer);
				
				if( AddFile(newMKF, buffer)!=0 ){ return NULL; }
			}
			printf("%s\n", buffer);
		}

		if(ch=='\n'){
			wordNum=1;
			firstChar=1;
		}

	}

	PrintFiles(newMKF);
	system("rm -f makefileMKtemp.txt");
	fclose(file);
	return newMKF;
}

makefilePtr handleSubDirs(makefilePtr newMKF){
	
	//
}

void flipStrPrt(char *trg, int str, int end){
	char ch;

	while(str<=end){
		ch=trg[str];
		trg[str]=trg[end];
		trg[end]=ch;

		str++;
		end--;
	}
	return;
}

char checkZero(char *buf){
	if(buf[0]=='0' && buf[1]=='\0'){
		return 1;
	}
	return 0;
}

void strExtClean(char *trg){
	char ch=0;
	while( trg[ch] != '.'){
		ch++;
	}
	trg[ch]=0;
	return;
}

void skipLine(FILE *file){
	int ch;
	while( (ch=getc(file))!='\n' ){}
	return;
}