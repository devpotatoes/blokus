#include "game.h"

#include <stdio.h>
#include <string.h>
#include "globalsVar.h"
#include "utils.h"

#include "checkingPiece.h"
#include "ai.h"

char *computeScore(int playerIndex) {
    static char result[16];
    int score = 0;

    for (int i = 0; i < numberOfPieces; i += 1) {
        if (gameData.players[playerIndex - 1].remainingPiecesArray[i] != 0) {
            for (int j = 0; j < pieceGridSize; j += 1) {
                for (int k = 0; k < pieceGridSize; k += 1) {
                    if (piecesArray[i].grid[j][k] == 1) {
                        score += 1;
                    };
                };
            };
        };
    };

    if (score < 9) {
        sprintf(result, "0%d", score);
    } else {
        sprintf(result, "%d", score);
    };

    return result;
}

char *displayGameInfo(int index) {
    static char textBuffer[64];

    if (index == 0) {
        sprintf(textBuffer, "│ > %s%s < │", gameData.players[gameData.playerTurn].name, generateStr(usernameMaxLength - strlen(gameData.players[gameData.playerTurn].name),' '));
    } else if (index == 1) {
        strcpy(textBuffer, "└───────────────────┘");
    } else if (index == 2) {
        strcpy(textBuffer, "┌───────────────────┐");
    } else if (index == 3) {
        strcpy(textBuffer, "│      Scores       │");
    } else if (index == 4) {
        sprintf(textBuffer, "│ %s%s: %s │", gameData.players[0].name, generateStr(usernameMaxLength - strlen(gameData.players[0].name), ' '), computeScore(1));
    } else if (index == 5) {
        sprintf(textBuffer, "│ %s%s: %s │", gameData.players[1].name, generateStr(usernameMaxLength - strlen(gameData.players[1].name), ' '), computeScore(2));
    } else if (index == 6) {
        if (gameData.players[2].name[0] != '\0') {
            sprintf(textBuffer, "│ %s%s: %s │", gameData.players[2].name, generateStr(usernameMaxLength - strlen(gameData.players[2].name), ' '), computeScore(3));
        } else {
            strcpy(textBuffer, "│                   │");
        };
    } else if (index == 7) {
        if (gameData.players[3].name[0] != '\0') {
            sprintf(textBuffer, "│ %s%s: %s │", gameData.players[3].name, generateStr(usernameMaxLength - strlen(gameData.players[3].name), ' '), computeScore(4));
        } else {
            strcpy(textBuffer, "│                   │");
        };
    };

    return textBuffer;
}

void displayGame(void) {
    clearTerminal();

    int remainingPiecesArrayIndex[21];
    int remainingPiecesCount = 0;

    for (int i = 0; i < numberOfPieces; i += 1) {
        if (gameData.players[gameData.playerTurn].remainingPiecesArray[i] != 0) {
            remainingPiecesArrayIndex[remainingPiecesCount] = i;
            remainingPiecesCount += 1;
        };
    };

    int groupSize = 7;

    for (int row = -1; row < gameData.board.size; row += 1) {
        if (row == -1) {
            printf("  ");
            for (int i = 0; i < gameData.board.size; i += 1) {
                if (i < 10) {
                    printf("%d ", i);
                } else {
                    printf("%c ", 'a' + (i - 10));
                };
            };
        } else if (row < 10) {
            printf("%d ", row);
        } else {
            printf("%c ", 'a' + (row - 10));
        };

        if (row >= 0) {
            for (int col = 0; col < gameData.board.size; col += 1) {
                if (gameData.board.grid[row][col] == 1) {
                    printf("\x1b[33m■\x1b[0m ");
                } else if (gameData.board.grid[row][col] == 2) {
                    printf("\x1b[32m■\x1b[0m ");
                } else if (gameData.board.grid[row][col] == 3) {
                    printf("\x1b[34m■\x1b[0m ");
                } else if (gameData.board.grid[row][col] == 4) {
                    printf("\x1b[31m■\x1b[0m ");
                } else {
                    printf("· ");
                };
            };
        };
    
        printf("  │   ");

        int rowOffset = row + 1;
        int pieceRowIndex = rowOffset % (pieceGridSize + 2);
        int pieceColIndex = rowOffset / (pieceGridSize + 2);
        
        if (pieceRowIndex == 0) {
            for (int i = 0; i < groupSize; i += 1) {
                int pieceListIndex = pieceColIndex * groupSize + i;

                if (pieceListIndex < remainingPiecesCount) {
                    int displayIndex = remainingPiecesArrayIndex[pieceListIndex] + 1;

                    if (displayIndex < 10) {
                        printf("┌ %d ────────┐ ", displayIndex);
                    } else {
                        printf("┌ %d ───────┐ ", displayIndex);
                    };
                };
            };
        } else if (pieceRowIndex >= 1 && pieceRowIndex <= pieceGridSize) {
            for (int i = 0; i < groupSize; i += 1) {
                int pieceListIndex = pieceColIndex * groupSize + i;

                if (pieceListIndex < remainingPiecesCount) {
                    printf("│ ");
                    for (int col = 0; col < pieceGridSize; col += 1) {
                        if (piecesArray[remainingPiecesArrayIndex[pieceListIndex]].grid[pieceRowIndex - 1][col] == 1) {
                            printf("■ ");
                        } else {
                            printf("· ");
                        };
                    };
                    printf("│ ");
                };
            };
        } else if (pieceRowIndex > pieceGridSize) {
            for (int i = 0; i < groupSize; i += 1) {
                int pieceListIndex = pieceColIndex * groupSize + i;
    
                if (pieceListIndex < remainingPiecesCount) {
                    printf("└───────────┘ ");
                };
            };
        };
        
        printf("\n");
    };

    printf("\n┌───────────────────┐\n");
    for (int i = 0; i < 8; i += 1) {
        printf("%s\n", displayGameInfo(i));
    };
    printf("└───────────────────┘\n");
}

