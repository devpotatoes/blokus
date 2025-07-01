#include "ai.h"

#include <stdio.h>
#include "globalsVar.h"

#include "checkingPiece.h"
#include "game.h"

void playBeginner(void){
    for (int pieceIndex = 0; pieceIndex < numberOfPieces; pieceIndex += 1) {
        for (int row = 0; row < gameData.board.size; row += 1) {
            for (int col = 0; col < gameData.board.size; col += 1) {
                if (gameData.players[gameData.playerTurn].remainingPiecesArray[pieceIndex] == 0) {
                    continue;
                } if (canPlacePiece(row, col, pieceIndex) == 0) {
                    gameData.players[gameData.playerTurn].remainingPieces -= 1;
                    gameData.players[gameData.playerTurn].remainingPiecesArray[pieceIndex] = 0;

                    placePiece(row, col, pieceIndex);
                    printf("The player %d has placed a piece %d at %d, %d\n", gameData.playerTurn + 1, pieceIndex, row, col);

                    return;
                };
            };
        };
    };

    printf("The player %d cannot play.\n", gameData.playerTurn + 1);
}

void playAmateur(void) {
    int bestPiece = -1;
    int bestRow = -1;
    int bestCol = -1;

    for (int pieceIndex = numberOfPieces - 1; pieceIndex >= 0; pieceIndex -= 1) {
        for (int row = 0; row < gameData.board.size; row += 1) {
            for (int col = 0; col < gameData.board.size; col += 1) {
                if (gameData.players[gameData.playerTurn].remainingPiecesArray[pieceIndex] == 0) {
                    continue;
                };

                if (canPlacePiece(row, col, pieceIndex) == 0) {
                    bestPiece = pieceIndex;
                    bestRow = row;
                    bestCol = col;
                    break;
                };
            };
            
            if (bestPiece != -1) {
                break;
            };
        };

        if (bestPiece != -1) {
            break;
        };
    };

    if (bestPiece != -1) {
        gameData.players[gameData.playerTurn].remainingPieces -= 1;
        gameData.players[gameData.playerTurn].remainingPiecesArray[bestPiece] = 0;
        
        placePiece(bestRow, bestCol, bestPiece);
        printf("The player %d has placed a piece %d at %d, %d\n", gameData.playerTurn + 1, bestPiece, bestRow, bestCol);
    } else {
        printf("The player %d cannot play.\n", gameData.playerTurn + 1);
    };
}

void playAdvanced(void) {
    int bestRow = -1;
    int bestCol = -1;
    int bestPiece = -1;
    int maxFreeSpace = -1;

    for (int pieceIndex = 0; pieceIndex < numberOfPieces; pieceIndex += 1) {
        for (int row = 0; row < gameData.board.size; row += 1) {
            for (int col = 0; col < gameData.board.size; col += 1) {
                if (gameData.players[gameData.playerTurn].remainingPiecesArray[pieceIndex] == 0) {
                    continue;
                };

                if (canPlacePiece(row, col, pieceIndex) == 0) {
                    int freeSpace = 0;

                    for (int i = 0; i < pieceGridSize; i += 1) {
                        for (int j = 0; j < pieceGridSize; j += 1) {
                            if (piecesArray[pieceIndex].grid[i][j] != 0) {
                                int dRow[] = { -1, 1, 0, 0 };
                                int dCol[] = { 0, 0, -1, 1 };

                                for (int k = 0; k < 4; k += 1) {
                                    int newRow = row + i + dRow[k], newCol = col + j + dCol[k];

                                    if (newRow >= 0 && newRow < gameData.board.size && newCol >= 0 && newCol < gameData.board.size && gameData.board.grid[newRow][newCol] == 0) {
                                        freeSpace += 1;
                                    };
                                };
                            };
                        };
                    };

                    if (freeSpace > maxFreeSpace) {
                        maxFreeSpace = freeSpace;
                        bestRow = row;
                        bestCol = col;
                        bestPiece = pieceIndex;
                    };
                };
            };
        };
    };

    if (bestRow != -1 && bestCol != -1 && bestPiece != -1) {
        gameData.players[gameData.playerTurn].remainingPieces -= 1;
        gameData.players[gameData.playerTurn].remainingPiecesArray[bestPiece] = 0;

        placePiece(bestRow, bestCol, bestPiece);
        printf("The player %d has placed a piece %d at %d, %d\n", gameData.playerTurn + 1, bestPiece, bestRow, bestCol);
    } else {
        printf("The player %d cannot play.\n", gameData.playerTurn + 1);
    };
}