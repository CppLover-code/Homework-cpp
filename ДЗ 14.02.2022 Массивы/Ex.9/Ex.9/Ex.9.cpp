//Ex.9
#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Заполнить квадратную матрицу размером M x N по спирали. Число 1 ставится в угловой\n";
    cout << " (например, верхний левый) элемент, и спираль закручивается к центру матрицы.\n\n";

    const int n = 5;
    int arr[n][n] = {};
    int m = 1;
    cout << " Двумерный массив: \n";

    int row = n / 2;
    int col = n / 2;
    arr[row][col] = n * n; // середина матрицы

    for (int i = 0; i < (n / 2); i++)
    {
        for (int j = i; j < (n - i); j++) // верх y уменьшается за счёт i
        {
            arr[i][j] = m;
            m++;
        }
        for (int j = 1; j < (n - i - i); j++) // правая сторона x уменьшается за счёт i
        {
            arr[(j + i)][(n - i) - 1] = m;
            m++;
        }
        for (int j = (n - 2) - i; j >= i; j--) // низ y уменьшается за счёт i
        {
            arr[(n - i) - 1][(j)] = m;
            m++;
        }
        for (int j = ((n - i) - 2); j > i; j--) // правая сторона x уменьшается за счёт i
        {
            arr[j][i] = m;
            m++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << arr[i][n - 1] << "\n";
    }
}