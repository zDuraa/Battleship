#include "battleship.h"

void vSwap(int* iFirst, int* iLast) {
	int temp = *iFirst;
	*iFirst = *iLast;
	*iLast = temp;
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

int iCheckShot(int iX, int iY, t_Ship fleet[], int* shipIndex)
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

int iCheckSunkShip(t_Ship fleet[], int index)
{
    int iSunk = 0;
    if ((fleet[index].iShipId == index) && (fleet[index].iHitMarker == fleet[index].iLength))
    {
        iSunk = 1;
    }

    return iSunk;
}