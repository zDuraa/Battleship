#include "battleship.h"

void vPlayerTurn(char* playerName, t_Board* currentPlayer, t_Board* opponentPlayer, int* iWinCondition, int iWinValue);
int main() {
    vIntroduction();
    vSystemMessage("                            Hit <ENTER> to continue!\n");
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
    system("cls");
    //------------ Test Bereich -----------
    
    int iWinCondition = 0;

    //do 
    //{
    //   int iTreffer = 1;
    //   //Player A;
    //   printf("Spieler A turn\n");
    //   
    //   while ((iTreffer == 1) && (iWinCondition == 0)) 
    //   {
    //       vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
    //       //vPrintPlayBoards(PlayerA.iaBoard, PlayerB.iaBoard);
    //      iTreffer = iShoot(&PlayerB);
    //      
    //      if (PlayerB.iTotalHits == 0)
    //      {
    //          iWinCondition = 1;
    //          break;
    //      }
    //   }
    //   //Transition Screen needed
    //   printf("                         Missed Shot, Opponent's turn\n");
    //   vSystemMessage("                            Hit <ENTER> to continue!\n");
    //   system("cls"); //Transition


    //   iTreffer = 1;
    //   //Player B;
    //   printf("Spieler B turn\n");

    //   while ((iTreffer == 1) && (iWinCondition == 0))
    //   {
    //       vPrintPlayBoards(PlayerA.iaBoard, PlayerB.iaBoard);
    //       //vPrintPlayBoards(PlayerB.iaBoard, PlayerA.iaBoard);
    //       iTreffer = iShoot(&PlayerA);
    //       
    //       if (PlayerA.iTotalHits == 0)
    //       {
    //           iWinCondition = 2;
    //       }
    //   }
    //   //Transition Screen needed
    //   printf("                         Missed Shot, Opponent's turn\n");
    //   vSystemMessage("                            Hit <ENTER> to continue!\n");
    //   printf("Reached End\n");
    //} while (iWinCondition == 0);    

    do
    {
        vPlayerTurn("Spieler A", &PlayerA, &PlayerB, iWinCondition, 1);
        if (!iWinCondition) {
            vPlayerTurn("Spieler B", &PlayerB, &PlayerA, iWinCondition, 2);
        }
    } while (iWinCondition == 0);

    if (iWinCondition == 1)
    {
        printf("Player A Wins\n");
    }
    else {
        printf("Player B Wins\n");
    }

    // Victory Screen ?
    vPrintVictoryScreen(iWinCondition);
    return 0;
}

void vPlayerTurn(char* playerName, t_Board* currentPlayer, t_Board* opponentPlayer, int* iWinCondition, int iWinValue) {
    int iTreffer = 1;
    printf("%s turn\n", playerName);

    while ((iTreffer == 1) && (iWinCondition == 0))
    {
        vPrintPlayBoards(currentPlayer->iaBoard, opponentPlayer->iaBoard);
        iTreffer = iShoot(currentPlayer);

        if (currentPlayer->iTotalHits == 0)
        {
            *iWinCondition = iWinValue;
            return;
        }
    }
    //Transition Screen needed
    printf("                         Missed Shot, Opponent's turn\n");
    vSystemMessage("                            Hit <ENTER> to continue!\n");
    system("cls"); //Transition
}