//Ex.10
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Заполнить массив M x N, как в текстовом файле ДЗ.\n\n";

    const int n = 6;
    const int m = n - 1;
    int arr[m][n] = {};
    int input = 1;
    cout << " Двумерный массив: \n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = input;
            input++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 || (i == 1 && arr[i][j] < 10)) cout << arr[i][j] << "  "; // подровняла для максимум n = 10;
            else cout << arr[i][j] << " ";          
        }
        cout << "\n";
    }
}