#include "battleship.h"

void vIntroduction()
{
   printf("=======================================================\n");
   printf("X       X  XXXXX  X        XXXX    XXX   X     X  XXXXX  \n");
   printf("X       X  X      X       X       X   X  XX   XX  X   \n");
   printf("X   X   X  XXXXX  X       X       X   X  X X X X  XXXXX \n");
   printf(" X X X X   X      X       X       X   X  X  X  X  X  \n");
   printf("  X   X    XXXXX  XXXXX    XXXX    XXX   X     X  XXXXX\n");
   printf("=======================================================\n");
   printf("\n\n");
   printf("||R U L E S||\n");
   printf("1. This is a two player game.\n");
   printf("2. Player 1 has to manually input coordinates\n");
   printf("   for the game board\n");
   printf("3. There are four types of ships to be placed by longest length to the\n");
   printf("   shortest; [b] Battleship has 4 cells, [c] Cruiser has 3 cells, \n");
   printf("   [s] Submarine has 2 cells, [d] Destroyer has 1 cell\n");
   printf("4. Afterwards, Player 2 does his input\n");
   printf("5. Player 1 goes first\n");
   printf("6. The game begins as each player tries to sink the ships of the oponent\n");
   printf("7. First player to destroy all ships wins\n\n");
}

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

//prints board
void vPrintBoard(int iaBoard[][BOARDLENGTH]) {
   char caLetters[BOARDLENGTH] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

   // Kopfzeile (Zahlen von 0 bis 9)
   printf("  ");
   for (int i = 0; i < BOARDLENGTH; i++) {
      printf("%d ", i);
   }
   printf("\n");

   // Board-Zeilen mit Buchstaben und Werten
   for (int iX = 0; iX < BOARDLENGTH; iX++) {
      printf("%c ", caLetters[iX]);
      for (int iY = 0; iY < BOARDLENGTH; iY++) {
         printf("%c ", cConvertSetup(iaBoard[iX][iY]));
      }
      printf("\n");
   }
}

void vPrintPlayBoards(int iaBoard[][BOARDLENGTH], int ibBoard[][BOARDLENGTH]){
    char caLetters[BOARDLENGTH] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

    // Kopfzeile (Zahlen von 0 bis 9)
    for (int j = 0; j < 2; j++) {
        printf("  ");
        for (int i = 0; i < BOARDLENGTH; i++) {
            printf("%d ", i);
        }
        printf("\t\t\t");
    }
    printf("\n");

    // Board-Zeilen mit Buchstaben und Werten
    for (int iX = 0; iX < BOARDLENGTH; iX++) {
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%c ", cConvertSetup(iaBoard[iX][iY]));
        }
        printf("\t\t\t");
        printf("%c ", caLetters[iX]);
        for (int iY = 0; iY < BOARDLENGTH; iY++) {
            printf("%c ", cConvertSetupEnemy(ibBoard[iX][iY]));
        }
        printf("\n");
    }
}

