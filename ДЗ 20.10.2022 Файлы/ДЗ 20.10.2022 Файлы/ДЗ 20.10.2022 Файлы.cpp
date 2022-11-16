/*
    Даны два текстовых файла. Определить, совпадают ли
    их строки.Если нет, то вывести строку, которая не 
    совпадает, с каждого файла.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main()
{
    std::cout << " Determine if strings in two files are the same.\n\n";

    FILE* f1;
    FILE* f2;

    f1 = fopen("Text1.txt", "rt");                      // открываем файлы для чтения
    f2 = fopen("Text2.txt", "rt");
    
    if (!f1)                                            // если f1 невозможно открыть
    {
        std::cout << 
            "File \"Text1.txt\" open error!\n";         // сообщаем об ошибке
        return -1;
    }
    if (!f2)                                            // если f1 невозможно открыть
    {
        std::cout << 
            "File \"Text2.txt\" open error!\n";         // сообщаем об ошибке
        return -1;
    }
    const size_t size = 50;                             // макс длина строки
    char str1[size];                                    // буфер 1 для строки из 1 файла
    char str2[size];                                    // буфер 2 для строки из 2 файла
    bool flag = false;                                  // переменная для проверки случая, если все строки совпали
    
    while (!feof(f1))                                   // пока не конец файла, сравниваем два файла
    {
        fgets(str1, size, f1);                          // считываем символы в строку из файла "Text1.txt"
        fgets(str2, size, f2);                          // считываем символы в строку из файла "Text2.txt"
        if (_stricmp(str1, str2) != 0)                  // если строки не равны нулю, значит они разные
        {
            flag = true;
            std::cout << " Different strings:\n"        // выводим искомые строки
                << "1-st file: " << str1 << std::endl
                << "2-nd file: " << str2 << std::endl;
        } 
    }
    if (!flag) std::cout                                // если все строки совпали - выводим сообщение
        << " Strings from both files are equal!\n"; 
   
    fclose(f1);                                         // закрываем файлы - освобождаем системный ресурс
    fclose(f2);
    return 0;
}

/*
    Дан текстовый файл. Необходимо создать 
    новый файл и записать в него статистику:
    ■ Количество символов;
    ■ Количество строк;
    ■ Количество гласных;
    ■ Количество согласных;
    ■ Количество цифр.
*/

int main2()
{
    std::cout << " You can see the statistics of a text file in the file!\n\n";

    FILE* f1;
    FILE* f2;

    f1 = fopen("fole.txt", "rt");                      // открываем файл для чтения
    f2 = fopen("Stat.txt", "wt");                      // открываем файл для записи

    if (!f1)                                           // если f1 невозможно открыть
    {
        std::cout <<
            "File \"fole.txt\" open error!\n";         // сообщаем об ошибке
        return -1;
    }
    if (!f2)                                           // если f1 невозможно открыть
    {
        std::cout <<
            "File \"Stat.txt\" open error!\n";         // сообщаем об ошибке
        return -1;
    }
    const size_t size = 50;                            // макс длина строки
    char str [size];                                   // буфер для строки из 1 файла
    
    char vow[6] = { 'A', 'E','I','O','U','Y' };        // массив гласных букв

    int letter = 0;                                    // переменная для счета букв
    int symbol = 0;
    int string = 0;
    int vowel  = 0;
    int cons   = 0;
    int digit  = 0;

    fgets(str, size, f1);                                           // считываем символы в строку из файла "fole.txt"
    while (!feof(f1))                                               // пока не конец файла
    {
        
        //std::cout << str << "\n";                                 // выводим файл в консоль
        size_t len = strlen(str);                                   // определение размера массива символов

        for (size_t i = 0; i < len; i++)                            // перебираем элементы массива символов str
        {
            if (int(str[i]) >= 32 && int(str[i]) <= 126) symbol++;  // если элемент массива входит в диапазон - это символ

            if ((int(str[i]) >= 65 && int(str[i]) <= 90) ||         // если элемент массива входит в диапазон - это буква
                (int(str[i]) >= 97 && int(str[i]) <= 122))
            {
                for (size_t v = 0; v < 6; v++)                      // запускаем цикл для поиска гласных
                {
                    if ((int(str[i]) == int(vow[v])) || 
                        (int(str[i]) == int(vow[v] + 32))) vowel++;
                }
                letter++;                                           // увеличиваем переменную для счета букв
            }
            
            if (int(str[i]) >= 48 && int(str[i]) <= 57) digit++;    // если элемент массива входит в диапазон - это цифра

            cons = letter - vowel;                                  // находим кол-во согласных (общее кол-во букв отнимаем от гласных)
        }
        string++;                                                   // увеличиваем переменную для счета строк

        fgets(str, size, f1);                                       // проверяем есть ли след строка, чтоб нормально сработал цикл while (!feof(f1))   
    } 
 
    fputs("\t\tFile Statistics \"fole.txt\"\n", f2);                // запись строки в файл
    fprintf(f2, "Characters = %d\n", symbol);                       // форматированный вывод в файл
    fprintf(f2, "Strings = %d\n",    string);
    fprintf(f2, "Vowels = %d\n",     vowel);
    fprintf(f2, "Consonants = %d\n", cons);
    fprintf(f2, "Digits = %d\n",     digit);

    
    fclose(f1);                                                     // закрываем файлы - освобождаем системный ресурс
    fflush(f2);                                                     // когда все на запись отправлено, то сбрасываем буфер (на диск)
    fclose(f2);

    return 0;
}

