///*
//    Создайте структуру, которая описывает комплексное число.
//    Реализуйте арифметические операции с комплексными числами:
//    сложение, вычитание, умножение и деление.
//*/
//#include <iostream>
//
//struct complex_number  // именованная структура для комплексных чисел
//{
//    float real;        // поля структуры
//    float imagine;
//};
//
//int main();                                                                  // прототип функции int main();
//void check_data(float x1, float y1, float x2, float y2, char oper);          // прототип функции проверки введенных данных пользователем
//complex_number add_sub(float n1, float n2, char oper);                       // прототип функции выполнения операций '+' '-'
//complex_number mult_div(float x1, float y1, float x2, float y2, char oper);  // прототип функции выполнения операций '*' '/'
//void print_complex_number(complex_number x, complex_number y);               // прототип функции вывода результата в консоль
//void operations(float x1, float y1, float x2, float y2, char oper);          // прототип функции проверки знака операции и выполнение 
//
//
//int main()
//{
//    std::cout << " Operations with complex numbers '+' '-' '*' '/')\n\n";
//
//    float x1, y1;  // исп тип данных float, тк результаты некоторых 
//    float x2, y2;  // операций могут давать вещественные числа
//
//    char oper;
//
//    std::cout << "Enter the real and imaginary part of the first complex number:\n";
//    std::cin >> x1 >> y1;
//    std::cout << "Enter the real and imaginary part of the second complex number:\n";
//    std::cin >> x2 >> y2;
//    std::cout << "Enter a math symbol:\n";
//    std::cin >> oper;
//
//    check_data(x1, y1, x2, y2, oper);
//    operations(x1, y1, x2, y2, oper);
//    
//    return 0;
//}
//
//void check_data(float x1, float y1, float x2, float y2, char oper)                                      // функция проверки введенных данных пользователем
//{
//    std::cout << "\n(" << x1 << (y1 >= 0 ? "+" : "") << y1 << "i) "                                     //вывод введенных данных в виде выражения
//        << oper
//        << " " << "(" << x2 << (y2 >= 0 ? "+" : "") << y2 << "i)";
//
//    if (x1 == 0 && y1 == 0 && (oper == '*' || oper == '/'))                                             // если два числа первого выражения равны нулю и 
//    {
//        std::cout << "\n The real and imaginary parts of the -first- expression are equal to zero.\n"   // знак операции '*' или '/', то выводим предупреждение
//            << " Operation not possible =( Enter all data again!\n\n";
//        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
//    }
//
//    else if (x2 == 0 && y2 == 0 && (oper == '*' || oper == '/'))                                        // если два числа второго  выражения равны нулю и 
//    {
//        std::cout << "\n The real and imaginary parts of the -second- expression are equal to zero.\n"  // знак операции '*' или '/', то выводим предупреждение
//            << " Operation not possible =( Enter all data again!\n\n";
//        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
//    }
//
//    else if (oper != '+' && oper != '-' && oper != '*' && oper != '/')                                  // если введенный знак операции не соответствует указаному,
//    {
//        std::cout << "\n You entered an invalid math symbol! Enter all data again!\n\n";                // выводим предупреждение
//        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
//    }
//}
//
//complex_number add_sub(float n1, float n2, char oper)  // функция выполнения операций '+' '-'
//{
//    complex_number x;                                 // имя структуры исп для объявления объектов
//    switch (oper)                                     // проверяем введенный знак операции и выполняем соответствующие действия
//    {
//    case '+':
//        x.real = n1 + n2;
//        x.imagine = n1 + n2;
//        return x;                                     // возвращаем результат 
//        break;
//    case '-':
//        x.real = n1 - n2;
//        x.imagine = n1 - n2;
//        return x;
//        break;
//    }
//}
//
//complex_number mult_div(float x1, float y1, float x2, float y2, char oper)  // функция выполнения операций '*' '/'
//{
//    complex_number x;                                                       // имя структуры исп для объявления объектов
//
//    float a, b, c, d, e;                                                    // переменные будут хранить результаты
//    a = x1 * x2;                                                            // операций над числами
//    b = y1 * y2;
//    c = y1 * x2;
//    d = x1 * y2;
//    e = x2 * x2 + y2 * y2;
//
//    switch (oper)                                                           // проверяем введенный знак операции и выполняем соответствующие действия
//    {
//    case '*':
//
//        x.real = a - b;
//        x.imagine = c + d;
//
//        return x;
//        break;
//
//    case '/':
//
//        x.real = (a + b) / e;
//        x.imagine = (c - d) / e;
//
//        return x;
//        break;
//    }
//}
//
//void print_complex_number(complex_number x, complex_number y)                           // функция вывода результата в консоль
//{
//    std::cout << " = " << x.real << (y.imagine >= 0 ? "+" : "") << y.imagine << "i\n";  // если мнимое число больше 0, то выводим '+', иначе пустые ""
//}
//
//void operations(float x1, float y1, float x2, float y2, char oper)  // функция проверки знака операции и выполнение 
//{                                                                   // соответствующих функций
//    complex_number numb1, numb2;                                    // действительное и мнимое число
//
//    switch (oper)
//    {
//    case '+':
//        numb1 = add_sub(x1, x2, oper);
//        numb2 = add_sub(y1, y2, oper);
//        print_complex_number(numb1, numb2);
//        break;
//
//    case '-':
//        numb1 = add_sub(x1, x2, oper);
//        numb2 = add_sub(y1, y2, oper);
//        print_complex_number(numb1, numb2);
//        break;
//
//    case '*':
//
//        numb1 = mult_div(x1, y1, x2, y2, oper);
//        numb2 = mult_div(x1, y1, x2, y2, oper);
//        print_complex_number(numb1, numb2);
//        break;
//
//    case '/':
//
//        numb1 = mult_div(x1, y1, x2, y2, oper);
//        numb2 = mult_div(x1, y1, x2, y2, oper);
//        print_complex_number(numb1, numb2);
//        break;
//    }
//}

