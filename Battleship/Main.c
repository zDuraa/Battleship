#include <stdio.h>
#include "battleship.h"

int main() {
    vIntroduction();

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

    //test
    vPrintBoard(iaPlayerABoard);
    vSetShip(fleet, iaPlayerABoard);
    vPrintBoard(iaPlayerABoard);
    return 0;
}