/*
    Дан текстовый файл.Необходимо зашифровать его
    с помощью шифрования Цезаря. Результат записать
    в новый файл. Шифрование с использованием 
    ключа: 3.
*/
int main1()
{
    std::cout << " You can see the encrypted text in the file!\n\n";

    FILE* f1;
    FILE* f2;

    f1 = fopen("Text to encrypt.txt", "rt");                         // открываем файл для чтения
    f2 = fopen("Ciphertext.txt", "wt");                             // открываем файл для записи

    if (!f1)                                                        // если f1 невозможно открыть
    {
        std::cout <<
            "File \"Text to encrypt.txt\" open error!\n";           // сообщаем об ошибке
        return -1;
    }
    if (!f2)                                                        // если f1 невозможно открыть
    {
        std::cout <<
            "File \"Ciphertext.txt\" open error!\n";                // сообщаем об ошибке
        return -1;
    }
    const size_t size = 50;                                         // макс длина строки
    char str [size];                                                // буфер для строки из 1 файла
    int k = 3;                                                      // ключ шифрования

    fputs("\t\tCaesar encryption\n", f2);                           // запись строки в файл

    while (!feof(f1))                                               // пока не конец файла
    {
        fgets(str, size, f1);                                       // считываем символы в строку из файла "Text to encrypt.txt"
        //std::cout << str << "\n";                                   // выводим файл в консоль
        size_t len = strlen(str);                                   // определение размера массива символов
        for (size_t i = 0; i < len; i++)                            // перебираем элементы массива символов str
        {
            if (str[i] >= 'a' && str[i] <= 'z')                     // если это буква нижнего регистра
                str[i] = ((str[i] - 'a' + k) % 26) + 'a';           // смещаем букву на 3 вперед
            else if (str[i] >= 'A' && str[i] <= 'Z')                // если это буква верхнего регистра
                str[i] = ((str[i] - 'A' + k) % 26) + 'A';           // смещаем букву на 3 вперед
        }
        //std::cout << str;                                         // для проверки на консоли
        fputs(str, f2);                                             // запись зашифрованной строки в файл
    }   
    
    fclose(f1);                                                     // закрываем файлы - освобождаем системный ресурс
    fflush(f2);                                                     // когда все на запись отправлено, то сбрасываем буфер (на диск)
    fclose(f2);

    return 0;
}