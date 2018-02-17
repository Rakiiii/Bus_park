
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


int main() {

    system( "cls" ) ;

    int loop = 1 ;

    printf("1.Fill with a keyboard\n2.Fill from the file\n0.Exit\n") ;

    while ( loop )
    {

        char Choose = getch();
        switch (Choose)
        {
            case '1' :

            /*
             * узнаем количество автобусов список с автобусами
             */

            printf("To set infomation about bus park , i need amount of buses in it. Add it_ ");

            int amount_of_buses = In();

            /*
             * формируем односвязный список
             */

            Single_List_t *bus_list = create_Single_List();

            /*
             * в цикле заполняем список с информацие об автобусах
             */

            for (int i = 0; i < amount_of_buses; i++)
            {
                /*
                 * очишаем экран
                 */

                system("cls");

                /*
                 * добовляем новые узлы с автобусами в наш список
                 */

                Bus_t *newbus;
                newbus = Read_Bus_info(i);

                Single_List_push(bus_list, *newbus);
            }
                loop = 0 ;
                break ;

            case '2' :

            /*
             * формируем односвязный список
             */

                Single_List_t *bus_list = create_Single_List();

                /*
                 * в цикле заполняем список с информацие об автобусах
                 */

                for (int i = 0; i < amount_of_buses; i++)
                {
                    /*
                     * очишаем экран
                     */

                    system("cls");

                    /*
                     * добовляем новые узлы с автобусами в наш список
                     */

                    Bus_t *newbus;
                    newbus = Read_Bus_info(i);

                    Single_List_push(bus_list, *newbus);
                }

                loop = 0 ;
                break ;
            case '0' :
                return 0 ;
            default: break;
        }
    }
    /*
     * меню
     */

    while ( TRUE )
    {

        system ( "cls" ) ;

        printf("1.\n0.Exit\n") ;

        char Choose = getch() ;

        switch ( Choose )

        {

            case '0' :
                return  0  ;

            default: break ;
        }
    }
}