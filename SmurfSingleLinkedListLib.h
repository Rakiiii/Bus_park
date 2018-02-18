//
// Created by sudar on 2/18/2018.
//

#ifndef BUS_PARK_SMURFSINGLELINKEDLISTLIB_H
#define BUS_PARK_SMURFSINGLELINKEDLISTLIB_H


#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>



/*
 * структура описываюшая информацию об автобусах
 */
#pragma pack( push , 1)
typedef  struct _Bus
{
    int number ;
    char *driver ;
    int position ;
    int Rnumber ;
} Bus_t ;
#pragma pack( pop ) ;

/*
 * Структура элементов односвязного спписка
 * обЪявляем новый тип , что б не писсать структуру каждый раз
 */
#pragma pack( push , 1 ) ;
typedef struct _Single_List_Node
{
    Bus_t value ;
    struct _Single_List_Node *adress ;
} Single_List_Node_t ;
#pragma pack( pop )

/*
 * Создаем  структуру односвзяного списка
 * Храним разсер списка
 * Указатель на начало
 * указатель на конец
 */

#pragma pack( push , 1 )
typedef struct _Single_List
{
    /*
     * размер списка
     */

    int size ;

    /*
     * начало списка
     */

    Single_List_Node_t *head ;

    /*
     * конец списка
     */

    Single_List_Node_t *tail ;

} Single_List_t ;
#pragma pack( pop s)

Single_List_t * create_Single_List ( void ) ;

void Single_List_push( Single_List_t *St , Bus_t data );

Bus_t * Single_List_pop ( Single_List_t *St );

void Single_List_push_back ( Single_List_t *St , Bus_t data );

Single_List_Node_t * Single_List_get_prevlast ( Single_List_t *St );

Bus_t * Single_List_pop_back ( Single_List_t *St );

void Single_List_push_nth ( Single_List_t *St , int position , Bus_t data );

Bus_t * Single_List_pop_nth ( Single_List_t *St , int position );



#endif //BUS_PARK_SMURFSINGLELINKEDLISTLIB_H
