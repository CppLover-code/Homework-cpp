/*  Задание 1
    Написать программу, которая даёт возможность пользователю 
    ввести 5 фамилий студентов, а потом сортирует их по возрастанию.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

size_t SIZE = 5;                                            // максимальное кол-во записей в списке
char** list;                                                // указатель на ресурс списка

void print_list();                                          // функция вывода списка в консоль
void add_surname(const char* surname);                      // функция добавления фамилии в список
void input_surname();                                       // функция, выполняющая взаимодействие с пользователем (получение данных)
void sort_list();                                           // функция сортировки данных по возрастанию

int main()
{
    list = new char* [SIZE]; 
    for (size_t i = 0; i < SIZE; i++) {
        list[i] = new char [1];
        list[i][0] = NULL;
    }
    cout << " Surname list\n\n";

    input_surname();
    //print_list();  
    sort_list();

    return 0;
}

void print_list()                                            // функция вывода списка в консоль
{
    cout << "No\tSurname\t\n";                               // "шапка" списка

    for (size_t i = 0; i < SIZE; i++)
        cout << (i + 1) << '\t' << list[i] << "\n";
    cout << "\n";
}

void add_surname(const char* surname)                        // функция добавления фамилии в список
{
    if (surname == NULL)                                     // проверка на NULL
    {
        cout << "NULL-argument in add_surname()";
        return;
    }

    size_t i = 0;
    while (i < SIZE && list[i][0] != NULL) ++i;

    list[i] = new char[strlen(surname) + 1];                 // копируем, выделяем новую память 
    strcpy(list[i], surname);                                // и переносим данные, которые ввёл пользователь
}

void input_surname()                                         // функция, выполняющая взаимодействие с пользователем (получение данных)
{
    const size_t BUF_SIZE = 100;
    char* surname = new char[BUF_SIZE];                      // выделение памяти для записи данных от пользователя

    size_t i = 0;
    do
    {
        cout << " Enter " << i + 1 << " surname: ";
        cin.getline(surname, BUF_SIZE);
        add_surname(surname);                                // полученные данные отправляем в функцию для записи в массив      
        ++i;
    } while (i < SIZE);
    cout << "\n";
    delete[] surname;
}

void sort_list()                                             // функция сортировки данных по возрастанию
{
    bool restart;                                            // переменная-переключатель
    do
    {
        restart = false;                                     // изменений в списке не было
        for (size_t i = 0; i < SIZE - 1; i++)
        {
            if (list[i] != NULL && list[i + 1] != NULL)      // проверка на NULL 
            {
                if (strcmp(list[i], list[i + 1]) == 1)       // сравниваем соседние эл-ты (если первый эл больше второго, то strcmp возвращает 1)
                {
                    char* tmp_ptr = list[i];                 // меняем местами указатели (обмен значений с помощью указателей) 
                    list[i] = list[i + 1];                   // при помощи временного
                    list[i + 1] = tmp_ptr;                   // указателя char* tmp_ptr                     
                    restart = true;                          // были изменения - нужно перезапустить
                }
            }
        }
    } while (restart);
    cout << "Sorted list of last names:\n";
    print_list();
}


///*  Задание 2
//    Есть 3 двумерных массива A, B, C. Кол-во строк и столбцов
//    вводит пользователь с клавиатуры для каждого из них. Реализовать:
//    1. Создайте одномерный массив, который содержит общие значения
//    для A, B, C.
//    2. Создайте одномерный массив, который содержит уникальные 
//    значения для A, B, C.
//    3. Создайте одномерный массив, который содержит общие значения
//    для A и C.
//    4. Создайте одномерный массив, который содержит отрицательные 
//    значения для A, B, C, без повторений.
//*/
//#include <iostream>
//#include <ctime>
//
//void memory_alloc_2d(int** arr, int rows, int cols)         // функция выделения памяти под массивы внутри массива указателей
//{
//    if (rows == NULL || cols == NULL)                       // проверка на NULL
//    {
//        std::cout << "memory_alloc_2d: argument NULL\n";
//        return;
//    }
//    for (size_t i = 0; i < rows; i++)                       // итерации по массиву указателей
//    {
//        arr[i] = new int[cols];                             // выделение памяти под массивы размером cols
//    }
//}
//
//void fill_2d(int** arr, int rows, int cols)                // функция заполнения двумерного массива случайными числами от -10 до 10
//{
//    if (rows == NULL || cols == NULL)                      // проверка на NULL
//    {
//        std::cout << "fill_2d: argument NULL\n";
//        return;
//    }
//    for (size_t i = 0; i < rows; i++)  
//    {
//        for (size_t j = 0; j < cols; j++)
//        {
//            arr[i][j] = rand() % 20 - 10;
//        }
//    }
//}
//
//void print_2d(int** arr, int rows, int cols)                // функция вывода двумерного массива
//{
//    if (rows == NULL || cols == NULL)                       // проверка на NULL
//    {
//        std::cout << "print_2d: argument NULL\n";
//        return;
//    }
//    for (size_t i = 0; i < rows; i++)  
//    {
//        std::cout << "\t";
//        for (size_t j = 0; j < cols; j++)
//        {
//            std::cout << arr[i][j] << "\t";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "-------------------------------------------------" << "\n";
//}
//
//int* make_arr(size_t n)
//{
//    if (n > 100)                                            // "некий лимит памяти"
//    {
//        return NULL;                                        // превышен "лимит" - возврат NULL как признак ошибки
//    }
//    return new int[n];                                      // выделение реальной памяти
//}
//
//void general(int** arrA, int** arrB, int** arrC,            // функция поиска и записи
//    int* arr1, int rowsA, int colsA, int rowsB,             // общих эл. трёх 2d массивов
//    int colsB, int rowsC, int colsC, int* ax)               // в 1d с повторами
//{
//    if (rowsA == NULL || colsA == NULL || 
//        rowsB == NULL || colsB == NULL || 
//        rowsC == NULL || colsC == NULL)                     // проверка на NULL
//    {
//        std::cout << "general: argument NULL\n";
//        return;
//    }
//
//    for (size_t i = 0; i < rowsA; i++)                      // arrA
//    {
//        for (size_t j = 0; j < colsA; j++)                  // arrA       
//        {
//            bool S = false;                                 // булевские переменные-"переключатели"
//            for (size_t x = 0; x < rowsB; x++)              // arrB
//            {
//                for (size_t y = 0; y < colsB; y++)          // arrB
//                {
//                   
//                    for (size_t k = 0; k < rowsC; k++)      // arrC 
//                    {
//                        for (size_t l = 0; l < colsC; l++)  // arrC 
//                        {
//                           if (arrA[i][j] == arrB[x][y] && 
//                               arrB[x][y] == arrC[k][l] && 
//                               arrA[i][j] == arrC[k][l])    // если элементы массивов А B C одинаковы, то
//                           {
//                               S = true;
//                           }
//                        }
//                    }
//                }
//            }
//            if (S == true)
//            {
//                arr1[*ax] = arrA[i][j];                    // записываем общий элемент в 1d массив
//                *ax = *ax + 1;                             // увеличиваем размер 1d массива на 1
//            }
//        }
//    }  
//}
//
//void unique(int** arr1, int** arr2, int** arr3,            // функция поиска и записи
//    int* arr, int rows1, int cols1, int rows2,             // уникальных эл. трёх 2d массивов с повторами
//    int cols2, int rows3, int cols3, int* bx)
//{
//    if (rows1 == NULL || cols1 == NULL ||
//        rows2 == NULL || cols2 == NULL ||
//        rows3 == NULL || cols3 == NULL)                    // проверка на NULL
//    {
//        std::cout << "unique: argument NULL\n";
//        return;
//    }
//
//    for (size_t i = 0; i < rows1; i++)                     // arr1
//    {
//        for (size_t j = 0; j < cols1; )                    // arr1       
//        {
//            bool S = true;                                 // булевские переменные-"переключатели"
//            bool T = true;
//
//            for (size_t x = 0; x < rows2; x++)             // arr2
//            {
//                for (size_t y = 0; y < cols2; y++)         // arr2 
//                {
//                    if (arr1[i][j] == arr2[x][y])          // если элементы массивов одинаковы,
//                    {
//                        S = false;                         // то меняем значение переменной на противоположное
//                    }   
//                }
//            }
//            for (size_t k = 0; k < rows3; k++)             // arr3 
//            {
//                for (size_t l = 0; l < cols3; l++)         // arr3 
//                {
//                    if (arr1[i][j] == arr3[k][l])          // если элементы массивов одинаковы,
//                    {
//                        T = false;                         // то меняем значение переменной на противоположное
//                    }
//                }
//            }
//            if (S == false || T == false)                  // если сработал "переключатель" (элемент массива  arr1 равен элементу массива arr2 или arr3),              
//            {
//                j++;                                       // то переходим к следющему эл. массива arrA
//            }
//            else
//            {
//                arr[*bx] = arr1[i][j];                     // иначе записываем эл. массива arr1 записываем в 1d массив
//                *bx = *bx + 1;                             // увеличиваем размер 1d массива на 1
//                j++;                                       // и переходим к следющему эл. массива arrA
//            }
//        }
//    }
//}
//
//void general_for_two(int** arrA, int** arrC,                // функция поиска и записи
//    int* arr3, int rowsA, int colsA,                        // общих эл. трёх 2d массивов
//    int rowsC, int colsC, int* сx)                          // в 1d с повторами
//{
//    if (rowsA == NULL || colsA == NULL ||
//        rowsC == NULL || colsC == NULL)                     // проверка на NULL
//    {
//        std::cout << "general_for_two: argument NULL\n";
//        return;
//    }
//
//    for (size_t i = 0; i < rowsA; i++)                      // arrA
//    {
//        for (size_t j = 0; j < colsA; j++)                  // arrA       
//        {
//            bool S = false;                                 // булевские переменные-"переключатели"
//
//            for (size_t x = 0; x < rowsC; x++)              // arrC
//            {
//                for (size_t y = 0; y < colsC; y++)          // arrC
//                {
//                    if (arrA[i][j] == arrC[x][y])           // если элементы массивов одинаковы,
//                    {
//                        S = true;                           // то меняем значение переменной на противоположное
//                    } 
//                }
//            }
//            if (S == true)                                  // если элементы массивов А и C одинаковы, то
//            {
//                arr3[*сx] = arrA[i][j];                     // записываем общий элемент в 1d массив
//                *сx = *сx + 1;                              // увеличиваем размер 1d массива на 1
//            }
//        }
//    }
//}
//    
//void negative(int** arr1, int* arr4, int rows1, int cols1, int* dx)  // функция поиска и записи отрицательных чисел трёх 2d массивов              
//   
//{
//    if (rows1 == NULL || cols1 == NULL)                              // проверка на NULL
//    {
//        std::cout << "negative: argument NULL\n";
//        return;
//    }
//
//    for (size_t i = 0; i < rows1; i++)                      
//    {
//        for (size_t j = 0; j < cols1; j++)                         
//        {
//            if (arr1[i][j] < 0)                                      // если элемент массива меньше 0, то
//            {   
//                arr4[*dx] = arr1[i][j];                              // записываем общий элемент в 1d массив
//                *dx = *dx + 1;                                       // увеличиваем размер 1d массива на 1
//            } 
//        }
//    }
//}
//
//void clean_negative(int* arr4, int* arr4c, int d, int* cdx)
//{
//    if (arr4 == NULL)                                       // проверка на NULL
//    {
//        std::cout << "clean_negative: argument NULL\n";
//        return;
//    }
//
//    for (size_t x = 0; x < d; x++)
//    {
//        bool S = true;
//
//        for (size_t y = x + 1; y < d; y++)                  // чтобы проверить есть ли еще в массиве такое же число (при этом увеличиваем индекс столбца на 1)
//        {
//            if (arr4[x] == arr4[y])                         // если совпадения найдены,
//            {
//                S = false;                                  // то меняем значение переключателя
//            }
//        }
//        if (S == true)                                      // если значение переключателя осталось неизменным (соответственно совпадений нет)
//        {
//            arr4c[*cdx] = arr4[x];                          // записываем общий элемент в 1d массив
//            *cdx = *cdx + 1;                                // увеличиваем размер 1d массива на 1
//        }
//    }
//}
//
//void print_1d(int* arr, int k)                              // функция вывода результирующего 1d массива
//{
//    if (k == 0)                                             // если результирующий массив пуст,
//    {
//        std::cout << " searched numbers not found!!!\n\n";  // то общие эл. отсутствуют
//    }
//    else
//    {
//        for (size_t i = 0; i < k; i++)                      // иначе, выводим общие элементы
//        {
//            std::cout << arr[i] << " ";
//        }
//        std::cout << "\n\n";
//    }
//}
//
//void del_2d(int** arr, int rows, int cols)                  // освобождение памяти 2d массива
//{
//    for (size_t i = 0; i < rows; i++)                       // итерируемся по массиву указателей
//    {
//        delete[] arr[i];                                    // освобождаем память одномерного массива
//    }
//
//    delete[] arr;                                           // освобождаем память массива указателей
//}
//
//int main()
//{
//    srand(time (0));
//
//    std::cout << "Working with three two-dimensional dynamic arrays\n\n";
//
//    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
//
//    std::cout << "Enter the number of rows of array A:\n";
//    std::cin >> rowsA;
//    std::cout << "Enter the number of columns of array A:\n";
//    std::cin >> colsA;
//
//    int** arrA = new int* [rowsA];                            // выделение памяти под массив указателей на одномерные массивы внутри
//    memory_alloc_2d(arrA, rowsA, colsA);
//    fill_2d(arrA, rowsA, colsA);
//    std::cout << "Two-dimensional array A:\n";
//    print_2d(arrA, rowsA, colsA);
//
//    std::cout << "Enter the number of rows of array B:\n";
//    std::cin >> rowsB;
//    std::cout << "Enter the number of columns of array B:\n";
//    std::cin >> colsB;
//
//    int** arrB = new int* [rowsB];                            // выделение памяти под массив указателей на одномерные массивы внутри
//    memory_alloc_2d(arrB, rowsB, colsB);
//    fill_2d(arrB, rowsB, colsB);
//    std::cout << "Two-dimensional array B:\n";
//    print_2d(arrB, rowsB, colsB);
//
//    std::cout << "Enter the number of rows of array C:\n";
//    std::cin >> rowsC;
//    std::cout << "Enter the number of columns of array C:\n";
//    std::cin >> colsC;
//
//    int** arrC = new int* [rowsC];                            // выделение памяти под массив указателей на одномерные массивы внутри
//    memory_alloc_2d(arrC, rowsC, colsC);
//    fill_2d(arrC, rowsC, colsC);
//    std::cout << "Two-dimensional array C:\n";
//    print_2d(arrC, rowsC, colsC);
//
//    int a = 0;              // arr1 size
//    int* ax = &a;
//
//    int b = 0;              // arr2 size
//    int* bx = &b;
//
//    int c = 0;              // arr3 size
//    int* cx = &c;
//
//    int d = 0;              // arr4 size
//    int* dx = &d;
//    int cd = 0;              // arr4 size clean
//    int* cdx = &cd;
//
//    int* arr1 = nullptr;    // массив результатов с общими элементами для A, B, C
//    int* arr2 = nullptr;    // массив результатов с уникальными элементами для A, B, C
//    int* arr3 = nullptr;    // массив результатов с общими элементами для A и С
//
//    int* arr4 = nullptr;    // массив результатов с отрицательными элементами для A, B, C 
//    int* arr4c = nullptr;   // массив результатов с отрицательными элементами для A, B, C без повторений
//
//    arr1 = make_arr(a);
//    arr2 = make_arr(b);
//    arr3 = make_arr(c);
//    arr4 = make_arr(d);
//    arr4c = make_arr(cd);
//
//    general(arrA, arrB, arrC, arr1, rowsA, colsA, rowsB, colsB, rowsC, colsC, ax);
//    std::cout << "A one-dimensional array that contains the general values for A, B, C: ";
//    print_1d(arr1, a);
//
//    unique(arrA, arrB, arrC, arr2, rowsA, colsA, rowsB, colsB, rowsC, colsC, bx);          // вызываем функцию поиска уникальных чисел
//    unique(arrB, arrA, arrC, arr2, rowsB, colsB, rowsA, colsA, rowsC, colsC, bx);          // три раза с различным порядком передачи аргументов,
//    unique(arrC, arrA, arrB, arr2, rowsC, colsC, rowsA, colsA, rowsB, colsB, bx);          // чтобы найти уникальные числа в каждом массиве по очереди
//    std::cout << "A one-dimensional array that contains the unique values for A, B, C: ";
//    print_1d(arr2, b);
//
//    general_for_two(arrA, arrC, arr3, rowsA, colsA, rowsC, colsC, cx);    
//    std::cout << "A one-dimensional array that contains the general values for A, C: ";
//    print_1d(arr3, c);
//
//    negative(arrA, arr4, rowsA, colsA, dx);
//    negative(arrB, arr4, rowsB, colsB, dx);
//    negative(arrC, arr4, rowsC, colsC, dx);
//    clean_negative(arr4, arr4c, d, cdx);
//    std::cout << "A one-dimensional array that contains negative values for A, B, C: ";
//    print_1d(arr4c, cd);
//    
//    // освобождаем память двумерных массивов
//    del_2d(arrA, rowsA, colsA);
//    del_2d(arrB, rowsB, colsB);
//    del_2d(arrC, rowsC, colsC);
//
//    // освобождаем память одномерных массивов
//    delete[] arr1; 
//    delete[] arr2;
//    delete[] arr3;
//    delete[] arr4;
//
//    return 0;
//}
