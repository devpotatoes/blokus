#include <stdio.h>
#include <string.h>
#include <math.h>
#include "globalsVar.h"
#include "utils.h"

#include "menu.h"

int displayAiDifficultySelectionMenu(int menuIndex) {
    clearTerminal();

    const char *menuArray[] = {
        "Beginner",
        "Amateur",
        "Advanced"
    };

    const char *menuTitle = "AI difficulty level";

    printf("\n");
    printf("%s%s", generateStr((terminalSize[1] - strlen(menuTitle)) / 2, ' '), menuTitle);

    int aiDifficultyBoxWidth = 40;
    int aiDifficultyBoxInnerWidth = 38;
    int indexCursorMarginRight = 3;

    printf("\n");
    printf("%s┌──────────────────────────────────────┐\n", generateStr((terminalSize[1] - aiDifficultyBoxWidth) / 2, ' '));
    for (int i = 0; i < (int)(sizeof(menuArray) / sizeof(menuArray[0])); i += 1) {
        float padding = (aiDifficultyBoxInnerWidth - strlen(menuArray[i])) / 2.0;
        int leftPadding = round(padding);

        if (i == menuIndex) {
            printf("%s│%s\x1b[90m%s\x1b[0m%s<  │\n", generateStr((terminalSize[1] - aiDifficultyBoxWidth) / 2, ' '), generateStr(leftPadding, ' '), menuArray[i], generateStr(padding - indexCursorMarginRight, ' '));
        } else {
            printf("%s│%s%s%s│\n", generateStr((terminalSize[1] - aiDifficultyBoxWidth) / 2, ' '), generateStr(leftPadding, ' '), menuArray[i], generateStr(padding, ' '));
        };
    };
    printf("%s└──────────────────────────────────────┘\n", generateStr((terminalSize[1] - aiDifficultyBoxWidth) / 2, ' '));

    int commandBoxWidth = 28;

    printf("\n");
    printf("%s┌─ Command ────────────────┐\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s│                          │\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s└──────────────────────────┘\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("\x1b[2A\x1b[%dC", ((terminalSize[1] - commandBoxWidth) / 2) + 2);

    return 0;
}

int settings(void) {
    clearTerminal();
    refreshTerminalSizeVar();

    int menuIndex = gameData.aiDifficulty - 1;

    int commandBoxWidth = 28;

    printf("\n");
    printf("%s┌─ Command ────────────────┐\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s│                          │\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("%s└──────────────────────────┘\n", generateStr((terminalSize[1] - commandBoxWidth) / 2, ' '));
    printf("\n");

    const char *optionsDescriptionArray[] = {
        "Enter 1 to access the AI difficulty settings.",
        "Enter 2 to return to the main menu."
    };

    for (int i = 0; i < (int)(sizeof(optionsDescriptionArray) / sizeof(optionsDescriptionArray[0])); i += 1) {
        printf("%s\x1b[32m%s\x1b[0m\n", generateStr((terminalSize[1] - strlen(optionsDescriptionArray[0])) / 2, ' '), optionsDescriptionArray[i]);
    };

    printf("\x1b[5A\x1b[%dC", ((terminalSize[1] - commandBoxWidth) / 2) + 2);

    int character = getchar();

    if (character == '1') {
        while (1) {
            displayAiDifficultySelectionMenu(menuIndex);
            clearTextBuffer();

            character = getchar();

            if (character == '\x1b') {
                character = getchar();

                if (character == '[') {
                    character = getchar();

                    if (character == 'A' && menuIndex > 0) {
                        menuIndex -= 1;
                    } else if (character == 'B' && menuIndex < 2) {
                        menuIndex += 1;
                    };
                };
            } else if (character == '\n') {
                gameData.aiDifficulty = menuIndex + 1;

                break;
            };
        };

        settings();
    } else if (character == '2') {
        menu();
    } else {
        settings();
    };

    return 0;
}