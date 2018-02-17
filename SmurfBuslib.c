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

    /*
     * закрываем файл
     */

    fclose( info ) ;
}

/*
 * функция изменения положений автобуса с использованием односвязного списка
 */

void Change_Bus_Position_Sll ( Single_List_t *St , int data )
{
    /*
     * создаем поисковый узел
     */

    Single_List_Node_t *node = St->head ;

    /*
     * ищем нужный узел
     */

    while( node && node->value.number != data )
    {
        node = node->adress ;
    }

    /*
     * меняем положение на противоположное
     */

    if (node->value.position == 1 ) node->value.position = 2 ;
    else node->value.position = 1 ;
}

/*
 * функция вывода информации об автобусах в одной из двух позиций из односвязного списка
 */

void Print_Infirmation_Sll( Single_List_t *St , int pos )
{
    /*
     * определяем какие чт выводить
     */

    if ( pos ) printf("In the park right now :\n") ;
    else printf("On the route right now:\n") ;
    pos ++ ;
    /*
     * создаем указатель на узел для вывода
     */

    Single_List_Node_t *node = St->head ;

    while( node )
    {
        /*
         * проверяем на совпадение pos
         */

        if( node->value.position == pos)
        {

            /*
             * выводим значения
             */

            printf("Bus number - %d , route number - %d , " , node->value.number , node->value.Rnumber ) ;
            puts( node->value.driver ) ;
            printf( "\n" ) ;
        }

        /*
         * двигаемся в следующий узел
         */
         node = node->adress ;
    }
}
