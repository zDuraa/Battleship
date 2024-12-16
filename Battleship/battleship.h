#pragma once
/* Inhalt der Headerdatei battleship.h */
#include "stdint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
//Lib and packages includes


//-------------------------------------------------------------------
// defines                                                                   
//-------------------------------------------------------------------
#define BOARDLENGTH 10
#define TOTALSHIPS 10              
#define MAX_SHIP_SIZE 4
//-------------------------------------------------------------------
// Declaration structs, unions, enums, bitfields, typedefs                      
//-------------------------------------------------------------------
typedef struct coordinate {
	int   iRow;
	int   iColumn;
   int   iIsHit;
} Coordinate;

typedef struct sShip {
    int iLength;                           // Länge des Schiffes
    int iSunk;
    Coordinate coordinates[MAX_SHIP_SIZE];
    int iShipId;
} t_Ship;

typedef struct sBoard {
    int iaBoard[BOARDLENGTH][BOARDLENGTH];
    int iPlayer;
    t_Ship fleet[TOTALSHIPS];
} t_Board;



typedef struct cell {
	char       symbol;
	Coordinate position;
} Cell;
//-------------------------------------------------------------------
// externals                                                      
//-------------------------------------------------------------------
// Declaration system globals

extern short int siPlayer;	           // 0 -> player1, 1 -> player2 

//-------------------------------------------------------------------
// Declaration functions                                           
//-------------------------------------------------------------------
t_Board vCreateBoard(int iPlayerId);

void vPrintBoard(int iaBoard[][BOARDLENGTH]);
void vPrintPlayBoards(int iaBoard[][BOARDLENGTH], int ibBoard[][BOARDLENGTH]);
void vFillFleet(t_Ship fleet[]);
void vSetFleet(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);
void vIntroduction(void);
void systemMessage(char* message);
void vSetLongShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int index);
void vSetShortShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int index);
void vSwap(int* iFirst, int* iLast);
void vSetLongShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int i);
void vSetShortShip(int iaBoard[][BOARDLENGTH], t_Ship fleet[], int i);
void vPlaceShip(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, t_Ship fleet[], int index);
void vDebugSetShip(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);

char vConvertSetup(int iCellValue);
char vConvertSetupEnemy(int iCellValue);
char vConvertPlay(int iCellValue);

int iGetX(char* message);
int iGetY(char* message);
int iCheckShipSize(int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int iCheckFreeSpace(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int checkSunkShip(t_Ship fleet[]);
int checkShot(int iX, int iY, t_Ship fleet[]);
int vShoot(t_Board *Enemy);

