//Ex.9
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Создать массив строк на 4000 элементов. Заполнить его римскими числами от 1 до\n";
    cout << " 3999, показать на экране все элементы.\n\n";
    const int k = 4000;
    int ar[k] = {};
    int thousand = 0;
    int hundred = 0;
    int ten = 0;
    int unit = 0;
   
    for (int i = 0; i < k; i++)
    {
        if (i + 1 == k) break;
        ar[i] = i + 1;  
    }
   
    for (int i = 0; i < k - 1; i++)
    {
        thousand = ar[i] / 1000;
        hundred = ar[i] / 100 % 10;
        ten = ar[i] / 10 % 10;
        unit = ar[i] % 10;

         switch (thousand)
         {
             case 1:cout << "M";
                 break;
             case 2:cout << "MM";
                 break;
             case 3:cout << "MMM";
                 break;
             case 0:cout << "";
                 break;
         }
         switch (hundred)
         {
             case 1:cout << "C";
                  break;
             case 2:cout << "CC";
                  break;
             case 3:cout << "CCC";
                  break;
             case 4:cout << "CD";
                  break;
             case 5:cout << "D";
                  break;
             case 6:cout << "DC";
                  break;
             case 7:cout << "DCC";
                  break;
             case 8:cout << "DCCC";
                  break;
             case 9:cout << "CM";
                  break;
             case 0:cout << "";
                  break;
         }
         switch (ten)                
         {
             case 1:cout << "X";
                  break;
             case 2:cout << "XX";
                  break;
             case 3:cout << "XXX";
                  break;
             case 4:cout << "XL";
                  break;
             case 5:cout << "L";
                  break;
             case 6:cout << "LX";
                  break;
             case 7:cout << "LXX";
                  break;
             case 8:cout << "LXXX";
                  break;
             case 9:cout << "XC";
                  break;
             case 0:cout << "";
                  break;
         }
         switch (unit)
         {
             case 1:cout << "I";
                  break;
             case 2:cout << "II";
                  break;
             case 3:cout << "III";
                  break;
             case 4:cout << "IV";
                  break;
             case 5:cout << "V";
                  break;
             case 6:cout << "VI";
                  break;
             case 7:cout << "VII";
                  break;
             case 8:cout << "VIII";
                  break;
             case 9:cout << "IX";
                  break;
             case 0:cout << "";
                  break;
         }
         cout << "  ";
    }
}