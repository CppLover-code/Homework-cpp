#include <iostream>
#include <fstream>
#include <string>

/*
    Дан текстовый файл. Удалить из него последлюю
    строку. Результат записать в другой файл.
*/
int main()
{
    std::ifstream reader;                               // файловые переменные для чтения
    std::ofstream writer;                               // и записи результата
    const std::string fileres = "Res1.txt";             // имя результирующего файла
    const std::string file = "Text.txt";                // имя исходного файла

    const size_t MAX_STR = 100;                         // размер буфера - макс длина строки
    char str[MAX_STR];                                  // буфер 1 для строки из файла
    char str1[MAX_STR];                                 // буфер 1 для строки из файла

    int s = 0;                                          // для подсчёта строк

    writer.open(fileres);
    if (!writer)                                        // открылся ли файл
    {
        std::cout << "Writer open error" << std::endl;
        return -1;
    }
    reader.open(file);
    if (!reader)                                        // открылся ли файл
    {
        std::cout << "Reader open error" << std::endl;
        return -2;
    }

    while (!reader.eof())                               // пока не конец файла
    {
        reader.getline(str, MAX_STR);                   // считываем строку из файла в str      
        s++;                                            // увеличиваем кол-во строк
    }

    reader.close();                                     // закрываем файл
    reader.open(file);                                  // вновь открываем

    if (!reader)                                        // открылся ли файл
    {
        std::cout << "Reader open error" << std::endl;
        return -2;
    }
   
    std::cout << " Writing to a new file completed!\n";
    for (int i = 0; i < s - 1; i++)                      // запуск цикла до предпоследней строки
    {
        reader.getline(str1, MAX_STR);                   // считываем строку из файла в str1
        writer << str1 << "\n";                          // записываем в новый файл "Res1.txt"
    }      

    reader.close();
    writer.flush();
    writer.close();

    return 0;
}
/*
    Дан текстовsй файл. Найти длину 
    самой длинной строки.
*/
int main2()
{
    const size_t SIZE = 100;                    // размер буфера - макс длина строки
    char str[SIZE];                             // буфер 1 для строки из файла
    char max_str[SIZE];                         // буфер 2 для хранения макс длинной строки
    const char filename[] = "Text.txt";         // имя файла

    size_t max_l = 0;                           // переменная для макс длины
    std::ifstream reader(filename);             // сокращенная форма - сразу open(...)

    if (!reader)                                // проверка нужна и для сокр формы
    {
        std::cout << "Reader open error";
        return -1;
    }
    while (!reader.eof())                       // пока не конец файла
    {
        reader.getline(str, SIZE);              // считываем строку из файла в str
        size_t length = strnlen_s(str, SIZE);   // определяем ее длину
        if (length > max_l)                     // сравниваем длину с максимальной
        {
            max_l = length;                     // если нашли более длинную
            strcpy_s(max_str, str);             // то заменяем max_length и сохраняем самую длинную строку в отдельном буфере
        }
    }

    reader.close();

    std::cout << "Max length of file's line = " << max_l << std::endl;
    //std::cout << "It is: " << max_str << std::endl;

    return 0;
}
/*
    Дан текстовый файл. Посчитать, сколько раз
    в нём встречается заданое пользователем слово.
*/
int main3()
{
    puts(" How many times does the word appear in the text?\n"); 
    std::string str;                                              // для строки из исходного файла
    std::string str_f;                                            // для искомого слова (ввод пользователя)

    std::ifstream reader("Text.txt");                             // сокращенная форма - сразу open(...)

    if (!reader)                                                  // проверка для сокр формы
    {
        std::cout << "Reader open error";
        return -1;
    }

    puts("\nEnter the word to be found: \n");

    std::cin >> str_f;
    int c = 0;                                                     // счетчик

    while (reader>>str)                                            // пока не конец файла
    {
        const char* found = strstr(str_f.c_str(), str.c_str());    // поиск строки в подстроке
        if (found)                                                 // если совпадение найдено
        {
            c++;                                                   // увеличиваем счетчик
        }
    }

    reader.close();                                                // закрываем файл

    std::cout << "The search word occurs " << c 
        << " times in the text. " << std::endl;

    return 0;
}
/*
    Дан текстовый файл. Найти и заменить в нём заданое слово.
    Что искать и на что менять определяет пользователь.
*/
int main4()
{
    puts(" Find and replace a given word in a text file.\n");
    const size_t SIZE = 100;                            // размер буфера - макс длина строки
    char str[SIZE];                                     // для строки из исходного файла
    char str_repl[SIZE];                                // заменяемое слово (ввод пользователя)
    char str_ins[SIZE];                                 // слово для замены (ввод пользователя)

    std::ifstream reader("Text.txt");                   // файловые переменные для чтения
    std::ofstream writer("Replace.txt");                // и записи результата

    if (!reader)                                        // проверка открытия файла для чтения
    {
        std::cout << "Reader open error";
        return -1;
    }

    if (!writer)                                        // проверка открытия файла для записи
    {
        std::cout << "Writer open error";
        return -1;
    }

    puts("\nEnter the word to be replaced: \n");
    std::cin >> str_repl;
    puts("\nEnter the word to be inserted: \n");
    std::cin >> str_ins;

    char* pos;                                          // указатель на первое совпадение подстроки в строке
    
    size_t ind = 0;
    size_t len1 = strnlen(str_repl, SIZE);              // длина заменяемого слова
    size_t len2 = strnlen(str_ins, SIZE);               // длина слова для замены

    while (!reader.eof())                               // пока не конец файла "Text.txt"
    {
        reader.getline(str, SIZE);                      // считываем строку из файла в str
        size_t length = strnlen(str, SIZE);             // определяем ее длину
        
        pos = strstr(str, str_repl);                    // указатель на первое совпадение подстроки в строке

        if (pos != NULL)                                // если совпадение найдено
        {
            for (size_t i = 0; i < length; i++)         // исходный массив строки str
            {
                ind = pos - str;                        // индекс элемента, с которого начинаем замену (адрес подстроки минус нулевой индекс строки)

                if (i != ind)                           // если индекс исходного массива не совпал с индексом начала замены
                {
                    writer << str[i];                   // записываем символы исходного файла в новый
                }
                else                                    // иначе, если индексы совпали, 
                {
                    for (size_t x = 0; x < len2; x++)   // масссив с символами, которые необходимо вставить вместо введенного пользователем слова
                    {
                        writer << str_ins[x];           // записываем символы слова для замены в новый файл
                    }
                    i = i + len1 - 1;                   // возвращаемся в исходный массив строки str, перескочив индексы слова, которое нужно было заменить
                    pos = strstr(pos + 1, str_repl);    // продолжаем искать совпадения
                }  
            }
        }
        else                                            // иначе, если совпадение не найдено
        {
            for (size_t i = 0; i < length; i++)         // исходный массив строки str
            {
                writer << str[i];                       // записываем символы исходного файла в новый
            }
        }
        writer << "\n";                                 // записываем переход на новую строку в новый файл после окончания str
    }                           


    reader.close();                                     // закрываем файлы
    writer.flush();
    writer.close();

    return 0;
}