//Ex.12
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(0, "rus");
    cout << " Заполнить массив M x N, как в текстовом файле ДЗ.\n\n";

        const int height = 6;
        const int width = 10;
        int ar[height][width] = {};
        int direction = 1; // 1 - right down, 2 - left down, 3 - left up, 4 - right up
        int x = 0;
        int y = 0;
        int current = 1;
        cout << " Двумерный массив: \n";
        for (int i = 0; i < height * width; i++)
        {
            ar[y][x] = current;
            if (direction == 1) // right down
            {
                x++;
                y++;
            }
            else if (direction == 2) // left down
            {
                x--;
                y++;
            }
            else if (direction == 3) // left up
            {
                x--;
                y--;
            }
            else if (direction == 4) // right up
            {
                x++;
                y--;
            }
            current++;

            if ((ar[y][x + 1] != 0 || y == height) && direction == 1) direction = 4;
            else if ((ar[y + 1][x] != 0 || y == height) && direction == 2) direction = 3;
            else if (x == 0 && direction == 3) direction = 1;
            else if (x == width && direction == 4) direction = 2;

            for (int a = 0; a < height; a++)
            {
                for (int b = 0; b < width; b++)
                {
                    cout << ar[a][b] << "\t";
                }
                cout << "\n\n";
            }

            Sleep(500);
            system("cls");
        }



    

}