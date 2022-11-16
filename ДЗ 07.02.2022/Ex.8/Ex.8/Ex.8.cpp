//Ex.8
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 20 случайных чисел. Определить минимальный и\n";
	cout << " максимальный элемент массива.\n\n";
	// Пузырьковая сортировка???? Линейная ????
	const int size = 20;
	int numbers[size];

	for (int i = 0; i < size; i++)
	{
		numbers[i] = 1 + rand() % 20;
		cout << numbers[i] << " ";
	}
	int min = numbers[0];
	int i_min=0;
	int max = numbers[0];
	int i_max=0;

	for (int i = 1; i < size; i++)
	{
		if (min > numbers[i])
		{
			min = numbers[i];
			i_min = i;
		}
		if (max < numbers[i])
		{
			max = numbers[i];
			i_max = i;
		}
	}
	
	cout << "\n\n" << " Минимальный элемент массива - [" << i_min << "] - " << min << "\n";
	cout << "\n" << " Максимальный элемент массива - [" << i_max << "] - " << max << "\n";
}
