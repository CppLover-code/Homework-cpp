//Ex.11
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Заполнить массив M x N, как в текстовом файле ДЗ.\n\n";

    const int n = 6;
    const int m = n - 1;
    int arr[m][n] = {};
    int c = 1;
    cout << " Двумерный массив: \n";
    
    for (int i = 0; i < m; i++)
    {     
        if (i % 2 == 0)
        {
            if (i % 2 == 0 && i > 0) c += n + 1;
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = c;
                c++;
            }
        } 
        if (i % 2 != 0)
        {
            c += n - 1;
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = c;
                c--;
            }
        }   
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  "; 
        }
        cout << "\n";
    }
}