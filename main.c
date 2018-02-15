#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>
#include "library.h"



Bus_t * Read_Bus_info (int index  )
        {
            /*
             * создаем возвращаемый указатель
             * выделяем место под этот элемент
             */

            Bus_t * bus = ( Bus_t * )malloc( sizeof( bus ) ) ;

            printf( "Add number of %d-th bus\n" , i ) ;

            bus->bus_number = In() ;

            printf( "where bus right now: at the park or on the way ?\n1.at the park\n2.On the way\n ") ;

            bus->bus_position = (int)getchar() ;

            printf( "Add name of bus driver_\n") ;

            scanf( "%s" , &bus->bus_driver ) ;

            printf( "Add bus road number_\n" ) ;

            bus->road_number = In() ;

            return bus ;

        }


int main() {

    /*
     * сфорсировать список с автобусами
     */

    printf( "To set infomation about bus park , i need amount of buses in it. Add it_ " ) ;

    int amount_of_buses = In() ;

    /*
     * формируем односвязный список
     */

    Single_List_t *bus_list = create_Single_List () ;

    /*
     * в цикле заполняем список с информацие об автобусах
     */

    for ( int i = 0 ; i < amount_of_buses ; i ++ )
    {
        /*
         * очишаем экран
         */

        system( "cls" ) ;

        /*
         * добовляем новые узлы с автобусами в наш список
         */

        Single_List_push( bus_list , Read_Bus_info( i ) ) ;
    }

    /*
     * меню
     */

    while ( TRUE )
    {

        system ( "cls" ) ;

        printf("\n") ;

        char Choose = getch() ;

        switch ( Choose )

        {

            case '0' :
                return  0  ;

            default: break ;
        }
    }
}