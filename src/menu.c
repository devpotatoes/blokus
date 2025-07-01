#include "menu.h"

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <math.h>
#include "globalsVar.h"
#include "utils.h"

#include "game.h"
#include "settings.h"
#include "rules.h"

void setDefaultSettings(void) {
    gameData.playerTurn = 0;
    gameData.aiDifficulty = 1;
    gameData.board.size = 20;
    
    piecesArray[0] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 1,
        .height = 1
    };

    piecesArray[1] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 1,
        .height = 2
    };

    piecesArray[2] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 1,
        .height = 3
    };

    piecesArray[3] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 2
    };

    piecesArray[4] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 1,
        .height = 4
    };

    piecesArray[5] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 3
    };

    piecesArray[6] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 3
    };

    piecesArray[7] = (struct Piece){
        .grid = {
            { 1, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 2
    };

    piecesArray[8] = (struct Piece){
        .grid = {
            { 1, 1, 0, 0, 0 },
            { 0, 1, 1, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 2
    };

    piecesArray[9] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 }
        },
        .width = 1,
        .height = 5
    };

    piecesArray[10] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 4
    };

    piecesArray[11] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 4
    };

    piecesArray[12] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 3
    };

    piecesArray[13] = (struct Piece){
        .grid = {
            { 1, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 3
    };

    piecesArray[14] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 2,
        .height = 4
    };

    piecesArray[15] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 1, 1, 1, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };

    piecesArray[16] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };

    piecesArray[17] = (struct Piece){
        .grid = {
            { 1, 1, 0, 0, 0 },
            { 0, 1, 1, 0, 0 },
            { 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };

    piecesArray[18] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0 },
            { 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };

    piecesArray[19] = (struct Piece){
        .grid = {
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };

    piecesArray[20] = (struct Piece){
        .grid = {
            { 0, 1, 0, 0, 0 },
            { 1, 1, 1, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 }
        },
        .width = 3,
        .height = 3
    };
}

int displayMenu(int menuIndex) {
    clearTerminal();
    refreshTerminalSizeVar();

    const char *blokusTitleArray[] = {
        " ____    _           _                      ",
        "|  _ \\  | |         | |                    ",
        "| |_) | | |   ___   | | __  _   _   ___     ",
        "|  _ <  | |  / _ \\  | |/ / | | | | / __|   ",
        "| |_) | | | | (_) | |   <  | |_| | \\__ \\  ",
        "|____/  |_|  \\___/  |_|\\_\\  \\____| |___/"
    };
    int blokusTitleLength = 40;

    printf("\n");
    for (int i = 0; i < (int)(sizeof(blokusTitleArray) / sizeof(blokusTitleArray[0])); i += 1) {
        printf("%s%s\n", generateStr((terminalSize[1] - blokusTitleLength) / 2, ' '), blokusTitleArray[i]);
    };
    printf("\n");

    const char *menuArray[] = {
        "Play",
        "Settings",
        "Game Rules",
        "Quit"
    };

    int menuBoxWidth = 40;
    int menuBoxInnerWidth = 38;
    int indexCursorMarginRight = 3;

    printf("%s┌──────────────────────────────────────┐\n", generateStr((terminalSize[1] - menuBoxWidth) / 2, ' '));
    for (int i = 0; i < (int)(sizeof(menuArray) / sizeof(menuArray[0])); i += 1) {
        float padding = (menuBoxInnerWidth - strlen(menuArray[i])) / 2.0;
        int leftPadding = round(padding);

        if (i == menuIndex) {
            printf("%s│%s\x1b[90m%s\x1b[0m%s<  │\n", generateStr((terminalSize[1] - menuBoxWidth) / 2, ' '), generateStr(leftPadding, ' '), menuArray[i], generateStr(padding - indexCursorMarginRight, ' '));
        } else {
            printf("%s│%s%s%s│\n", generateStr((terminalSize[1] - menuBoxWidth) / 2, ' '), generateStr(leftPadding, ' '), menuArray[i], generateStr(padding, ' '));
        };
    };
    printf("%s└──────────────────────────────────────┘\n", generateStr((terminalSize[1] - menuBoxWidth) / 2, ' '));

    int commandBoxWidth = 28;

    printf("\n");
    printf("%s┌─ Command ────────────────┐\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s│                          │\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s└──────────────────────────┘\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));

    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - commandBoxWidth) / 2) + 2);

    return 0;
}

