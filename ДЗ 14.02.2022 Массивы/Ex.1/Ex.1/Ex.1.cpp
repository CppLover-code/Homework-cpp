//Ex.1
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Дан двумерный массив размерностью M х N, заполненный случайными числами.\n";
	cout << " Определить сумму элементов массива, среднее арифметическое, минимальный и максимальный элемент.\n\n";

	const int rows = 2;
	const int cols = 4;
	int arr[rows][cols] = {};
	int counter = 0;
	int sum = 0;
	int min = arr[0][0];
	int max = arr[0][0];

	cout << " Двумерный массив: ";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 20;
			cout << arr[y][x] << " ";
			counter++;
		}
	}
	cout << "\n Сумма элементов массива: ";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			sum += arr[y][x];
		}
	}
	cout << sum << " ";
	cout << "\n Среднее арифметическое элементов массива: " << sum / counter << "\n";

	for (int y = 0; y < rows; y++)
	{
		for (int x = 1; x < cols; x++)
		{
			if (min > arr[y][x])	min = arr[y][x];
			if (max < arr[y][x])	max = arr[y][x];
		}
	}
	
	cout << " Минимальный элемент массива - " << min << "\n";
	cout << " Максимальный элемент массива - " << max << "\n";
}
