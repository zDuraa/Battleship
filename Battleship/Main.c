#include "battleship.h"

int main() {
    vIntroduction();
    systemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");

    t_Ship fleet[TOTALSHIPS];
    vFillFleet(fleet);
    t_Board PlayerA = vCreateBoard(0);
    t_Board PlayerB = vCreateBoard(1);
   

    vPrintBoard(PlayerA.iaBoard);
    vSetFleet(fleet, PlayerA.iaBoard);
    vPrintBoard(PlayerA.iaBoard);
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