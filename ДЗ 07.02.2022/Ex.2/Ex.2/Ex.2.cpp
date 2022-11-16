//Ex.2
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "RUS");
	cout << " Создать массив из 20 случайных чисел.\n";
	cout << " Вывести все элементы массива с чётными индексами.\n\n";

	const int size = 20;
	int numbers[size];

	cout << " Массив из 20 случайных чисел.\n\n";
	for (int i = 0; i < size; i++)
	{
		numbers[i] = 1 + rand() % 20;
		cout << numbers[i] << " ";
	}
	cout << "\n\n" << " Элементы массива с чётными индексами:\n\n";

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			cout << " Индекс [" << i << "] - " << numbers[i] << "\n";
		}
	}
	cout << "\n";
}