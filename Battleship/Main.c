#include "battleship.h"

int main() {
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
    int iaPlayerBBoard[BOARDLENGTH][BOARDLENGTH] = {
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

/*

   - 2 Arrays, Player1/2
   - char vConvertNumberToSymbol(int iCellValue)
   - struct Board
     {
      int iaBoard[][] //Board des Spielers
      int iPlayer; //Entscheiden um welchen Player es sich handelt
     }
   - Globale Variable, die zwischen Spieler 1 und 2 wechselt
   - Neue Art des eingebens, Koordinate 1 eingeben (anfang), koordinate 2 eingeben (Ende) und automatisch füllen

*/