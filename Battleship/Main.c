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
    //vSetFleet(&PlayerA);
    vPrintBoard(PlayerA.iaBoard);

    //------------ Test Bereich -----------
    vDebugSetShip(&PlayerB);
    vDebugSetShip(&PlayerA);

    system("cls");
    vPrintPlayBoards(PlayerA.iaBoard,PlayerB.iaBoard);

    printf("\n/////////////////////////\n\n");

    vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
    printf("Total Hit Points Player A: %d\n", PlayerA.iTotalHits);
    printf("Total Hit Points Player B: %d\n", PlayerB.iTotalHits);
    
    //------------ Test Bereich -----------
    
    int iWinCondition = 0;

    do 
    {
       int iTreffer = 1;
       //Player A;
       printf("Spieler A turn\n");
       
       while ((iTreffer == 1) && (iWinCondition == 0)) 
       {
           vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
           //vPrintPlayBoards(PlayerA.iaBoard, PlayerB.iaBoard);
          iTreffer = vShoot(&PlayerB);
          
          if (PlayerB.iTotalHits == 0)
          {
              iWinCondition = 1;
          }
       }
       //Transition Screen needed
       iTreffer = 1;
       //Player B;
       printf("Spieler B turn\n");

       while ((iTreffer == 1) && (iWinCondition == 0))
       {
           vPrintPlayBoards(PlayerA.iaBoard, PlayerB.iaBoard);
           //vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
           iTreffer = vShoot(&PlayerA);
           
           if (PlayerA.iTotalHits == 0)
           {
               iWinCondition = 2;
           }
       }
       printf("Reached End\n");
    } while (iWinCondition == 0);    

    if (iWinCondition == 1)
    {
        printf("Player A Wins\n");
    }
    else {
        printf("Player B Wins\n");
    }
    
    // Victory Screen ?


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