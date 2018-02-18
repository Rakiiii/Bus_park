//
// Created by sudar on 2/18/2018.
//

#ifndef BUS_PARK_SMURFBUSLIB_H
#define BUS_PARK_SMURFBUSLIB_H


#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>
#include "SmurfSingleLinkedListLib.h"
#include "SmurfStringlib.h"
#include "SmurfIOlib.h"

Bus_t * Read_Bus_info (int index  ) ;

void ReadBusInfo_fromFile ( Single_List_t *St  ) ;

void Change_Bus_Position_Sll ( Single_List_t *St , int data ) ;

void Print_Information_Sll( Single_List_t *St , int pos ) ;



#endif //BUS_PARK_SMURFBUSLIB_H
