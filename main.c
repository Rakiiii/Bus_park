
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windef.h>
#include "SmurfSingleLinkedListLib.h"
#include "Include_and_constants.h"
#include "SmurfSingleLinkedListLib.c"
#include "SmurfStringLib.c"
#include "SmurfBuslib.c"






int main()
{

    /*
                         * формируем односвязный список
                         */

    Single_List_t *bus_list = create_Single_List();

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
                 * предупреждаем о необходимости соответствия файла шаблону
                 */

                printf( "Are your file correspond to this template:\n"
                                "Bus number\n"
                                "Bus route number\n"
                                "Bus position(1-equivalent position at the park, 2- equivalent to the route)\n"
                                "Bus driver surname and initials\n");
                printf("1.Yep\n2.no\n") ;

                char right = getch() ;
                switch( right ) {
                    case '1' :

                        /*
                         * читаем из файла
                         */

                        ReadBusInfo_fromFile( bus_list ) ;

                        loop = 0;
                        break;

                    case '2' : break ;
                    default: break ;
                }
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