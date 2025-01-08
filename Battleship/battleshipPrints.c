#include "battleship.h"
/// <summary>
/// Prints the welcome Screen and introduces the Game to the player
/// </summary>
void vIntroduction()
{
	printf("=======================================================\n");
	printf("X       X  XXXXX  X        XXXX    XXX   X     X  XXXXX  \n");
	printf("X       X  X      X       X       X   X  XX   XX  X   \n");
	printf("X   X   X  XXXXX  X       X       X   X  X X X X  XXXXX \n");
	printf(" X X X X   X      X       X       X   X  X  X  X  X  \n");
	printf("  X   X    XXXXX  XXXXX    XXXX    XXX   X     X  XXXXX\n");
	printf("=======================================================\n");
	printf("\n\n");
	printf("||R U L E S||\n");
	printf("1. This is a two player game.\n");
	printf("2. Player 1 has to manually input coordinates\n");
	printf("   for the game board\n");
	printf("3. There are four types of ships to be placed by longest length to the\n");
	printf("   shortest; [b] Battleship has 4 cells, [c] Cruiser has 3 cells, \n");
	printf("   [s] Submarine has 2 cells, [d] Destroyer has 1 cell\n");
	printf("4. Afterwards, Player 2 does his input\n");
	printf("5. Player 1 goes first\n");
	printf("6. The game begins as each player tries to sink the ships of the oponent\n");
	printf("7. First player to destroy all ships wins\n\n");
}

/// <summary>
/// Prints the board with Ships/Water visible.
/// </summary>
/// <param name="iaBoard"> The Board that should be printed </param>
void vPrintBoard(int iaBoard[][BOARDLENGTH]) {
    char caLetters[BOARDLENGTH] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    printf("  ");
    for (int i = 0; i < BOARDLENGTH; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int iX = 0; iX < BOARDLENGTH; iX++) {
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%c ", cConvertSetup(iaBoard[iX][iY]));
        }
        printf("\n");
    }
}

/// <summary>
/// Prints the Board of each Player, hidden so only questionsmarks are shown
/// </summary>
/// <param name="iaBoard">Board of Player A which will be printed</param>
/// <param name="ibBoard">Board of Player B which will be printed</param>
void vPrintPlayBoards(int iaBoard[][BOARDLENGTH], int ibBoard[][BOARDLENGTH]) {
    char caLetters[BOARDLENGTH] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    printf("[Current Player]\t\t\t\t[Opponent]\n\n");
    for (int j = 0; j < 2; j++) {
        printf("  ");
        for (int i = 0; i < BOARDLENGTH; i++) {
            printf("%d ", i);
        }
        printf("\t\t\t");
    }
    printf("\n");

    for (int iX = 0; iX < BOARDLENGTH; iX++) {
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%c ", cConvertSetupEnemy(iaBoard[iX][iY]));
        }
        printf("\t\t\t");
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%c ", cConvertSetupEnemy(ibBoard[iX][iY]));
        }
        printf("\n");
    }
}

/// <summary>
/// Waits for the player to press a certain button, assigns it to an variable and checks if it equals to the wished button
/// </summary>
/// <param name="message">The massage that will be displayed</param>
void vSystemMessage(char* message) {
    char ch = '\0';

    do {
        printf("%s", message);
    } while ((ch = _getch()) != '\r');
}

/// <summary>
/// Prints the Victory Screen after the game ends
/// </summary>
/// <param name="iWinCondition"> Condition for checking which message to be displayed</param>
void vPrintVictoryScreen(int iWinCondition) {
    if (iWinCondition == 1) {
        printf("\n");
        printf("  ______ _                         ___    _    _ _           \n");
        printf(" | ___ \\ |                        / _ \\  | |  | (_)          \n");
        printf(" | |_/ / | __ _ _   _  ___ _ __  / /_\\ \\ | |  | |_ _ __  ___ \n");
        printf(" |  __/| |/ _` | | | |/ _ \\ '__| |  _  | | |/\\| | | '_ \\/ __|\n");
        printf(" | |   | | (_| | |_| |  __/ |    | | | | \\  /\\  / | | | \\__ \\\n");
        printf(" \\_|   |_\\__,_|\\__, |\\___|_|     \\_| |_/  \\/  \\/|_|_| |_|___/\n");
        printf("                 __/ |                                       \n");
        printf("                |___/                                        \n\n");
    }
    else {
        printf("\n");
        printf("  ______ _                        ______   _    _ _           \n");
        printf(" | ___ \\ |                       | ___ \\ | |  | (_)          \n");
        printf(" | |_/ / | __ _ _   _  ___ _ __  | |_/ / | |  | |_ _ __  ___ \n");
        printf(" |  __/| |/ _` | | | |/ _ \\ '__| | ___ \\ | |/\\| | | '_ \\/ __|\n");
        printf(" | |   | | (_| | |_| |  __/ |    | |_/ / \\  /\\  / | | | \\__ \\\n");
        printf(" \\_|   |_\\__,_|\\__, |\\___|_|     \\____/   \\/  \\/|_|_| |_|___/\n");
        printf("                 __/ |                                       \n");
        printf("                |___/                                        \n\n");
    }
}