#ifndef _makefileADT_
#define _makefileADT_

typedef struct makefileADT *makefilePtr;

// Start-Up functions
makefilePtr CreateMakefile(makefilePtr new); // Allocate memory for a Makefile struct
char InitializeMakefile(makefilePtr ptr); 	 // Initialize the members of a Makefile to the defaults

// Set data to the Makefile struct ( Return value 1 for errors )
char SetName(makefilePtr ptr, char *newName);
char SetComp(makefilePtr ptr, char *newComp);
char SetFrmt(makefilePtr ptr, char *newFormat);

char SetFlagDeb(makefilePtr ptr, char value);
char SetFlagVal(makefilePtr ptr, char value);

// Get data from the Makefile struct ( Return Member value or -1/NULL for errors )
char *GetName(makefilePtr ptr);
char *GetComp(makefilePtr ptr);
char *GetFrmt(makefilePtr ptr);

char GetFlagDeb(makefilePtr ptr);
char GetFlagVal(makefilePtr ptr);

// Clean up functions
void DestroyMakefile(makefilePtr ptr); // Free the Makefile

#endif