/*
    Создайте структуру «Автомобиль» (длина, клиренс(высота посадки),
    объём двигателя, мощность двигателя, диаметр колёс, цвет, тип
    коробки передач). Создайте функции для ввода значений, отображения
    значений, поиска значений.
*/
#include <iostream>
#include <Windows.h>
#include "colors.h"
struct car                 // именованная структура для характеристик авто
{
    float length{};        // поля структуры
    float clearance{};
    float volume{};
    float power{};
    float diameter{};
    std::string color{};
    bool type{};

    car() {};
};

car* arr;
int size;

void input_arr()                                                         // функция заполнения массива данными об авто
{
    std::cout << "How many cars do you want to add to the database?\n";  // кол-во характеристик машин будет записано
    std::cin >> size;

    if (size < 1) size = 1;
    arr = new car[size];                                                 // выделение памяти под массив 

    for (int i = 0; i < size; i++)                                       // заполняем массив данными
    {
        std::cout << colors::BLUE_BOLD 
                  << " Car number "
                  << i + 1 << ".\n" 
                  << colors::RESET;

        std::cout << " Enter length: ";
        std::cin >> arr[i].length;

        std::cout << " Enter clearance: ";
        std::cin >> arr[i].clearance;

        std::cout << " Enter volume: ";
        std::cin >> arr[i].volume;

        std::cout << " Enter power: ";
        std::cin >> arr[i].power;

        std::cout << " Enter diameter: ";
        std::cin >> arr[i].diameter;

        std::cout << " Enter color: "; 
        std::cin >> arr[i].color;

        std::cout << " Enter the type of gearbox:\n" 
            << " 0 - automatic\n" 
            << " 1 - mechanical:\n";

        int tp = 0;                                                        // переменная для проверки значения
        std::cin >> tp;
        (tp > 0) ? arr[i].type = true : arr[i].type = false;               // если введенное число больше нуля - 1, иначе - 0
    }
}

void print_rec(int i)                                           // функция вывода данных массива
{
    if (size < 1) std::cout << colors::RED_BRIGHT               // если размер массива меньше 1, то массив не заполнен
                            << " Car details not yet filled!" 
                            << colors::RESET<< "\n";
    else                                                        // иначе выводим данные в консоль
    {
        std::cout << colors::BLUE_BOLD  
                  << " Car number "
                  << i + 1 << "\n" 
                  << colors::RESET

            << "Length           " << arr[i].length    << "\n"
            << "Clearance        " << arr[i].clearance << "\n"
            << "Volume           " << arr[i].volume    << "\n"
            << "Power            " << arr[i].power     << "\n"
            << "Diameter         " << arr[i].diameter  << "\n"
            << "Color            " << arr[i].color     << "\n"
            << "Type of gearbox  ";
        (arr[i].type) ? std::cout << "mechanical\n\n" :         // проверяем булевскую переменную и выводим соотв. данные
            std::cout << "automatic" << "\n\n";
    }
}

