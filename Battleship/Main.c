#include "battleship.h"

int vPlayerTurn(char* playerName, t_Board* currentPlayer, t_Board* opponentPlayer, int iWinValue);
void vPlayerSetsTheirFleet(t_Board* PlayerA, t_Board* PlayerB);
void vDebugPlacingFleet(t_Board* PlayerA, t_Board* PlayerB);

int main() {
    //-------------------------------------------------------------------
    // Welcome Screen                                                                  
    //-------------------------------------------------------------------
    vIntroduction();
    vSystemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");

    //-------------------------------------------------------------------
    // Spiel Setup                                                                 
    //-------------------------------------------------------------------
    t_Board PlayerA = vCreateBoard(0);
    vFillFleet(PlayerA.fleet);
    t_Board PlayerB = vCreateBoard(1);
    vFillFleet(PlayerB.fleet);
   

    //vPlayerSetsTheirFleet(&PlayerA, &PlayerB);
    vDebugPlacingFleet(&PlayerA, &PlayerB);
    
    int iWinCondition = 0;
    //-------------------------------------------------------------------
    // Spiel Start                                                               
    //-------------------------------------------------------------------
    do
    {
        iWinCondition = vPlayerTurn("Spieler A", &PlayerA, &PlayerB, 1);
        if (iWinCondition == 0) {
            iWinCondition = vPlayerTurn("Spieler B", &PlayerB, &PlayerA, 2);
        }
    } while (iWinCondition == 0);

    //-------------------------------------------------------------------
    // Spiel Ende                                                                 
    //-------------------------------------------------------------------
    if (iWinCondition == 1)
    {
        printf("Player A Wins\n");
    }
    else {
        printf("Player B Wins\n");
    }

    vPrintVictoryScreen(iWinCondition);
    return 0;
}

int vPlayerTurn(char* playerName, t_Board* currentPlayer, t_Board* opponentPlayer, int iWinValue) {
    int iTreffer = 1;
    int iRet = 0;
    printf("%s turn\n", playerName);

    while ((iTreffer == 1) && (iRet == 0))
    {
        vPrintPlayBoards(currentPlayer->iaBoard, opponentPlayer->iaBoard);
        iTreffer = iShoot(opponentPlayer);
        printf("Total Hits of Opponent : %i\n", opponentPlayer->iTotalHits);
        if (opponentPlayer->iTotalHits == 0)
        {
            iRet = iWinValue;
            
        }
    }
    
    if ((iTreffer == 0) && (iRet == 0)) {
        printf("                         Missed Shot, Opponent's turn\n");
    }
    else {
            printf("                            Final Ship sunk!\n");
            printf("                            Game ends!");
    }
    vSystemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");
    return iRet;
}

void vPlayerSetsTheirFleet(t_Board* PlayerA, t_Board* PlayerB) {
    vPrintBoard(PlayerA->iaBoard);
    vSetFleet(PlayerA);
    vPrintBoard(PlayerA->iaBoard);

    printf("All Ships have been placed!\n");
    printf("Switching to Player B!\n");
    vSystemMessage("                            Hit <ENTER> to continue!\n");

    vPrintBoard(PlayerB->iaBoard);
    vSetFleet(PlayerB);
    vPrintBoard(PlayerB->iaBoard);

    printf("All Ships have been placed!\n");
    printf("Starting Game!\n");
    vSystemMessage("                            Hit <ENTER> to continue!\n");
}

void vDebugPlacingFleet(t_Board* PlayerA, t_Board* PlayerB) {
    vDebugSetShip(PlayerB);
    vDebugSetShip(PlayerA);
}