#include <stdio.h>
#include "battleship.h"

int main() {
    short int siPlayer = 0;	           // 0 -> player1, 1 -> player2 
    vIntroduction();
    systemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");

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

    //temp
    vPrintBoard(iaPlayerABoard);
    vSetShip(fleet, iaPlayerABoard);
    vPrintBoard(iaPlayerABoard);
    return 0;
}
