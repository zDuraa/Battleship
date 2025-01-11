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
   

    vPlayerSetsTheirFleet(&PlayerA, &PlayerB);
    //vDebugPlacingFleet(&PlayerA, &PlayerB);
    
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

/// <summary>
/// Handles what happens at each player turn
/// </summary>
/// <param name="playerName">The current Players name</param>
/// <param name="currentPlayer">the current Player</param>
/// <param name="opponentPlayer">the current Opponent</param>
/// <param name="iWinValue">The Value that will be assigned, if a player meets the conditions for a win</param>
/// <returns></returns>
int vPlayerTurn(char* playerName, t_Board* currentPlayer, t_Board* opponentPlayer, int iWinValue) {
    int iTreffer = 1;
    int iRet = 0;
    printf("[ Current Player: %s ]\n", playerName);

    while ((iTreffer == 1) && (iRet == 0)) //Solange wir Schiffe treffen und unser Return keinen anderen Wert annimmt, besteht der loop
    {
        vPrintPlayBoards(currentPlayer->iaBoard, opponentPlayer->iaBoard);
        iTreffer = iShoot(opponentPlayer); //Wir Überprüfen ob wir weiterhin treffen
        if (opponentPlayer->iTotalHits == 0) //Sollten wir im Verlauf des Spieles alle Schiffe getroffenhaben
        {
            iRet = iWinValue; //So wird die WinCodition übergeben und der loop beendet
            
        }
    }
    
    //Derp print für keinen Treffer (iTreffer == 0) && (iRet == 0) und für die WinCodition (iTreffer == 1) && (iRet == 1)
    if ((iTreffer == 0) && (iRet == 0)) {
        printf("                         Missed Shot, Opponent's turn\n");
    }
    else {
            printf("                            Final Ship sunk!\n");
            printf("                            Game ends!\n");
    }
    vSystemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");
    return iRet;
}

/// <summary>
/// Handles the placing of the Ships
/// </summary>
/// <param name="PlayerA">Player A</param>
/// <param name="PlayerB">Player B</param>
void vPlayerSetsTheirFleet(t_Board* PlayerA, t_Board* PlayerB) {
    //Spieler A sein Brett wird ausgegeben und darauf PLatziert er seine Schiffe
    vPrintBoard(PlayerA->iaBoard);
    vSetFleet(PlayerA);
    system("cls");
    vPrintBoard(PlayerA->iaBoard);
    printf("All Ships have been placed!\n");

    //Dann werden alle Schiffe von Spieler B Platziert
    printf("Switching to Player B!\n");
    vSystemMessage("                            Hit <ENTER> to continue!\n");

    system("cls");
    vPrintBoard(PlayerB->iaBoard);
    vSetFleet(PlayerB);
    system("cls");
    vPrintBoard(PlayerB->iaBoard);
    printf("All Ships have been placed!\n");

    //Darauf wird die Setup Phase beendet
    printf("Starting Game!\n");
    vSystemMessage("                            Hit <ENTER> to continue!\n");
    system("cls");

}

/// <summary>
/// Automatically Places Ships on the field
/// </summary>
/// <param name="PlayerA">Player A</param>
/// <param name="PlayerB">Player B</param>
void vDebugPlacingFleet(t_Board* PlayerA, t_Board* PlayerB) {
    vDebugSetShip(PlayerB);
    vDebugSetShip(PlayerA);
}