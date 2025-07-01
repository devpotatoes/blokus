extern int terminalSize[2];

#define numberOfPieces 21
#define usernameMaxLength 13
#define pieceGridSize 5

struct Player {
    int isAi;
    char name[13];
    char color[1];
    int remainingPieces;
    int remainingPiecesArray[21];
    int isFirstTurn;
};

struct Board {
    int size;
    int grid[21][21];
};

struct GameData {
    int numberOfPlayers;
    int aiDifficulty;
    int playerTurn;
    struct Player players[5];
    struct Board board;
};

extern struct GameData gameData;

struct Piece {
    int grid[5][5];
    int width;
    int height;
};

extern struct Piece piecesArray[21];