//Puts Ship on Board
void vSetFleet(t_Board *Player)
{
   printf("Enter coordinates to place a ship on the board\n");
   for (int i = 0; i < TOTALSHIPS; i++)
   {
      printf("Placing a Ship with the size of %d\n", Player->fleet[i].iLength);
      if (Player->fleet[i].iLength > 1)
      {

         vSetLongShip(Player, i);
         system("cls");
         vPrintBoard(Player->iaBoard);
      }
      else {

         vSetShortShip(Player, i);
         system("cls");
         vPrintBoard(Player->iaBoard);
      }
   }
}

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

      // Überprüfe ob die Koordinaten horizontal oder vertikal ausgerichtet sind
      if ((iYfirst == iYlast) || (iXfirst == iXlast)) {
         // Tausche Werte, falls notwendig
         if (iYfirst == iYlast && iXfirst > iXlast) {
            vSwap(&iXfirst, &iXlast);
         }
         else if (iXfirst == iXlast && iYfirst > iYlast) {
            vSwap(&iYfirst, &iYlast);
         }

         // Überprüfe die Schiffgröße
         if (iCheckShipSize(iXfirst, iYfirst, iXlast, iYlast, Player->fleet[index].iLength)) {
            // Überprüfe ob Platz frei ist
            if (iCheckFreeSpace(Player->iaBoard, iXfirst, iYfirst, iXlast, iYlast, Player->fleet[index].iLength)) {
               // Platziere das Schiff
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

void vSetShortShip(t_Board *Player, int index)
{
   int iX = 0;
   int iY = 0;

   int iErr = 0;

   do {
      iX = iGetX("X Coordinate: ");
      iY = iGetY("Y Coordinate: ");

      if ((Player->iaBoard[iY][iX] == 0) &&
         ((iX == 9) || (Player->iaBoard[iY][iX + 1] == 0)) &&
         ((iX == 0) || (Player->iaBoard[iY][iX - 1] == 0)) &&
         ((iY == 9) || (Player->iaBoard[iY + 1][iX] == 0)) &&
         ((iY == 0) || (Player->iaBoard[iY - 1][iX] == 0)))
      {
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

int iGetX(char* message)
{
   char ch = '\0';
   int iX = -1;

   do {
      printf("%s", message);
      ch = _getch();
      switch (ch)
      {
      case '0':
         iX = 0;
         break;
      case '1':
         iX = 1;
         break;
      case '2':
         iX = 2;
         break;
      case '3':
         iX = 3;
         break;
      case '4':
         iX = 4;
         break;
      case '5':
         iX = 5;
         break;
      case '6':
         iX = 6;
         break;
      case '7':
         iX = 7;
         break;
      case '8':
         iX = 8;
         break;
      case '9':
         iX = 9;
         break;
      default:
         iX = -1;
         printf("%c is invalid \n", ch);
         break;
      }
      printf("%c \n", ch);
   } while (iX == -1);
   return iX;
}

int iGetY(char* message)
{
   char ch = '\0';
   int iY = -1;

   do {
      printf("%s", message);
      ch = _getch();
      switch (ch)
      {
      case 'a':        //Fall-through
      case 'A':        //Fall-through
      case '0':
         iY = 0;
         break;
      case 'b':       //Fall-through
      case 'B':       //Fall-through
      case '1':
         iY = 1;
         break;
      case 'c':       //Fall-through
      case 'C':       //Fall-through
      case '2':
         iY = 2;
         break;
      case 'd':       //Fall-through
      case 'D':       //Fall-through
      case '3':
         iY = 3;
         break;
      case 'e':       //Fall-through
      case 'E':       //Fall-through
      case '4':
         iY = 4;
         break;
      case 'f':       //Fall-through
      case 'F':       //Fall-through
      case '5':
         iY = 5;
         break;
      case 'g':       //Fall-through
      case 'G':       //Fall-through
      case '6':
         iY = 6;
         break;
      case 'h':       //Fall-through
      case 'H':       //Fall-through
      case '7':
         iY = 7;
         break;
      case 'i':       //Fall-through
      case 'I':       //Fall-through
      case '8':
         iY = 8;
         break;
      case 'j':       //Fall-through
      case 'J':       //Fall-through
      case '9':
         iY = 9;
         break;
      default:
         iY = -1;
         printf("%c is invalid \n", ch);
         break;
      }
      printf("%c \n", ch);
   } while (iY == -1);
   return iY;
}

void vFillFleet(t_Ship fleet[]) {
   int index = 0;

   // • 1 Schiff der Länge 4

   fleet[index].iLength = 4;
   fleet[index].iHitMarker = 0;
   fleet[index].iShipId = index;
   index++;

   // • 2 Schiffe der Länge 3
   for (int i = 0; i < 2; i++) {
      fleet[index].iLength = 3;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }

   // • 3 Schiffe der Länge 2
   for (int i = 0; i < 3; i++) {
      fleet[index].iLength = 2;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }

   // • 4 Schiffe der Länge 1
   for (int i = 0; i < 4; i++) {
      fleet[index].iLength = 1;
      fleet[index].iShipId = index;
      fleet[index].iHitMarker = 0;
      index++;
   }
}

//Enter Message and only after pressing enter, it continous
void systemMessage(char* message) {
   char ch = '\0';

   do {
      printf("%s", message);
   } while ((ch = _getch()) != '\r');
}

char cConvertSetup(int iCellValue) {
   switch (iCellValue)
   {
   case 1:
      return 'd';
      break;
   case 2:
      return 's';
      break;
   case 3:
      return 'c';
      break;
   case 4:
      return 'b';
      break;
   case 5:
       return 'x';
       break;
   case 6:
       return 'X';
       break;
   case 7:
       return 'M';
       break;
   default:
      return '~';
   }
}

char cConvertSetupEnemy(int iCellValue) {
    switch (iCellValue)
    {
    case 5:
        return 'x';
        break;
    case 6:
        return 'X';
        break;
    case 7:
        return 'M';
        break;
    default:
        return '?';
    }
}

void vSwap(int *iFirst, int *iLast) {
   int temp = *iFirst;
   *iFirst = *iLast;
   *iLast = temp;
}

int iCheckShipSize(int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize) {
   return (iYfirst == iYlast && iXlast - iXfirst + 1 == iShipSize) ||
      (iXfirst == iXlast && iYlast - iYfirst + 1 == iShipSize);
}

int iCheckFreeSpace(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize) {
   int x = 0;
   int y = 0;
   for (int i = 0; i < iShipSize; i++) {
      if (iYfirst == iYlast) {
         // Horizontales Schiff
         x = iXfirst + i;
         y = iYfirst;
      }
      else if (iXfirst == iXlast) {
         // Vertikales Schiff
         x = iXfirst;
         y = iYfirst + i;
      }

      if (iaBoard[y][x] != 0 ||
         (y > 0 && iaBoard[y - 1][x] != 0) ||
         (y < BOARDLENGTH - 1 && iaBoard[y + 1][x] != 0) ||
         (x > 0 && iaBoard[y][x - 1] != 0) ||
         (x < BOARDLENGTH - 1 && iaBoard[y][x + 1] != 0)) {
         return 0; // Platz ist blockiert
      }
   }
   return 1; // Platz ist frei
}

void vPlaceShip(t_Board *Player, int iXfirst, int iYfirst, int iXlast, int iYlast, int index) {
   int x = 0;
   int y = 0;
   for (int i = 0; i < Player->fleet[index].iLength; i++) {
      if (iYfirst == iYlast) {
         // Horizontales Schiff
         x = iXfirst + i;
         y = iYfirst;

      }
      else if (iXfirst == iXlast) {
         // Vertikales Schiff
         x = iXfirst;
         y = iYfirst + i;
      }
      Player->fleet[index].coordinates[i].iColumn = x;
      Player->fleet[index].coordinates[i].iRow = y;
      Player->fleet[index].coordinates[i].iIsHit = 0;
      Player->iaBoard[y][x] = Player->fleet[index].iLength;
      Player->iTotalHits++;
   }
}

int checkShot(int iX, int iY, t_Ship fleet[], int* shipIndex)
{
   int ret = 0;
   for (int i = 0; i < TOTALSHIPS; i++) { //gehen alle Schiffe durch
      for (int j = 0; j < fleet[i].iLength; j++) { //dann iterrieren wir durch das Schiff, entsprächend seiner länge
         if (fleet[i].coordinates[j].iColumn == iX &&
             fleet[i].coordinates[j].iRow == iY) //und dann überprüfen wir, ob es die Koordinaten enthält, die wir abschießen wollen
         {
            if (fleet[i].coordinates[j].iIsHit == 0) { //Wurde es schon getroffen?
               fleet[i].coordinates[j].iIsHit = 1;
               fleet[i].iHitMarker = fleet[i].iHitMarker + 1;
               
               ret = 1; // Treffer
            }
            else {              
               ret = 2; // Schon getroffen
            }
            *shipIndex = fleet[i].iShipId;
         }
      }
      
   }
   return ret; // Kein Treffer / Miss
}

int checkSunkShip(t_Ship fleet[], int index)
{
    int iSunk = 0;
         if ((fleet[index].iShipId == index) && (fleet[index].iHitMarker == fleet[index].iLength)) 
         {
            iSunk = 1;
         }
   
   return iSunk;
}

int vShoot(t_Board *Enemy)
{
   int iIndexOfShip = 0;

   printf("Please enter the coordinate that you want to shoot at\n");
   int iX = iGetX("X Coordinate: ");
   int iY = iGetY("Y Coordinate: ");



   int iTemp = checkShot(iX, iY, Enemy->fleet, &iIndexOfShip);
   int iGoAgain = 0;

   switch (iTemp) {
   case 0:
      printf("Missed\n");
      iGoAgain = 0;
      Enemy->iaBoard[iY][iX] = 7;
      break;
   case 1:
      printf("Hit\n");
      Enemy->iaBoard[iY][iX] = 5;
      Enemy->iTotalHits--;
      if (checkSunkShip(Enemy->fleet, iIndexOfShip) == 1) {
         printf("Ship Sunk!\n");
         vSetShipToSunk(Enemy, iIndexOfShip);
      }
      iGoAgain = 1;
      break;
   case 2:
      printf("Already Hit, go again\n");
      iGoAgain = 1;
      break;
   default:
      printf("Error, schiff wurde nicht getroffen oder verfehlt, hä?\n");    
   }


   return iGoAgain;
}

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
    1 - d Schiff der größe 1
    2 - s Schiff der größe 2
    3 - c Schiff der größe 3
    4 - b Schiff der größe 4
    5 - x Treffer
    6 - X Versenkt
    7 - M Daneben
    8 - ? Unbekannt
*/

/*
    Nochmal Schiessen erlauben wenn ein feld getroffen wird das bereits abgeschossen wurde und Daneben war ?
    mögliche addition zu checkShot ?
*/