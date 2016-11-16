#include <stdio.h>
#include "compile.h"
void loadvar(char * mark, float * val) {
    if (strcmp(mark, "xxxx") == 0) {
        *val = 6;
        return;
    }
    if (strcmp(mark, "xxxx") == 0) {
        *val = 6.99789;
        return;
    }
}
int main(int argc, char *argv[]) {
    int iRet;
    /**/
    char sFile[MAX_FORMULA_LEN] = {0};
    FILE * fp;
    if (argc != 2) {
        printf("Error: command filename/n");
        exit(-1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file/n");
        exit(-1);
    }
    fread(sFile, sizeof(char), MAX_FORMULA_LEN, fp);
    fclose(fp);

    iRet = FormulaParser(sFile, loadvar);
    printf("/nRet:%d/n", iRet );

    float fVal;
    iRet = FormulaVarGet("i", &fVal);
    if (iRet == 0)
        printf("i:%g/n", fVal );
}
