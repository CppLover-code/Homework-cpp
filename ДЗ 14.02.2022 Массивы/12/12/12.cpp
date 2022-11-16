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
           /* if (ar[y + 1][x + 1] != 0)
            {
                x += 2;
                y += 2;
            }
            else
            {*/
                x++;
                y++;
            //}       
        }
        else if (direction == 2) // left down
        {
            if (ar[y + 1][x - 1] != 0)
            {
                x -= 2;
                y += 2;
            }
            else
            {
                x--;
                y++;
            }
           
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

        if (y == height && direction == 1)
        {
            direction = 4;
            y = height - 2;
        }

        else if (x == width && direction == 4)
        {
            direction = 3;
            x = width - 2;
        }
        else if (direction == 3)
        {
             direction = 2;
             y += 2;
            
        }
        else if (y == height && direction == 2)  
        {
            direction = 3;
            y -= 2;
        }
        else if (x == 0 && direction == 3)
        {
            x += 1;
            direction = 4;
        }
        else if (y == 0 && direction == 4)
        {
            y += 1;
            direction == 1;
        }

       

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