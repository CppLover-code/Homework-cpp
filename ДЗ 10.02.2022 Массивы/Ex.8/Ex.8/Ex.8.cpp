//Ex.8
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(0, "rus");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор окна консоли
    cout << " Осуществить циклический сдвиг массива.\n\n";
    const int k = 10;
    int ar[k] = { 0,1,2,3,4,5,6,7,8,9 };
    cout << " Массив из 10 чисел: ";
    for (int i = 0; i < k; i++)
    {
        cout << ar[i] << " ";
    }

    cout << "\n Какое количество чисел необходимо сдвинуть?\n";
    int count;
    cin >> count;

    cout << " В какую сторону необходимо сдвинуть?\n" << " Вправо - 1\n" << " Влево - 0\n\n";
    int side;
    cin >> side;

    if (count == 10)
    {
        SetConsoleTextAttribute(h, 4);
        cout << " Вы ввели количество чисел равное размеру массива, поэтому изменений вы не увидите!\n\n";
        SetConsoleTextAttribute(h, 15);
    }

    int r = 0, l = 0;
    int newar[k] = {};

    switch (side)
    {
    case 1:
        for (int i = k - count; i < k; i++)
        {
            newar[r] = ar[i];
            r++;
        }
        for (int i = 0; i < k - count; i++)
        {
            newar[r] = ar[i];
            r++;
        }
        cout << " Массив со сдвигом вправо: ";
        for (int i = 0; i < k; i++)
        {
            cout << newar[i] << " ";
        }
        cout << "\n";
        break;

    case 0:
        int i = 0;
        for (i += count; i < k; i++)
        {
            newar[r] = ar[i];
            r++;
        }
        for (int i = 0; i < count; i++)
        {
            newar[r] = ar[i];
            r++;
        }
        cout << " Массив со сдвигом влево: ";
        for (int i = 0; i < k; i++)
        {
            cout << newar[i] << " ";
        }
        cout << "\n";
        break;
    }
}