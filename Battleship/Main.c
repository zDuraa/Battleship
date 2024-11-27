#include <stdio.h>
#include "battleship.h"

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
