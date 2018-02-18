//
// Created by sudar on 2/18/2018.
//

#ifndef BUS_PARK_SMURFSTRINGLIB_H
#define BUS_PARK_SMURFSTRINGLIB_H

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>


void ReadString( char *String ) ;

int SearchStringInString(char *MainString , char *String) ;

void CopyString( char *MainString , int Start , int End , char *CopiedString ) ;

void ConnectString( char *String1 , char *String2 , char *MainString ) ;

void ReverseString( char *String ) ;

int StringToNumber( char *String ) ;

char* NumberToString( int Number ) ;



#endif //BUS_PARK_SMURFSTRINGLIB_H
