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
         printf("%c ", vConvertSetup(iaBoard[iX][iY]));
      }
      printf("\n");
   }
}

//Puts Ship on Board
void vSetFleet(t_Ship fleet[], int iaBoard[][BOARDLENGTH])
{
   printf("Enter coordinates to place a ship on the board\n");
   for (int i = 0; i < TOTALSHIPS; i++)
   {
      printf("Placing a Ship with the size of %d\n", fleet[i].iLength);
      if (fleet[i].iLength > 1)
      {

         vSetLongShip(iaBoard, fleet, i);
         system("cls");
         vPrintBoard(iaBoard);
      }
      else {

         vSetShortShip(iaBoard, fleet, i);
         system("cls");
         vPrintBoard(iaBoard);
      }
   }
}

void vSetLongShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int index) {
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
         if (iCheckShipSize(iXfirst, iYfirst, iXlast, iYlast, fleet[index].iLength)) {
            // Überprüfe ob Platz frei ist
            if (iCheckFreeSpace(iaBoard, iXfirst, iYfirst, iXlast, iYlast, fleet[index].iLength)) {
               // Platziere das Schiff
               vPlaceShip(iaBoard, iXfirst, iYfirst, iXlast, iYlast, fleet, index);
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

void vSetShortShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int index)
{
   int iX = 0;
   int iY = 0;

   int iErr = 0;

   do {
      iX = iGetX("X Coordinate: ");
      iY = iGetY("Y Coordinate: ");

      if ((iaBoard[iY][iX] == 0) &&
         ((iX == 9) || (iaBoard[iY][iX + 1] == 0)) &&
         ((iX == 0) || (iaBoard[iY][iX - 1] == 0)) &&
         ((iY == 9) || (iaBoard[iY + 1][iX] == 0)) &&
         ((iY == 0) || (iaBoard[iY - 1][iX] == 0)))
      {
         iaBoard[iY][iX] = 1;
         fleet[index].coordinates[0].iColumn = iX;
         fleet[index].coordinates[0].iRow = iY;
         fleet[index].coordinates[0].iIsHit = 0;
         fleet[index].iShipId = index;

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
   fleet[index].iShipId = index;
   index++;

   // • 2 Schiffe der Länge 3
   for (int i = 0; i < 2; i++) {
      fleet[index].iLength = 3;
      fleet[index].iShipId = index;
      index++;
   }

   // • 3 Schiffe der Länge 2
   for (int i = 0; i < 3; i++) {
      fleet[index].iLength = 2;
      fleet[index].iShipId = index;
      index++;
   }

   // • 4 Schiffe der Länge 1
   for (int i = 0; i < 4; i++) {
      fleet[index].iLength = 1;
      fleet[index].iShipId = index;
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

char vConvertSetup(int iCellValue) {
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
   case 7:
      return '!';
      break;
   default:
      return '~';
   }
}

char vConvertPlay(int iCellValue) {
   switch (iCellValue)
   {
   case 4:
      return 'X';
      break;
   case 5:
      return 'M';
      break;
   default:
      return '?';
   }
}

void vSwap(int* iFirst, int* iLast) {
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

void vPlaceShip(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, t_Ship fleet[], int index) {
   int x = 0;
   int y = 0;
   fleet[index].iShipId = index;
   for (int i = 0; i < fleet[index].iLength; i++) {
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
      fleet[index].coordinates[i].iColumn = x;
      fleet[index].coordinates[i].iRow = y;
      fleet[index].coordinates[i].iIsHit = 0;
      iaBoard[y][x] = fleet[index].iLength;
   }
}

int checkShot(int iX, int iY, t_Ship fleet[])
{
   for (int i = 0; i < TOTALSHIPS; i++) { //gehen alle Schiffe durch
      for (int j = 0; j < fleet[i].iLength; j++) { //dann iterrieren wir durch das Schiff, entsprächend seiner länge
         if (fleet[i].coordinates[j].iColumn == iX &&
            fleet[i].coordinates[j].iRow == iY) //und dann überprüfen wir, ob es die Koordinaten enthält, die wir abschießen wollen
         {
            if (fleet[i].coordinates[j].iIsHit == 0) { //Wurde es schon getroffen?
               fleet[i].coordinates[j].iIsHit = 1;
               return 1; // Treffer
            }
            else {
               return 2; // Schon getroffen
            }
         }
      }
      
   }
   return 0; // Kein Treffer / Miss
}

int checkSunkShip(t_Ship fleet[])
{
   int iHitMarker = 0;
   for (int i = 0; i < TOTALSHIPS; i++) 
   {
      for (int j = 0; j < fleet[i].iLength; j++) 
      {
         if (fleet[i].coordinates[j].iIsHit == 1) {
            iHitMarker++;
         }
         else {
            break;
         }

         if (iHitMarker == fleet[i].iLength) {
            fleet[i].iSunk = 1;
            return fleet[i].iSunk;
         }
      }
      iHitMarker = 0;
   }
   return 0;
}

void vDebugSetShip(t_Ship fleet[], int iaBoard[][BOARDLENGTH])
{
   int y = 0;
   int x = 0;
   for (int i = 0; i < TOTALSHIPS; i++) 
   {
      for (int j = 0; j < fleet[i].iLength; j++) {
         fleet[i].coordinates[j].iColumn = x;
         fleet[i].coordinates[j].iRow = y;
         fleet[i].coordinates[j].iIsHit = 0;
         iaBoard[y][x] = fleet[i].iLength;
         x++;
      }
      y++;
   }
}


int vShoot(t_Ship fleet[])
{
   printf("Please enter the coordinate that you want to shoot at\n");
   int iX = iGetX("X Coordinate: ");
   int iY = iGetY("Y Coordinate: ");



   int iTemp = checkShot(iX, iY, fleet);
   int iGoAgain = 0;

   switch (iTemp) {
   case 0:
      printf("Missed\n");
      iGoAgain = 0;
      break;
   case 1:
      printf("Hit\n");
      if (checkSunkShip(fleet) == 1) {
         printf("Ship Sunk!");
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

/*
    Symbol Lexikon:
    0 - ~ Wasser
    1 - d Schiff der größe 1
    2 - s Schiff der größe 2
    3 - c Schiff der größe 3
    4 - b Schiff der größe 4
    5 - X Treffer
    6 - M Daneben
*/