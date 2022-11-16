//Ex.3
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Дан двумерный массив размерностью M х N, заполненный случайными числами.\n";
	cout << " Определить количество положительных, отрицательных и нулевых элементов.\n\n";

	const int rows = 5;
	const int cols = 3;
	int arr[rows][cols] = {};
	int plus = 0;
	int minus = 0;
	int null = 0;

	cout << " Двумерный массив: ";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 21 - 10;
			cout << arr[y][x] << " ";
		}
	}
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (arr[y][x] > 0) plus++;
			if (arr[y][x] < 0) minus++;
			if (arr[y][x] == 0) null++;
		}
	}
	cout << "\n Количество:\n" << " положительных: " << plus << "\n";
	cout << " отрицательных: " << minus << "\n" << " нулевых: " << null << "\n";
}