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
//-------------------------------------------------------------------
// Declaration structs, unions, enums, bitfields, typedefs                      
//-------------------------------------------------------------------
typedef struct sShip {
    int length;
    int data[4][1];
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

//extern volatile uint8_t u8Clock_Is;
//extern volatile struct MyTime sSystemTime;
//extern volatile struct MyTime sCurrentMeasurementTime;
//extern volatile struct AllMeasurements sAllMeasurements;
//extern volatile enum StateMeasurement eStateCurrentMeasurement;
extern volatile short int siPlayer;	           // 0 -> player1, 1 -> player2 

//-------------------------------------------------------------------
// Declaration functions                                           
//-------------------------------------------------------------------
void vPrintBoard(int iaBoard[][BOARDLENGTH]);
t_Board vCreateBoard(int iPlayerId);
void vFillFleet(t_Ship fleet[]);
void vSetFleet(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);
void vIntroduction(void);
void systemMessage(char* message);
char vConvertSetup(int iCellValue);
char vConvertPlay(int iCellValue);
void vSetLongShip(int iaBoard[][BOARDLENGTH], int iShipSize);
void vSetShortShip(int iaBoard[][BOARDLENGTH]);
int iGetX(char* message);
int iGetY(char* message);