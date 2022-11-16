//// Задание 1. Дана строка символов. Заменить в ней все пробелы табуляцией.
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//void replace_spaces(char* str); // функция, выполняющая замену пробелов на табуляцию
//
//int main()
//{
//    cout << " Replace all spaces in the string with tabs " << "\n\n";
//
//    const size_t SIZE = 50;  // размер массива с запасом
//    char* str = new char[SIZE];
//
//    cout << "Enter a string: " << "\n";
//
//    cin.getline(str, SIZE);  // ввод всей строки
//   
//    replace_spaces(str);  // замена всех пробелов на табуляцию
//
//    cout << "\nTab result: \n" << str << "\n";
//
//    return 0;
//}
//void replace_spaces(char* str) // функция, выполняющая замену пробелов на табуляцию
//{
//    size_t len = strlen(str);  // определение размера массива
//
//    for (size_t i = 0; i < len; i++)
//    {
//        if (str[i] == ' ') str[i] = '\t';
//    }
//}

// Задание 2. Дана строка символов. Определить количество символов,
// чисел и других символов, присутствующих в строке.
#include <iostream>
#include <string.h>
using namespace std;

void check_symbols(char* str);  // функция, подсчитывающая символы, цифры и др. символы

int main()
{
    cout << "Determine the number of characters, numbers, and other characters in a string\n";

    const size_t SIZE = 50;  // размер массива с запасом
    char* str = new char[SIZE];
    
    cout << "Enter a string: " << "\n";
    
    cin.getline(str, SIZE);  // ввод всей строки
    
    check_symbols(str);
    
    return 0;
}
void check_symbols(char* str)  // функция, подсчитывающая символы, цифры и др. символы
{
    int symbols = 0;
    int numbers = 0;
    int other = 0;

    size_t len = strlen(str);  // определение размера массива
    for (size_t i = 0; i < len; i++) // перебираем элементы массива (строка, введённая пользователем)
    {
        for (size_t s = 65; s <= 90; s++)  // проверка на наличие символов верхнего регистра (ASCII от 65 до 90 вкл-но)
        {
            if (int(str[i]) == s) symbols++;  // int(str[i]) - преобразование символа в число(код в таблице ASCII)
        }

        for (size_t t = 97; t <= 122; t++)  // проверка на наличие символов нижнего регистра (ASCII от 97 до 122 вкл-но)
        {
            if (int(str[i]) == t) symbols++;
        }

        for (size_t n = 48; n <= 57; n++)  // проверка на наличие цифр (ASCII от 48 до 57 вкл-но)
        {
            if (int(str[i]) == n) numbers++;
        }

        other = len - symbols - numbers;  // вычисление кол-ва других символов  
    }
    cout << "\n Characters: " << symbols << "\n Numbers: " << numbers << "\n Other characters: " << other << "\n";
}

//// Задание 3. Подсчитать количество слов в введённом предложении.
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//void check_words(char* str);
//
//int main()
//{
//    cout << "Count the number of words in the given sentence\n";
//    
//    const size_t SIZE = 50;  // размер массива с запасом
//    char* str = new char[SIZE];
//        
//    cout << "Enter a string: " << "\n";
//        
//    cin.getline(str, SIZE);  // ввод всей строки
//   
//    check_words(str);
//
//    return 0;
//}
//void check_words(char* str)
//{
//    int word = 0;
//
//    size_t len = strlen(str);  // определение размера массива
//
//
//    for (size_t i = 0; i < len; i++)
//    {
//        if ((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122) &&                 // если int(str[i]) - это буква И
//            (((int(str[i + 1]) >= 0 && int(str[i + 1]) < 65) || (int(str[i + 1]) >= 90 && int(str[i + 1]) <= 96) ||  // (int(str[i + 1]) - др. символ ИЛИ
//                (int(str[i + 1]) >= 123 && int(str[i + 1]) <= 127) || int(str[i]) == len - 1)))                      // int(str[i]) - это последний символ массива,
//        {
//            word++;                                                                                                  // то кол-во слов увеличиваем
//        }
//        else continue;                                                                                               // иначе - переходим к след. итерации цикла
//    }
//    cout << "\n Words: " << word << "\n";
//}

//// Задание 4. Дана строка символов. Необходимо проверить является ли
//// эта строка палиндромом.
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//void check_string(char* str);
//
//int main()
//{
//    setlocale(0, "rus");
//    cout << "Is the string a palindrome?\n";
//        
//    const size_t SIZE = 50;  // размер массива с запасом
//    char* str = new char[SIZE];
//            
//    cout << "Enter a string: " << "\n";
//            
//    cin.getline(str, SIZE);  // ввод всей строки
//
//    check_string(str);
//
//    return 0;
//}
//void check_string(char* str)
//{
//    size_t len = strlen(str);  // определение размера массива
//    int m = 0;
//
//    for (size_t i = 0; i < len / 2; i++)  // цикл, передирающий массив до половины
//    {
//        if (str[i] == str[len - 1 - i])  // сравниваем символы зеркально. 
//        {
//            m++;                         // символы одинаковые, увеличиваем m
//        }
//        else m = 0;                      // символы разные,  m остается неизменным
//    }
//    if (m > 0)  // символы одинаковые
//    {
//        cout << "\nIt's a palindrome!\n";
//    }
//    else cout << "\nIt's not a palindrome!!!\n";
//}