//
// Created by sudar on 2/18/2018.
//

#include "SmurfIOlib.h"


int In() //ввод с защитой от юзера
{
    int RightNumber = 0 ;
    while(scanf( "%d" , &RightNumber ) != 1 )
    {
        printf( "Uncorect datatype, print once more_" ) ;
        while( getchar() != '\n' ) ;
    }
    return RightNumber ;
}


int BinaryNumbers( int n , int l ) // преобразование 10 го числа к двоичному
{
    n = abs( n ) ;
    for( int i = l ; i >= 0 ; i-- )
    {
        printf( "%d" , ( n >> i ) & 1) ;
    }
    printf("   ") ;
    return 0 ;
}


int Exponentiation( int  Number, int Exponent ) // возведение в степень
{
    int Result = Number ;
    for( int i = 0 ; i < Exponent ; i++ )
    {
        Result = Result * Number ;
    }
    return Result ;
}

int BinaryLength( int Number )// подсчет количества разрядов в двоичной форме 10 го числа
{
    int Length = 0 ;
    Number = abs( Number ) ;
    while( Number > 0 )
    {
        Number = Number >> 1 ;
        Length ++ ;
    }
    return Length - 1 ;
}
