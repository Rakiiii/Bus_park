//
// Created by sudar on 2/18/2018.
//

#include "SmurfStringLib.h"


void ReadString( char *String ) //алгоритм чтения строки из буфера , получает адрес строки по которому будет лежать строка
{
    fflush( stdin ) ;
    char  ch ; //символ для временной записи
    int i = 0 ; //счетчик
    scanf( "%c" , &ch ) ; //читаем первый символ
    while ( ch != '\n' ) //жрем символы из буфера пока нет перехода на слледующую строку
    {
        String[ i ] = ch  ; //кладем прочитанный символ в позицию в строке
        i ++ ; //обновляем счетчик
        scanf( "%c" , &ch ) ; //обновляем символ
    }
    String[ i + 1 ] = '\0' ; //все строки в си должны заканчиваться нулевым символом
    fflush( stdin ) ; //чистим буфер чтения
}


int SearchStringInString(char *MainString , char *String) //исщет в первой строке вторую и возвращает номер начала второй строки в первой ,
// на вход получает адреса главной строки и подстроки
{
    int i = 0 , j = 0 , k = 0 ; //три счетчика
    for ( i = 0 ; MainString[ i ] != '\0' ; i ++ ) //цикл продолжается пока строка не коньчится
    {
        for ( j = i , k = 0 ; String[ k ] != '\0' && MainString[ j ] == String[ k ] ; j ++ , k ++ ) ; //пока строки не закончились и символы под намерами совподают увеличиваем счетчики
        if ( k > 0 && String[ k + 1 ] == '\0' ) //если предыдущий цикл дошел до предпоследнего элемента , то значит совпадение начинается с i элемента строки
            return i ;

    }

    return -1 ;
}

void CopyString( char *MainString , int Start , int End , char *CopiedString ) //копирует подстроку из подстроки по номерам
{
    int j = 0 ; //счетчик
    for( int i = Start ; i <= End ; i ++ ) //цикл отвечающий за копированние
    {
        CopiedString[ j ] = MainString [ i ] ; //само копированние, происходит по символьно
        j ++ ;
    }
    CopiedString [ j + 1 ] = '\0' ; //закрываем строку нулевым элементом , как этого требует си
}



void ConnectString( char *String1 , char *String2 , char *MainString ) //соеденяет две строки в одну
// на вход получает адреса строк для объеденения и адрес строки в которой должен быть результат
{
    strncat( MainString , String1 , strlen( String1 ) ) ; //засовываем в резулбтирующую строку все кроме нулевого элемента
    strcat( MainString , String2 ) ; //засовываем всю строку чтобы не прибовлять нулевой элемент заного
}

void ReverseString( char *String ) //печать строки в обратном порядке
// на вход получает адрес строки
{
    for( int i = strlen( String ) - 2 ; i >= 0 ; i -- ) //цикл для выведения всего кроме нулевого элемента
    {
        printf("%c" , String[ i ]);
    }
    printf("\n");
}

int StringToNumber( char *String )//преобразование строки в число
{
    int Number = 0 ;  //конечное число
    int i = 0 ; //счетчик
    int Sign = 0 ; //знак
    if ( String[i] == '-' ) //определяем знак
    {
        Sign = 1 ;
        i ++ ;
    }
    while ( String[ i ] >= 0x30 && String[ i ] <= 0x39 ) //преобразовываем на основе ASKII
    {
        Number = Number + ( String[ i ] & 0x0F );
        Number = Number * 10 ;
        i ++ ;
    }
    Number = Number / 10 ;
    if ( Sign == 1 )
        Number = -Number ; //разбираемся со знаком
    return Number ;
}

char* NumberToString( int Number ) // преобразование числа в строку
{
    char* String = ( char* )malloc( 255 * sizeof( char ) ) , t , *Temp;// делаем Два указателя из одного сразу массив, и переменную для обмена
    int i = 0 , k = Number ,  Sign = 0 ; // считчик, копия числа , и опрделитель знака
    if( k < 0 ) //определяем знак
    {
        Sign = 1 ;
        k = -k ;
    }
    do {
        t = k % 10 ; //разбираем копию числа
        k = k / 10 ;
        String[ i ] = t | 0x30 ; //преобразовываем на основе ASKII
        i ++ ;
    }while( k > 0 ) ;
    if ( Sign == 1 )//разбираемяся со знаком
    {
        String[ i ] = '-' ;
        i ++ ;
    }
    Temp = ( char* )malloc( i * sizeof( char ) );// т.к. строка перевернута создаем еще одну для удобства переворачивания
    k = 0 ;
    i -- ;
    while( i >= 0 )// переыорачиваем строку
    {
        Temp[ k ] = String [ i ] ;
        i ++ ;
        k -- ;
    }
    Temp[ k ] = '\0' ;
    return Temp ;
}


