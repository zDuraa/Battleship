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
    int iHitMarker;
    int iShipId;
} t_Ship;

typedef struct sBoard {
    int iaBoard[BOARDLENGTH][BOARDLENGTH];
    int iPlayer;
    t_Ship fleet[TOTALSHIPS];
    int iTotalHits;
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
void vSetFleet(t_Board* Player);
void vIntroduction(void);
void systemMessage(char *message);
void vSetLongShip(t_Board *Player, int index);
void vSetShortShip(t_Board *Player, int index);
void vSwap(int* iFirst, int *iLast);
void vPlaceShip(t_Board *Player, int iXfirst, int iYfirst, int iXlast, int iYlast, int index);
void vSetShipToSunk(t_Board *Enemy, int iShipIndex);
void vDebugSetShip(t_Board *Player);

char cConvertSetup(int iCellValue);
char cConvertSetupEnemy(int iCellValue);

int iGetX(char* message);
int iGetY(char* message);
int iCheckShipSize(int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int iCheckFreeSpace(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int checkSunkShip(t_Ship fleet[], int iIndexOfShip);
int checkShot(int iX, int iY, t_Ship fleet[], int *shipIndex);
int vShoot(t_Board *Enemy);

