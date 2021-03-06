#include "SmurfBuslib.h"


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
                 * чистим консоль
                 */

                system( "cls" ) ;

                /*
                 * предупреждаем о необходимости соответствия файла шаблону
                 */

                printf( "Are your file correspond to this template:\n"
                                "Bus number\n"
                                "Bus route number\n"
                                "Bus position(1-equivalent position at the park, 2- equivalent to the route)\n"
                                "Bus driver surname and initials\n");
                printf("1.Yep\n2.no\n") ;
                fflush( stdin ) ;

                char right = getch() ;
                fflush( stdin ) ;
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

        printf(        "1.Bus come back to the park\n"
                       "2.Bus come back to the rout\n"
                       "3.Show the information about buses on the rout\n"
                       "4.Show the information about buses in the park\n"
                       "5.Add new bus\n"
                       "0.Exit\n") ;

        char Choose = getch() ;

        switch ( Choose )

        {
            case '1' :

                system( "cls" ) ;

                printf( "Add number of the backed bus_  ") ;

                int index = In() ;

                /*
                 * меняем положение автобуса
                 */

                Change_Bus_Position_Sll( bus_list , index ) ;
                break ;
            case '2' :
                system ( "cls" ) ;

                printf( "Add number of the backed to the route bus_  ") ;

                int indeX= In() ;

                /*
                 * меняем положение автобуса
                 */

                Change_Bus_Position_Sll( bus_list , indeX ) ;
                break ;
            case '3' :

                Print_Information_Sll( bus_list , 1 ) ;

                printf("Press any button to continue_ ") ;
                getch() ;
                break ;
            case '4' :

                Print_Information_Sll( bus_list , 0 ) ;

                printf("Press any button to continue_ ") ;
                getch() ;
                break ;
            case '5' :

                /*
              * очишаем экран
              */

                system("cls");

                /*
                 * добовляем новые узлы с автобусами в наш список
                 */

                Bus_t *newbus;
                newbus = Read_Bus_info(0);

                Single_List_push(bus_list, *newbus);

                break ;
            case '0' :
                return  0  ;

            default: break ;
        }
    }
}