int numberOfPlayerInput(void) {
    clearTerminal();

    int inputWidth = 30;

    printf("\n");
    printf("%s┌────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("%s│ Number of players (2-4):   │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("%s└────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - 3));

    int character;

    while (1) {
        character = getchar();

        if (character >= '2' && character <= '4') {
            return character - '0';
        } else {
            clearTerminal();

            printf("\n");
            printf("%s┌────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
            printf("%s│ Number of players \x1b[31m(2-4)\x1b[0m:   │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
            printf("%s└────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
            printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - 3));

            continue;
        };
    };
}

int isAiInput(int playerIndex){
    clearTerminal();

    int inputWidth = 36;

    printf("\n");
    printf("%s┌──────────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("%s│ Is the %d player an AI ? (y/n):   │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '), playerIndex);
    printf("%s└──────────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - 3));

    int character;

    while (1) {
        character = getchar();

        if (character == 'y') {
            return 1;
        } else if (character == 'n') {
            return 0;
        } else {
            clearTerminal();

            printf("\n");
            printf("%s┌──────────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
            printf("%s│ Is the %d player an AI ? \x1b[31m(y/n)\x1b[0m:   │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '), playerIndex);
            printf("%s└──────────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
            printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - 3));

            continue;
        };
    };
}

char *playerNameInput(int playerIndex) {
    clearTerminal();

    int inputWidth = 52;
    static char nameInputArray[13];

    printf("%s┌──────────────────────────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("%s│ Player name %d (12 characters max):               │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '), playerIndex);
    printf("%s└──────────────────────────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - (usernameMaxLength + 2)));

    while (1) {
        int i = 0;
        int invalidInput = 0;

        memset(nameInputArray, 0, sizeof(nameInputArray));

        int character;

        while (1) {
            character = getchar();

            if (character == '\n') {
                break;
            };

            if (i < 12 && ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9') || character == '-' || character == '_')) {
                nameInputArray[i++] = character;
            } else {
                invalidInput = 1;
                clearTerminal();
                break;
            };
        };

        nameInputArray[i] = '\0';

        if (i == 0 || i > 12) {
            invalidInput = 1;
        };

        if (!invalidInput) {
            return nameInputArray;
        };

        clearTerminal();
        clearTextBuffer();
        
        printf("%s┌──────────────────────────────────────────────────┐\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
        printf("%s│ Player name %d \x1b[31m(12 characters max)\x1b[0m:               │\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '), playerIndex);
        printf("%s└──────────────────────────────────────────────────┘\n", generateStr((terminalSize[1] - inputWidth) / 2, ' '));
        printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - inputWidth) / 2) + (inputWidth - (usernameMaxLength + 2)));
    };
}

void createGame(void) {
    refreshTerminalSizeVar();

    char colorIndexArray[4] = { 'Y', 'G', 'B', 'R' };

    gameData.numberOfPlayers = numberOfPlayerInput();
    for (int i = 0; i < gameData.numberOfPlayers; i += 1) {
        clearTextBuffer();

        gameData.players[i].isAi = isAiInput(i + 1);
        memset(gameData.players[i].color, colorIndexArray[i], sizeof(gameData.players[i].color));
    };

    clearTextBuffer();
    
    int aiCount = 0;
    char *aiNameArray[] = {
        "AI 1",
        "AI 2",
        "AI 3",
        "AI 4"
    };

    for (int i = 0; i < gameData.numberOfPlayers; i += 1) {
        if (gameData.players[i].isAi == 0) {
            strcpy(gameData.players[i].name, playerNameInput(i + 1));
        } else {
            strcpy(gameData.players[i].name, aiNameArray[aiCount]);
            aiCount += 1;
        };
    };

    for (int i = 0; i < gameData.numberOfPlayers; i += 1) {
        gameData.players[i].remainingPieces = numberOfPieces;

        for (int n = 0; n < numberOfPieces; n += 1) {
            gameData.players[i].remainingPiecesArray[n] = 1;
        };

        gameData.players[i].isFirstTurn = 1;
    };

    for (int row = 0; row <= gameData.board.size; row += 1) {
        for (int col = 0; col <= gameData.board.size; col += 1) {
            gameData.board.grid[row][col] = 0;
        };
    };
}

int menu(void) {
    int menuIndex = 0;
    displayMenu(menuIndex);

    int input;
    
    while (1) {
        input = getchar();

        if (input == '\n') {
            if (menuIndex == 0) {
                input = getchar();

                if (input == '\n') {
                    createGame();
                    game();
                };
            } else if (menuIndex == 1) {
                input = getchar();

                if (input == '\n') {
                    settings();
                };
            } else if (menuIndex == 2) {
                input = getchar();

                if (input == '\n') {
                    displayRules();
                };
            } else {
                input = getchar();

                if (input == '\n') {
                    exitProgram(0);
                };
            };
        };

        if (input == '\x1b') {
            input = getchar();

            if (input == '[') {
                input = getchar();

                if (input == 'A' && menuIndex > 0) {
                    menuIndex -= 1;
                } else if (input == 'B' && menuIndex < 3) {
                    menuIndex += 1;
                };
            };

            displayMenu(menuIndex);
        };

        if (input != '\n' && input != '\x1b') {
            displayMenu(menuIndex);
        };
    };

    return 0;
}

int main(void) {
    signal(SIGINT, exitProgram);
    setDefaultSettings();
    
    return menu();
}