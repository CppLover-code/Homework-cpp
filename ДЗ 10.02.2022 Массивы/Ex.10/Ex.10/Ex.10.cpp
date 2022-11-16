//Ex.10
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Ввести число в диапазоне от 0 до 1000000. Озвучить его словами.\n\n";
    int n;
    cout << " Введите число: ";
    cin >> n;

    int first = n / 100000;
    int second = n / 10000 % 10;
    int third = n / 1000 % 10;
    int fourth = n / 100 % 10;
    int fifth = n / 10 % 10;
    int sixth = n % 10;

    const int k = 6;
    int ar[k] = {};
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        switch (i) 
        {
            case 0:                
                ar[i] = first;
                break;
            case 1:               
                ar[i] = second;
                break;
            case 2:               
                ar[i] = third;
                break;
            case 3:               
                ar[i] = fourth;
                break;
            case 4:               
                ar[i] = fifth;
                break;
            case 5:   
                ar[i] = sixth;
                break;
        }
        sum += ar[i];
    }
    /*for (int i = 0; i < k; i++)
    {
        cout << ar[i] << " ";
    }*/
    for (int i = 0; i < k; i++)
    {
        if (sum == 0)
        {
            cout << " ноль ";
            break;
        }
        if (i == 0 || i == 3)
        {
            switch (ar[i])
            {
                case 1:
                    cout << " сто "; break;
                case 2:
                    cout << " двести "; break;
                case 3:
                    cout << " триста "; break;
                case 4:
                    cout << " четыреста "; break;
                case 5:
                    cout << " пятьсот "; break;
                case 6:
                    cout << " шестьсот "; break;
                case 7:
                    cout << " семьсот "; break;
                case 8:
                    cout << " восемьсот "; break;
                case 9:
                    cout << " девятьсот "; break;
                case 0:
                    cout << ""; break;
            }
            if (i == 0 && ar[i] > 0 && i == 0 && ar[i + 1] == 0 && i == 0 && ar[i + 2] == 0) cout << " тысяч ";
        }
        if (i == 1 || i == 4)
        {
            switch (ar[i])
            {
                case 1:
                    switch(ar[i + 1])
                    {
                        case 1:
                            cout << " одиннадцать "; break;
                        case 2:
                            cout << " двенадцать "; break;
                        case 3:
                            cout << " тринадцать "; break;
                        case 4:
                            cout << " четырнадцать "; break;
                        case 5:
                            cout << " пятнадцать "; break;
                        case 6:
                            cout << " шестнадцать "; break;
                        case 7:
                            cout << " семнадцать "; break;
                        case 8:
                            cout << " восемнадцать "; break;
                        case 9:
                            cout << " девятнадцать "; break;
                        case 0:
                            cout << " десять "; break;
                            
                    }
                    if (i == 1 && ar[i] != 0) cout << " тысяч ";
                    else cout << "";
                    break;
                case 2:
                    cout << " двадцать "; break;
                case 3:
                    cout << " тридцать "; break;
                case 4:
                    cout << " сорок "; break;
                case 5:
                    cout << " пятьдесят "; break;
                case 6:
                    cout << " шестьдесят "; break;
                case 7:
                    cout << " семьдесят "; break;
                case 8:
                    cout << " восемьдесят "; break;
                case 9:
                    cout << " девяносто "; break;
                case 0:
                    cout << ""; break;     
                    
            }
            if (i == 1 && ar[i + 1] == 0 && ar[1] > 0) cout << " тысяч ";
            else cout << "";
        }
        if ((i == 2 && ar[i - 1] == 0 && (i == 2 && ar[i - 2] == 0)) ||
            (i == 2 && ar[i - 1] > 1) || ((i == 2 && ar[i - 2] > 0) && (i == 2 && ar[i - 1] == 0))
            || ((i == 2 && ar[i - 2] > 0) && (i == 2 && ar[i - 1] > 1)))
        {
            switch (ar[i])
            {
                case 1:
                    cout << " однa тысяча "; break;
                case 2:
                    cout << " две тысячи "; break;
                case 3:
                    cout << " три тысячи"; break;
                case 4:
                    cout << " четыре тысячи"; break;
                case 5:
                    cout << " пять "; break;
                case 6:
                    cout << " шесть "; break;
                case 7:
                    cout << " семь "; break;
                case 8:
                    cout << " восемь "; break;
                case 9:
                    cout << " девять "; break;
                case 0:
                    cout << ""; break;
            }
            if (ar[i] > 4) cout << " тысяч ";
        }
        if (((i == 5 && ar[i - 1] == 0) && (i == 5 && ar[i - 2] == 0)) || i == 5 && ar[i - 1] > 1 ||
            ((i == 5 && ar[i - 1] == 0) && (i == 5 && ar[i - 2] >= 1)))
        {
            switch (ar[i])
            {
                case 1:
                    cout << " один "; break;
                case 2:
                    cout << " два "; break;
                case 3:
                    cout << " три "; break;
                case 4:
                    cout << " четыре"; break;
                case 5:
                    cout << " пять "; break;
                case 6:
                    cout << " шесть "; break;
                case 7:
                    cout << " семь "; break;
                case 8:
                    cout << " восемь "; break;
                case 9:
                    cout << " девять "; break;
                case 0:
                    cout << ""; break;
            }
        }

    }
    cout << "\n";
}