//Ex.4
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Дан двумерный массив размерностью M х N, заполненный случайными числами.\n";
	cout << " Определить сумму по каждой строке и по каждому столбцу массива.\n\n";

	const int rows = 2;
	const int cols = 3;
	int arr[rows][cols] = {};
	int sum;

	cout << " Двумерный массив: ";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 20 + 1;
			cout << arr[y][x] << " ";
		}
	}
	cout << "\n Сумма элементов строки:\n";
	for (int y = 0; y < rows; y++)
	{
		sum = 0;
		cout << "[" << y << "] - ";
		for (int x = 0; x < cols; x++)
		{
			sum += arr[y][x];
		}
		cout << sum << "\n";
	}
	cout << "\n Сумма элементов столбца:\n";
	for (int x = 0; x < cols; x++)
	{
		sum = 0;
		cout << "[" << x << "] - ";
		for (int y = 0; y < rows; y++)
		{
			sum += arr[y][x];
		}
		cout << sum << "\n";
	}
}