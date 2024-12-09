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
typedef struct sShip {
    int length;                           // Länge des Schiffes
    int iaCoordinates[MAX_SHIP_SIZE][1];  // (x, y) koordinate des Schiffes
    int iaHits[MAX_SHIP_SIZE];            // 1 = getroffen, 0 = nicht getroffen
    int iSunk;
} t_Ship;

typedef struct sBoard {
    int iaBoard[BOARDLENGTH][BOARDLENGTH];
    int iPlayer;
} t_Board;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;

typedef struct cell {
	char       symbol;
	Coordinate position;
} Cell;
//-------------------------------------------------------------------
// externals                                                      
//-------------------------------------------------------------------
// Declaration system globals

extern volatile short int siPlayer;	           // 0 -> player1, 1 -> player2 

//-------------------------------------------------------------------
// Declaration functions                                           
//-------------------------------------------------------------------
t_Board vCreateBoard(int iPlayerId);
void vPrintBoard(int iaBoard[][BOARDLENGTH]);
void vFillFleet(t_Ship fleet[]);
void vSetFleet(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);
void vIntroduction(void);
void systemMessage(char* message);
void vSetLongShip(int iaBoard[][BOARDLENGTH], int iShipSize, t_Ship fleet[]);
void vSetShortShip(int iaBoard[][BOARDLENGTH]);
void vSwap(int* iFirst, int* iLast);
void vPlaceShip(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize, t_Ship fleet[], int iCurrentShip);
char vConvertSetup(int iCellValue);
char vConvertPlay(int iCellValue);
int iGetX(char* message);
int iGetY(char* message);
int iCheckShipSize(int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int iCheckFreeSpace(int iaBoard[][BOARDLENGTH], int iXfirst, int iYfirst, int iXlast, int iYlast, int iShipSize);
int checkSunkShip(t_Ship fleet[], int iCurrentShip);
int checkShot(int iX, int iY, t_Ship fleet[], int iCurrentShip);