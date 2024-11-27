#include <stdio.h>

#define BOARDLENGTH 10

void vPrintBoard(int iaBoard[][BOARDLENGTH]);


//struct sShip {
//    int size;
//};
//typedef struct sShip t_TypeOfShip;

int main() {

    /*t_TypeOfShip shipOfSizeTwo[2] = { 1,2 };*/

    int iaPlayerA[BOARDLENGTH][BOARDLENGTH] = {
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

    vPrintBoard(iaPlayerA);
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
