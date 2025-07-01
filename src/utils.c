#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globalsVar.h"

#include "game.h"

int clearTerminal(void) {
    char command[] = "clear";
    system(command);
    
    return 0;
}

void exitProgram(int status) {
    clearTerminal();

    if (status == -1 || status == 0) {
        printf("Thank you for playing my game ! :)\n\n");
    } else if (status == 2) {
        printf("\x1b[31m[SIGINT]\x1b[0m The game has been interrupted by the user.\n\n");
    } else {
        printf("Oops... There seems to have been an error. Code: %d\n\n", status);
    };

    char command[] = "rm -f ./.blokusTemp.txt";
    system(command);

    exit(status);
}

char *generateStr(int length, char fillCharacter) {
    char *strArray = (char*)malloc((length + 1) * sizeof(char));

    if (length <= 0) {
        strArray[length] = '\0';
        return strArray;
    };

    if (strArray == NULL) {
        return NULL;
    };

    for (int i = 0; i < length; i += 1) {
        strArray[i] = fillCharacter;
    };

    strArray[length] = '\0';

    return strArray;
}

int *getTerminalSize(void) {
    static int sizeArray[2] = { 0 };

    char command1[] = "tput lines > ./.blokusTemp.txt";
    char command2[] = "tput cols >> ./.blokusTemp.txt";

    system(command1);
    system(command2);
    
    FILE *fpointer = fopen("./.blokusTemp.txt", "r");

    if (fpointer != NULL) {
        fscanf(fpointer, "%d", &sizeArray[0]);
        fscanf(fpointer, "%d", &sizeArray[1]);
        fclose(fpointer);
    };
    
    return sizeArray;
}

int refreshTerminalSizeVar(void) {
    int *getTerminalSizeValue = getTerminalSize();

    terminalSize[0] = getTerminalSizeValue[0];
    terminalSize[1] = getTerminalSizeValue[1];

    return 0;
}

void clearTextBuffer(void) {
    while (getchar() != '\n');
}