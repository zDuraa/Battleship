#include "battleship.h"

/// <summary>
/// Creates the board for a Player by filling up the array and applying an ID 
/// </summary>
/// <param name="iPlayerId">The ID which will be assigned to a board</param>
/// <returns></returns>
t_Board vCreateBoard(int iPlayerId) {
   t_Board PlayerBoard;

   // Initialisiere alle Werte im Array auf 0
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         PlayerBoard.iaBoard[i][j] = 0;
      }
   }

   PlayerBoard.iPlayer = iPlayerId;
   PlayerBoard.iTotalHits = 0;

   return PlayerBoard;
}

/// <summary>
/// Handles the placing of each ship
/// </summary>
/// <param name="Player">The Player which ships will be placed</param>
void vSetFleet(t_Board *Player)
{
   printf("Enter coordinates to place a ship on the board\n");
   for (int i = 0; i < TOTALSHIPS; i++)
   {
      printf("Placing a Ship with the size of %d\n", Player->fleet[i].iLength);
      if (Player->fleet[i].iLength > 1)
      {
         //Platziere zuerst alle schiffe gr��er als 1
         vSetLongShip(Player, i);
         system("cls");
         vPrintBoard(Player->iaBoard);
      }
      else {

         //Platziere die einser Schiffe
         vSetShortShip(Player, i);
         system("cls");
         vPrintBoard(Player->iaBoard);
      }
   }
}

/// <summary>
/// Handles the placing of Ships by the size >1 and checks for a legal input
/// </summary>
/// <param name="Player">The Player which ships will be placed</param>
/// <param name="index">Index of the Fleet Array</param>
void vSetLongShip(t_Board *Player, int index) {
   int iXfirst, iYfirst, iXlast, iYlast, iErr;

   do
   {
      printf("Please enter the first Ship coordinate\n");
      iXfirst = iGetX("X Coordinate: ");
      iYfirst = iGetY("Y Coordinate: ");

      printf("Please enter the last Ship coordinate\n");
      iXlast = iGetX("X Coordinate: ");
      iYlast = iGetY("Y Coordinate: ");

      iErr = 0;

      // �berpr�fe ob die Koordinaten horizontal oder vertikal ausgerichtet sind
      if ((iYfirst == iYlast) || (iXfirst == iXlast)) {
         // Tausche Werte, falls notwendig
         if (iYfirst == iYlast && iXfirst > iXlast) {
            vSwap(&iXfirst, &iXlast);
         }
         else if (iXfirst == iXlast && iYfirst > iYlast) {
            vSwap(&iYfirst, &iYlast);
         }

         // �berpr�fe den Input auf die  Schiffgr��e
         if (iCheckShipSize(iXfirst, iYfirst, iXlast, iYlast, Player->fleet[index].iLength)) {
            // �berpr�fe ob Platz frei ist
            if (iCheckFreeSpace(Player->iaBoard, iXfirst, iYfirst, iXlast, iYlast, Player->fleet[index].iLength)) {
               // Platziere das Schiff auf das Board
               vPlaceShip(Player, iXfirst, iYfirst, iXlast, iYlast, index);
            }
            else {
               iErr = -1;
               printf("This space is already occupied. Try again.\n");
            }
         }
         else {
            iErr = -1;
            printf("Ship size is incorrect. Try again.\n");
         }
      }
      else {
         iErr = -1;
         printf("Ships must be placed horizontally or vertically. Try again.\n");
      }
   } while (iErr == -1);
}

/// <summary>
/// Handles the placing of Ships by the Size of 1
/// </summary>
/// <param name="Player">The Player which ships will be placed</param>
/// <param name="index">Index of the Fleet Array</param>
void vSetShortShip(t_Board *Player, int index)
{
   int iX = 0;
   int iY = 0;

   int iErr = 0;

   do {
      iX = iGetX("X Coordinate: ");
      iY = iGetY("Y Coordinate: ");

      //Wir �berpr�fen ob die Koordinaten g�ltig sind, um ein Einser schiff platzieren zu k�nnen
      if ((Player->iaBoard[iY][iX] == 0) &&
         ((iX == 9) || (Player->iaBoard[iY][iX + 1] == 0)) &&
         ((iX == 0) || (Player->iaBoard[iY][iX - 1] == 0)) &&
         ((iY == 9) || (Player->iaBoard[iY + 1][iX] == 0)) &&
         ((iY == 0) || (Player->iaBoard[iY - 1][iX] == 0)))
      {
          //und verwalten alle ben�tigten Parameter
          Player->iaBoard[iY][iX] = 1;
          Player->fleet[index].coordinates[0].iColumn = iX;
          Player->fleet[index].coordinates[0].iRow = iY;
          Player->fleet[index].coordinates[0].iIsHit = 0;
          Player->fleet[index].iShipId = index;
          Player->fleet[index].iHitMarker = 0;
          Player->iTotalHits++;

         iErr = 0;
      }
      else {
         iErr = -1;
         printf("Place occupied or to close\n");
      }

   } while (iErr == -1);


}

/// <summary>
/// Handles the Size of each ship, the hitmarker and the id
/// </summary>
/// <param name="fleet">Fleet with all Ships in it</param>
void vFillFleet(t_Ship fleet[]) {
   int index = 0;

   // � 1 Schiff der L�nge 4

   fleet[index].iLength = 4;
   fleet[index].iHitMarker = 0;
   fleet[index].iShipId = index;
   index++;

   // � 2 Schiffe der L�nge 3
   for (int i = 0; i < 2; i++) {
      fleet[index].iLength = 3;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }

   // � 3 Schiffe der L�nge 2
   for (int i = 0; i < 3; i++) {
      fleet[index].iLength = 2;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }

   // � 4 Schiffe der L�nge 1
   for (int i = 0; i < 4; i++) {
      fleet[index].iLength = 1;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }
}

