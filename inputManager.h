#ifndef _inputManager_
#define _inputManager_

#include "makefileADT.h"
#include "strQueue.h"

char handleArgs(makefilePtr newMKF, int argc, char **argv);
char handleParameter(makefilePtr newMKF, char *param);
void printInputFormat(void);
int dotcheck(char *str, char *format, char hidden);

char getParameters(makefilePtr newMKF);
makefilePtr handleSystemInput(makefilePtr newMKF, char *format, char hidden);

makefilePtr handleSubDirs(makefilePtr newMKF);
void flipStrPrt(char *trg, int str, int end);
char checkZero(char *buf);
void strExtClean(char *trg);
void skipLine(FILE *file);

#endif