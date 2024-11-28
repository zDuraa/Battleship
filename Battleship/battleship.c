#include "battleship.h"

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
    printf("   shortest; [b] Battleship has 4 cells, [r] Cruiser has 3 cells, \n");
    printf("   [s] Submarine has 2 cells, [d] Destroyer has 1 cell\n");
    printf("4. Afterwards, Player 2 does his input\n");
    printf("5. Player 1 goes first\n");
    printf("6. The game begins as each player tries to sink the ships of the oponent\n");
    printf("7. First player to destroy all ships wins\n\n");
}
//prints board
void vPrintBoard(int iaBoard[][BOARDLENGTH]) {
    char caLetters[BOARDLENGTH] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

    // Kopfzeile (Zahlen von 0 bis 9)
    printf("  ");
    for (int i = 0; i < BOARDLENGTH; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Board-Zeilen mit Buchstaben und Werten
    for (int iX = 0; iX < BOARDLENGTH; iX++) {
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%d ", iaBoard[iX][iY]);
        }
        printf("\n");
    }
}

//Puts Ship on Board
void vSetShip(t_Ship fleet[], int iaBoard[][BOARDLENGTH])
{
    int iX = 0;
    int iY = 0;
    printf("Enter coordinates to place a ship on the board\n");
    for (int i = 0; i < TOTALSHIPS; i++)
    {
        printf("Placing a Ship with the size of %d\n", fleet[i].length);

        for (int row = 0; row < fleet[i].length; row++) {

            printf("X Coordinate: ");
            scanf_s("%d", &iX);
            printf("Y Coordinate: ");
            scanf_s("%d", &iY);

            iaBoard[iX][iY] = 1;
            fleet[i].data[row][0] = iX;
            fleet[i].data[row][0] = iY;
        }
    }

}

//void vShootShip(int iX, int iY) 
//{
//
//}

void vFillFleet(t_Ship fleet[]) {
    int index = 0;

    // • 1 Schiff der Länge 4

    fleet[index].length = 4;
    index++;

    // • 2 Schiffe der Länge 3
    for (int i = 0; i < 2; i++) {
        fleet[index].length = 3;
        index++;
    }

    // • 3 Schiffe der Länge 2
    for (int i = 0; i < 3; i++) {
        fleet[index].length = 2;
        index++;
    }

    // • 4 Schiffe der Länge 1
    for (int i = 0; i < 4; i++) {
        fleet[index].length = 1;
        index++;
    }
}


