//Ex.2
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Дан двумерный массив размерностью M х N, заполненный случайными числами.\n";
	cout << " Определить сумму элементов, расположенных на главной диагонали,\n";
	cout << " а также сумму элементов, расположенных на побочной диагонали.\n\n";

	const int rows = 4;
	const int cols = 3;
	int arr[rows][cols] = {};
	int sum1 = 0;
	int sum2 = 0;

	cout << " Двумерный массив: \n";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 20 + 1;
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "\n Сумма элементов, расположенных на главной диагонали: ";
	for (int y = 0; y < rows; y++)
		for (int x = 0; x < cols; x++)
			if (y == x) sum1 += arr[y][x];
	cout << sum1;
	cout << "\n Сумма элементов, расположенных на побочной диагонали: ";

	for (int y = 0; y < rows; y++)
		for (int x = 0; x < cols; x++)
			if (y + x == cols - 1) sum2 += arr[y][x];
	cout << sum2 << "\n";
}
