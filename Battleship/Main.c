#include "battleship.h"

int main() {
    vIntroduction();
    systemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");

    
    t_Board PlayerA = vCreateBoard(0);
    vFillFleet(PlayerA.fleet);
    t_Board PlayerB = vCreateBoard(1);
    vFillFleet(PlayerB.fleet);
   

    vPrintBoard(PlayerA.iaBoard);
   // vSetFleet(PlayerA.fleet, PlayerA.iaBoard);
    vPrintBoard(PlayerA.iaBoard);

    //------------ Test Bereich -----------
    vDebugSetShip(PlayerB.fleet, PlayerB.iaBoard);

    system("cls");
    vPrintBoard(PlayerB.iaBoard);
    printf("///////////////////////////////////////////\n");
    vPrintBoard(PlayerA.iaBoard);
    //------------ Test Bereich -----------
    
    while (1) //Noch keine Win Condition
    {
       int iTreffer = 0;
       //Player A;
       printf("Spieler A turn\n");
       do {
          iTreffer = vShoot(PlayerB.fleet);
       } while (iTreffer == 1);
       printf("Reached End\n");
    }




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