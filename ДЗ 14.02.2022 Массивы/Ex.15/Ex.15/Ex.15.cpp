//Ex.15
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив размерностью M x N, заполненный случайными числами. Вывести на\n";
	cout << " экран  строку, для которой среднее арифметическое элементов максимально\n";
	cout << " отличается от среднего арифметического значения для всех элементов массива.\n\n";

	const int rows = 3;
	const int cols = 4;
	int arr[rows][cols] = {};
	int counter = 0;
	int sum = 0;
	int average = 0;
	
	cout << " Двумерный массив: \n";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 200 + 1;
			cout << arr[y][x] << " ";
			counter++;
			sum += arr[y][x];
		}
		cout << "\n";
	}
	cout << "\n Сумма элементов массива: ";
	cout << sum << " ";
	average = sum / counter;
	cout << "\n Среднее арифметическое элементов массива: " << average << "\n";

	int counter1 = 0;
	int sum1 = 0;
	int average1 = 0;
	int y, x, n;
	int max = 0;
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < cols; x++)
		{
			sum1 += arr[y][x];
			counter1++;
		}
		average1 = sum1 / counter1;	
		//cout << average1 << " ";
		
		if (abs(average - average1) >= max)
		{
			max = abs(average - average1);
			n = y;
		}
		counter1 = 0;
		sum1 = 0;
	}
	cout << " Искомая строка массива y - [" << n << "] - ";
	for (int y = n; y <= n; y++)
	{
		for (x = 0; x < cols; x++)
		{
			cout << arr[y][x] << " ";
		}
	}
	cout << "\n";
}