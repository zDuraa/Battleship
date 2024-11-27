#include <stdio.h>

#define BOARDLENGTH 10
#define TOTALSHIPS 10

struct sShip {
    int length;   
    int data[4][1]; 
};
typedef struct sShip t_Ship;

void vPrintBoard(int iaBoard[][BOARDLENGTH]);
void vFillFleet(t_Ship fleet[]);
void vSetShip(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);

int main() {
    t_Ship fleet[TOTALSHIPS];
    vFillFleet(fleet);
    int iaPlayerABoard[BOARDLENGTH][BOARDLENGTH] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };


    vPrintBoard(iaPlayerABoard);
    vSetShip(fleet, iaPlayerABoard);
    vPrintBoard(iaPlayerABoard);
    return 0;
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


