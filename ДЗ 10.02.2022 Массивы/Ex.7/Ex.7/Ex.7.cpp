//Ex.7
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "RUS");
	cout << " Создать массив из 10 целых случайных чисел в диапазоне от 0 до 100. Найти элемент,\n";
	cout << " максимально близкий к среднему арифметическому значений массива.\n\n";

	const int k = 10;
	int numbers[k] = {};
	int sum = 0, n = 0, min = 0, mid = 0;
	cout << " Массив из 20 случайных чисел:\n\n";
	for (int i = 0; i < k; i++)
	{
		numbers[i] = rand() % 101;
		cout << numbers[i] << " ";
		sum += numbers[i];
	}

	mid = sum / k;

	min = abs(numbers[0] - mid);
	for (int i = 0; i < k; i++)
	{
		if (abs(numbers[i] - mid) <= min) //сравниваем разницу между средним и числом массива
		{
			min = abs(numbers[i] - mid);
			n = numbers[i];
		}
	}
	cout << "\n\n" << " Среднее арифметическое: " << mid << "\n";
	cout << " Максимально близкий элемент: " << n << "\n";
}