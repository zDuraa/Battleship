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
    vPrintPlayBoards(PlayerA.iaBoard,PlayerB.iaBoard);

    printf("\n/////////////////////////\n\n");

    vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
    
    //------------ Test Bereich -----------
    
    while (1) //Noch keine Win Condition
    {
       int iTreffer = 0;
       //Player A;
       printf("Spieler A turn\n");
       for (int i = 0; i < 4; i++)
       {
           printf("X-Coord: %d      Y-Coord: %d\n",PlayerB.fleet->coordinates[i].iColumn, PlayerB.fleet->coordinates[i].iRow);
       }
       do {
          iTreffer = vShoot(&PlayerB);
          vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
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