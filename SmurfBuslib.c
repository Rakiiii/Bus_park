#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>
#include "SmurfSingleLinkedListLib.h"
#include "Include_and_constants.h"
#include "SmurfSingleLinkedListLib.c"
#include "SmurfStringLib.c"


Bus_t * Read_Bus_info (int index  )
{
    /*
     * создаем возвращаемый указатель
     * выделяем место под этот элемент
     */

    Bus_t * bus = ( Bus_t * )malloc( sizeof( Bus_t ) ) ;
    bus->driver = ( char * )malloc( sizeof( char ) * 20 ) ;

    fflush( stdin ) ;

    printf( "Add number of %d-th bus\n" , index + 1 ) ;

    bus->number = In() ;

    printf( "Add name of bus driver_\n") ;

    ReadString( bus->driver ) ;

    printf( "Add bus road number_\n" ) ;

    bus->Rnumber = In() ;

    printf( "Where bus right now: at the park or on the way ?\n1.at the park\n2.On the way\n") ;

    bus->position = (int)getch() ;

    return bus ;
}


void ReadBusInfo_fromFile ( Single_List_t *St  )
{

    /*
     * узнать адрес нахождения файла
     */

    char *string = ( char * )malloc( sizeof( char ) * 1024 ) ;

    printf("Add way to your file\n") ;

    ReadString( string ) ;

    /*
     * открыть файл в режиме чтения
     */

    FILE *info ;
    info = fopen( *string , "r" ) ;

    /*
     * выделяем меcто под считываемую информацию
     */

    Bus_t *newBus = ( Bus_t * )malloc( sizeof( Bus_t ) ) ;
    newBus->driver = ( char * )malloc( sizeof( char ) * 33 ) ;

    /*
     * читаем количество автобусов
     */

    int amount = 0 ;
    fscanf( info , "%d" , amount ) ;

    for (int i = 0 ; i < amount ; i ++ )
    {
        /*
         * читаем сначала номер автобуса
         * затем номер маршрута
         * затем местонахождение
         * читаем фамилию и инициалы водителя
         */

        fscanf( info , "%d\n%d\n%d\n" , newBus->number , newBus->Rnumber , newBus->position ) ;
        fgets( newBus->driver , 32 , info );

        /*
         * добовляем новый узел в список
         */

        Single_List_push( St , *newBus ) ;
    }
}