void placePiece(int row, int col, int pieceIndex) {
    for (int i = 0; i < pieceGridSize; i += 1) {
        for (int j = 0; j < pieceGridSize; j += 1) {
            if (piecesArray[pieceIndex].grid[i][j] == 1) {
                gameData.board.grid[row + i][col + j] = gameData.playerTurn + 1;
            };
        };
    };
}


int selectPiece(void) {
    int choice;

    while (1) { 
        printf("\nSelect a piece to play (1-%d): ", numberOfPieces);

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and %d, or -1 to quit.\n", numberOfPieces);
            clearTextBuffer();

            continue;
        };
    
        if ((choice >= 1 && choice <= numberOfPieces) || choice == -1) {
            if (choice == -1) {
                exitProgram(0);
            } else {
                if (gameData.players[gameData.playerTurn].remainingPiecesArray[choice - 1] == 0) {
                    printf("This piece has already been used. Try again.\n");
                } else {
                    gameData.players[gameData.playerTurn].remainingPiecesArray[choice - 1] = 0;
                    gameData.players[gameData.playerTurn].remainingPieces -= 1;
    
                    return choice - 1;
                };
            };
        };
    };
}

int play(void) {
    int pieceIndex = selectPiece();
    clearTextBuffer();

    int row;
    int col;

    while (1) {
        printf("Enter the coordinates of the piece to play (row column): ");

        char input[64];

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Specified coordinates invalid. Please try again.\n");

            continue;
        };

        if (sscanf(input, "%d %d", &row, &col) != 2) {
            printf("Specified coordinates invalid. Please try again.\n");

            continue;
        };

        if (canPlacePiece(row, col, pieceIndex) == 0) {
            gameData.players[gameData.playerTurn].isFirstTurn = 0;

            placePiece(row, col, pieceIndex);

            return 1;
        };

        printf("Specified coordinates invalid. Please try again.\n");
    };
}

int game(void) {
    clearTerminal();

    int turnResult = 0;

    while (1) {
        displayGame();

        if (gameData.players[gameData.playerTurn].isAi == 1) {
            if (gameData.aiDifficulty == 1) {
                playBeginner();
            } else if (gameData.aiDifficulty == 2) {
                playAmateur();
            } else if (gameData.aiDifficulty == 3) {
                playAdvanced();
            };
            
            if (gameData.players[gameData.playerTurn].isFirstTurn == 1) {
                gameData.players[gameData.playerTurn].isFirstTurn = 0;
            };
        } else {
            if (gameData.players[gameData.playerTurn].remainingPieces == 0) {
                printf("The player %s has used all his pieces. End of the game.\n", gameData.players[gameData.playerTurn].name);

                break;
            } else {
                turnResult = play();
            };
        };

        if (turnResult == 0) {
            exitProgram(0);
        };

        gameData.playerTurn = (gameData.playerTurn + 1) % gameData.numberOfPlayers;
    };

    return 0;
}