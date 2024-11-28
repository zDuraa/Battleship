#pragma once
/* Inhalt der Headerdatei battleship.h */
#include "stdint.h"
#include <stdio.h>

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

extern volatile uint8_t u8Clock_Is;
extern volatile struct MyTime sSystemTime;
extern volatile struct MyTime sCurrentMeasurementTime;
extern volatile struct AllMeasurements sAllMeasurements;
extern volatile enum StateMeasurement eStateCurrentMeasurement;
//-------------------------------------------------------------------
// Declaration functions                                           
//-------------------------------------------------------------------
void vPrintBoard(int iaBoard[][BOARDLENGTH]);
void vFillFleet(t_Ship fleet[]);
void vSetShip(t_Ship fleet[], int iaBoard[][BOARDLENGTH]);
void vIntroduction(void);