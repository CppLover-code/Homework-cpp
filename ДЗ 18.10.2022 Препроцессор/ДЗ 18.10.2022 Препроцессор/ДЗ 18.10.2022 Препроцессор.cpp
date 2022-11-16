#include <iostream>
#include <ctime>
#include "function.h"

#define INTEGER(x,y)  Integer(x, y) //  замена на функцию соответствующего типа
#define FLOAT(x,y)  Float(x, y)     //  аналогично первому
#define CHAR(x,y)  Char(x, y)       //  аналогично первому
#define SIZE  5                     //  размер массива, значение подстваляется вместо SIZE

int main()
{
    srand(time(0));                  
    int* arr1 = new int[SIZE];      //  выделение памяти под массив Int 
    float* arr2 = new float[SIZE];  //  выделение памяти под массив Float
    char* arr3 = new char[SIZE];    //  выделение памяти под массив Char 
    
    int choice;                     //  переменная для выбора пользователя
    std::cout << " What data do you want to work with?\n" 
        << " 1 - integer values\n"
        << " 2 - real values\n"
        << " 3 - character values\n";
    std::cin >> choice;   

    std::cout << " Random array: ";

    switch (choice)                        //  проверяем выбор пользователя
    {
    case 1: INTEGER(arr1, SIZE); break;    //  выполняем соответствующие 
    case 2: FLOAT(arr2, SIZE); break;      //  замены, в зависимости от
    case 3: CHAR(arr3, SIZE); break;       //  выбранного типа данных
    default:                               //  в случае неверного ввода - ошибка
        std::cout << " You have selected the wrong option!\n";
        break;
    }

    delete[] arr1;  //  освобождение памяти
    delete[] arr2;
    delete[] arr3;

    return 0;
}