#include "checkingPiece.h"

#include <stdio.h>
#include "globalsVar.h"

int cornerCheck(int row, int col, int pieceIndex) {
    for (int i = 0; i < pieceGridSize; i += 1) {
        for (int j = 0; j < pieceGridSize; j += 1) {
            if (piecesArray[pieceIndex].grid[i][j] == 1) {
                if (col + j == 0 && row + i == 0) {
                    return 0;
                } if (col + j == gameData.board.size - 1 && row + i == 0) {
                    return 0;
                } if (col + j == 0 && row + i == gameData.board.size - 1) {
                    return 0;
                } if (col + j == gameData.board.size - 1 && row + i == gameData.board.size - 1) {
                    return 0;
                };
            };
        };
    };

    return 1;
}

int overlapCheck(int row, int col, int pieceIndex) {
    for (int i = 0; i < pieceGridSize; i += 1) {
        for (int j = 0; j < pieceGridSize; j += 1) {
            if (piecesArray[pieceIndex].grid[i][j] != 0) {
                int targetRow = row + i;
                int targetCol = col + j;

                if (targetRow < 0 || targetRow >= gameData.board.size || targetCol < 0 || targetCol >= gameData.board.size) {
                    return 1;
                };

                if (gameData.board.grid[targetRow][targetCol] != 0) {
                    return 1;
                };
            };
        };
    };

    return 0;
}

int diagonalCheck(int row, int col, int pieceIndex) {
    for (int i = 0; i < pieceGridSize; i += 1) {
        for (int j = 0; j < pieceGridSize; j += 1) {
            if (piecesArray[pieceIndex].grid[i][j] == 1) {
                if (gameData.board.grid[row + i - 1][col + j - 1] == gameData.playerTurn + 1 || gameData.board.grid[row + i - 1][col + j + 1] == gameData.playerTurn + 1 || gameData.board.grid[row + i + 1][col + j - 1] == gameData.playerTurn + 1 || gameData.board.grid[row + i + 1][col + j + 1] == gameData.playerTurn + 1) {
                    return 0;
                };
            };
        };
    };
    
    return 1;
}

int lateralCheck(int row, int col, int pieceIndex) {
    for (int i = 0; i < pieceGridSize; i += 1) {
        for (int j = 0; j < pieceGridSize; j += 1) {
            if (piecesArray[pieceIndex].grid[i][j] == 1) {
                if (gameData.board.grid[row + i - 1][col + j] == gameData.playerTurn + 1 || gameData.board.grid[row + i + 1][col + j] == gameData.playerTurn + 1 || gameData.board.grid[row + i][col + j - 1] == gameData.playerTurn + 1 || gameData.board.grid[row + i][col + j + 1] == gameData.playerTurn + 1) {
                    return 1;
                };
            };
        };
    };

    return 0;
}

int canPlacePiece(int row, int col, int pieceIndex) {
    if (gameData.players[gameData.playerTurn].isFirstTurn == 1) {
        return cornerCheck(row, col, pieceIndex) || overlapCheck(row, col, pieceIndex);
    } else {
        return diagonalCheck(row, col, pieceIndex) || overlapCheck(row, col, pieceIndex) || lateralCheck(row, col, pieceIndex);
    };
}