void output_arr()                                               // функция вывода данных массива на экран консоли
{
    if (size <= 0) std::cout << colors::RED_BRIGHT              // если размер массива меньше <= 0, то массив не заполнен
                             << " Car details not yet filled!" 
                             << colors::RESET << "\n";

    else for (int i = 0; i < size; i++) print_rec(i);           // иначе выводим на экран консоли
}

int search()                                                    // функция поиска автомобиля по данным
{

    if (size < 1) std::cout << colors::RED_BRIGHT               // если размер массива меньше < 1, то массив не заполнен
                            << " Car details not yet filled!"
                            << colors::RESET << "\n";
    else                                                        // иначе предлагаем выбрать характеристику для поиска
    {
        int menu_s;
        std::cout << "Enter feature number to search\n"
         << "1 - length\n"
         << "2 - clearance\n"                                                                       
         << "3 - volume\n"
         << "4 - power\n"
         << "5 - diameter\n"
         << "6 - type оf gearbox\n"
         << "7 - color\n";

        std::cin >> menu_s;

        //system("pause");
        Sleep(2000);
        system("cls");

        if (menu_s != 6) std::cout << "Enter data to search\n"; 
        else std::cout << "0 - automatic or 1 - mechanical\n";

        float data;                                              // переменная для ввода числовых значений в меню от 1 до 6
        std::string data_color;                                  // переменная для ввода цвета в меню 7

        if (menu_s <= 6) std::cin >> data;                       // если выбор от 1 до 6 - ввод число
        else std::cin >> data_color;                             // иначе цвет авто

        int count_s = 0;                                         // счетчик кол-ва найденных авто

        for (int i = 0; i < size; i++)
        {
            float temp = 0;
            std::string temp_color;

            switch (menu_s)                                      // проверем выбранный пункт меню
            {                                                    // и записываем его значение в временную переменную
            case 1: 
                temp = arr[i].length;
                break; 
            case 2: 
                temp = arr[i].clearance;
                break; 
            case 3: 
                temp = arr[i].volume;
                break; 
            case 4: 
                temp = arr[i].power;
                break; 
            case 5: 
                temp = arr[i].diameter;
                break; 
            case 6: 
                temp = arr[i].type;
                break; 
            case 7: 
                temp_color = arr[i].color;
                break; 
            }

            if (menu_s <= 6)                                     // выводим найденное авто в зависимости от выбранного пункта меню
            {
                if (temp == data) 
                {
                    print_rec(i);
                    count_s++;
                }
            }
            else 
            {
                if (temp_color == data_color)
                {
                    print_rec(i);
                    count_s++;
                }
            }
        }

        return count_s;                                            // возвращаем найденное кол-во авто
    }
    return 0;
}

int main()
{
    system("title Cars data");
    bool work = true;
    int menu;

    do
    {
        std::cout << "MENU\n"
         << "1 - add car details\n"
         << "2 - show car details\n"
         << "3 - data search\n"
         << "Any key - exit\n"
         << "Choose an option: ";
        std::cin >> menu;

        //system("pause");
        Sleep(2000);
        system("cls");

        switch (menu)                                                        // проверяем ввод пользователя
        {                                                                    // и выполняем соотв. функции и действия
        case 1:

            input_arr();
            break;

        case 2:

            output_arr();
            Sleep(2000);
            break;

        case 3:
        {
            int count = search();
            (count < 1) ? std::cout << colors::RED_BRIGHT                    // если функция search() вернула значение < 1, то
                                    << " Car data not found!"                // совпадений не найдено
                                    << colors::RESET << "\n" :

                          std::cout << colors::GREEN_BRIGHT                  // иначе показываем кол-во найденных авто
                                    << "Total found: " << count 
                                    << " car(s)" << colors::RESET << "\n";
            Sleep(2000);
            break;
        }
            
        default:

            work = false;
            break;
        }

        //system("pause");
        Sleep(2000);
        system("cls");

    } while (work);

    delete[] arr;                                                            // освобождение памяти дин. массива

    return 0;
}
