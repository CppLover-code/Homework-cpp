// Ex.2
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "RUS");
	cout << " Вывести на экран каркас параллелепипеда размерностью AxBxC.\n" << "\n";
	cout << " Введите размеры:\n";
	int a, b, c;
	cin >> a >> b >> c;

	int height = a + c;
	int width = b + c;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			if ((x + y == c - 1 && y < c) || (x + y == width - 2 && y < c) ||      // побочные верх
				(y == 0 && x > c - 1) || (y == c - 1 && x + 1 < b))					// горизонтальные верх
			{
				cout << "*";
			}
			else if ((x + y == height - 2 && y >= a - 1) || (x + y == width + 2 + c && y >= a - 1) ||		// побочные низ
				(y == a - 1 && x >= c && x < width) || (y == height - 2 && x < width - 1 - c))				// горизонтальные низ
				cout << "*";

			else if ((x == 0 && y >= c) || (x == width - 1 - c && y >= c) ||       // вертикальные
				(x == c - 1 && y < a - 1) || (x == width - 2 && y < a - 1))
				cout << "*";

			else
				cout << " ";
		}
		cout << "\n";
	}
}