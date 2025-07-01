#include <stdio.h>
#include <string.h>
#include "globalsVar.h"
#include "utils.h"

#include "menu.h"

const char *rulesArray[] = {
    "#Blokus Game Rules",
    "",
    "",
    "!  Objective of the Game",
    "",
    "   - The goal of Blokus is to place as many pieces as possible on the board while blocking your opponents.",
    "",
    "!  Equipment",
    "",
    "   - The game is played on a 20x20 board, for a total of 400 squares.",
    "   - Each player has 21 pieces of different shapes.",
    "",
    "!  Playing",
    "",
    "   - Each player has a color (blue, yellow, red, or green) and receives the 21 pieces of that color.",
    "   - On the first turn, each player must place a piece covering the corner square of the board in front of them.",
    "   - On their turn, each player places a piece that must touch at least one corner of a piece they have already placed, but",
    "     pieces of the same color may never touch by their sides.",
    "   - As soon as a player can no longer play a piece, they pass. It is possible that a player who can still place pieces",
    "     plays alone several times at the end of the game.",
    "   - When no player can place a piece, the game ends and points are counted.",
    "",
    "!  Scoring",
    "",
    "   - Each player scores:",
    "       -1 point for each square not placed (a pentomino left in hand loses 5 points).",
    "       15 points if all pieces are placed, plus 5 extra points if the last piece placed was the small square.",
    "   - The winner is the player with the highest score."
};

int displayRules(void) {
    clearTerminal();
    refreshTerminalSizeVar();

    int rulesBoxWidth = 126;

    printf("%s┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n", generateStr((terminalSize[1] - rulesBoxWidth) / 2, ' '));
    for (int i = 0; i < (int)(sizeof(rulesArray) / sizeof(rulesArray[0])); i += 1) {
        if (rulesArray[i][0] == '#') {
            printf("%s│%s\x1b[1m\x1b[4m%s\x1b[0m%s│\n", generateStr((terminalSize[1] - rulesBoxWidth) / 2, ' '), generateStr((rulesBoxWidth - strlen(&rulesArray[i][1])) / 2, ' '), &rulesArray[i][1], generateStr( rulesBoxWidth - (strlen(&rulesArray[i][1]) + strlen(generateStr((rulesBoxWidth - strlen(&rulesArray[i][1])) / 2, ' '))), ' '));
        } else if (rulesArray[i][0] == '!') {
            printf("%s│\x1b[1m%s\x1b[0m%s│\n", generateStr((terminalSize[1] - rulesBoxWidth) / 2, ' '), &rulesArray[i][1], generateStr(rulesBoxWidth - strlen(&rulesArray[i][1]), ' '));
        } else {
            printf("%s│%s%s│\n", generateStr((terminalSize[1] - rulesBoxWidth) / 2, ' '), rulesArray[i], generateStr(rulesBoxWidth - strlen(rulesArray[i]), ' '));
        };
    };
    printf("%s└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n", generateStr((terminalSize[1] - rulesBoxWidth) / 2, ' '));
    
    int commandBoxWidth = 39;

    printf("\n");
    printf("%s┌─ Command ───────────────────────────┐\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s│ Click enter to return to the menu   │\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s└─────────────────────────────────────┘\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - commandBoxWidth) / 2) + (commandBoxWidth - 3));

    int character;

    while (1) {
        character = getchar();

        if (character) {
            menu();
        };
    };

    return 0;
}