/// <summary>
/// Places the Ship into the Player Board
/// </summary>
/// <param name="Player">The Player of the ships/board</param>
/// <param name="iXfirst">First X coordinate</param>
/// <param name="iYfirst">First Y coordinate</param>
/// <param name="iXlast">last X coordinate</param>
/// <param name="iYlast">last Y coordinate</param>
/// <param name="index"> Index of the Fleet Array</param>
void vPlaceShip(t_Board *Player, int iXfirst, int iYfirst, int iXlast, int iYlast, int index) {
   int x = 0;
   int y = 0;
   for (int i = 0; i < Player->fleet[index].iLength; i++) { //wir gehen die gesamte l�nge des Schiffes durch
      if (iYfirst == iYlast) {
         // Horizontales Schiff
         x = iXfirst + i; //und inkrementieren die X koordinate wenn es sich um ein Horizontales Schiff handelt
         y = iYfirst;

      }
      else if (iXfirst == iXlast) {
         // Vertikales Schiff
         x = iXfirst;
         y = iYfirst + i; //oder inkrementieren die Y koordinate wenn es sich um ein Vertikales Schiff handelt
      }
      Player->fleet[index].coordinates[i].iColumn = x; //und �bergeben dem Schiff die Koordinaten
      Player->fleet[index].coordinates[i].iRow = y;
      Player->fleet[index].coordinates[i].iIsHit = 0; //setzen die Hitpunkte auf 0
      Player->iaBoard[y][x] = Player->fleet[index].iLength;
      Player->iTotalHits++; //und erh�he die Total Player Hitpoints um die l�nge des schiffes
   }
}

/// <summary>
/// Handles the shooting, if it hits/misses or already shot at ship
/// </summary>
/// <param name="Enemy">The Opponent</param>
/// <returns></returns>
int iShoot(t_Board *Enemy)
{
   int iIndexOfShip = 0;

   printf("Please enter the coordinate that you want to shoot at\n"); //die Koordinate auf die wir schie�en m�chten
   int iX = iGetX("X Coordinate: ");
   int iY = iGetY("Y Coordinate: ");



   int iTemp = iCheckShot(iX, iY, Enemy->fleet, &iIndexOfShip); //�berpr�fen ob wir etwas treffen oder nicht
   int iGoAgain = 0;

   switch (iTemp) {
   case 0: //case wenn wir nicht treffen
      printf("Missed\n");
      iGoAgain = 0;
      Enemy->iaBoard[iY][iX] = 7;
      break;
   case 1: //case wenn wir treffen
      system("cls");
      printf("Hit\n");
      Enemy->iaBoard[iY][iX] = 5;
      Enemy->iTotalHits--;
      if (iCheckSunkShip(Enemy->fleet, iIndexOfShip) == 1) {
         printf("Ship Sunk!\n");
         vSetShipToSunk(Enemy, iIndexOfShip);
      }
      iGoAgain = 1;
      break;
   case 2: //case wenn wir etwas abschie�en, was wir schon getroffen haben
      system("cls");
      printf("Already Hit, go again\n");
      iGoAgain = 1;
      break;
   default:
      printf("Error, schiff wurde nicht getroffen oder verfehlt, h�?\n");    
   }


   return iGoAgain;
}

/// <summary>
/// Marks a Ship as Sunk
/// </summary>
/// <param name="Enemy">The Opponent</param>
/// <param name="iShipIndex">The Ship beeing marked as sunk</param>
void vSetShipToSunk(t_Board* Enemy, int iShipIndex) 
{
    int iY = 0;
    int iX = 0;
    for (int i = 0; i < Enemy->fleet[iShipIndex].iLength; i++)
    {
        iY = Enemy->fleet[iShipIndex].coordinates[i].iRow;
        iX = Enemy->fleet[iShipIndex].coordinates[i].iColumn;
        Enemy->iaBoard[iY][iX] = 6;
    }
}


/// <summary>
///  Automatically Places Ships+
/// </summary>
/// <param name="Player">The Player which ships are beeing placed</param>
void vDebugSetShip(t_Board* Player)
{
   int y = 0;
   int x = 0;
   for (int i = 0; i < 3; i++) 
   {
      for (int j = 0; j < Player->fleet[i].iLength; j++) {
          Player->fleet[i].coordinates[j].iColumn = x;
          Player->fleet[i].coordinates[j].iRow = y;
          Player->fleet[i].coordinates[j].iIsHit = 0;
          Player->iaBoard[y][x] = Player->fleet[i].iLength;
          Player->iTotalHits++;
         x++;
      }
      y++;
   }

   x = 0;
   for (int i = 3; i < TOTALSHIPS; i++)
   {
       for (int j = 0; j < Player->fleet[i].iLength; j++) {
           Player->fleet[i].coordinates[j].iColumn = x;
           Player->fleet[i].coordinates[j].iRow = y;
           Player->fleet[i].coordinates[j].iIsHit = 0;
           Player->iaBoard[y][x] = Player->fleet[i].iLength;
           Player->iTotalHits++;
           x++;
       }
       y++;
   }
}

/*
    Symbol Lexikon:
    0 - ~ Wasser
    1 - d Schiff der gr��e 1
    2 - s Schiff der gr��e 2
    3 - c Schiff der gr��e 3
    4 - b Schiff der gr��e 4
    5 - x Treffer
    6 - X Versenkt
    7 - M Daneben
    8 - ? Unbekannt
*/
