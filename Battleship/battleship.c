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
        printf("Placing a Ship with the size of %d\n", fleet[i].length);
        if (fleet[i].length > 1)
        {
            
            vSetLongShip(iaBoard, fleet[i].length);
            system("cls");
            vPrintBoard(iaBoard);
        }
        else {
            
            vSetShortShip(iaBoard);
            system("cls");
            vPrintBoard(iaBoard);
        }       
    }
}

void vSetLongShip(int iaBoard[][BOARDLENGTH], int iShipSize) {
   int iXfirst, iYfirst, iXlast, iYlast, iErr;

   do {
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

         // �berpr�fe die Schiffgr��e
         if (iCheckShipSize(iXfirst, iYfirst, iXlast, iYlast, iShipSize)) {
            // �berpr�fe ob Platz frei ist
            if (iCheckFreeSpace(iaBoard, iXfirst, iYfirst, iXlast, iYlast, iShipSize)) {
               // Platziere das Schiff
               vPlaceShip(iaBoard, iXfirst, iYfirst, iXlast, iYlast, iShipSize);
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


void vSetShortShip(int iaBoard[][BOARDLENGTH])
{
    int iX = 0;
    int iY = 0;

    int iErr = 0;

    do {
    iX = iGetX("X Coordinate: ");
    iY = iGetY("Y Coordinate: ");

    if ((iaBoard[iX][iY] == 0) && 
       ((iX == 9) || (iaBoard[iX + 1][iY] == 0)) && 
       ((iX == 0) || (iaBoard[iX - 1][iY] == 0)) &&
       ((iY == 9) || (iaBoard[iX][iY + 1] == 0)) &&
       ((iY == 0) || (iaBoard[iX][iY - 1] == 0)))
    {
        iaBoard[iY][iX] = 1;
        iErr = 0;
    }
    else {
        iErr = -1;
        printf("Please try again");
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
            printf("%c is invalid \n",ch);
            break;
        }
        printf("%c \n", ch);
    } while (iY == -1);
    return iY;
}

void vFillFleet(t_Ship fleet[]) {
    int index = 0;

    // � 1 Schiff der L�nge 4

    fleet[index].length = 4;
    index++;

    // � 2 Schiffe der L�nge 3
    for (int i = 0; i < 2; i++) {
        fleet[index].length = 3;
        index++;
    }

    // � 3 Schiffe der L�nge 2
    for (int i = 0; i < 3; i++) {
        fleet[index].length = 2;
        index++;
    }

    // � 4 Schiffe der L�nge 1
    for (int i = 0; i < 4; i++) {
        fleet[index].length = 1;
        index++;
    }
}

//Enter Massage and only after pressing enter, it continous
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

void vPlaceShip(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize) {
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
      iaBoard[y][x] = iShipSize;
   }
}
/*
    Symbol Lexikon:
    0 - ~ Wasser
    1 - d Schiff der gr��e 1
    2 - s Schiff der gr��e 2
    3 - c Schiff der gr��e 3
    4 - b Schiff der gr��e 4
    5 - X Treffer
    6 - M Daneben
*/