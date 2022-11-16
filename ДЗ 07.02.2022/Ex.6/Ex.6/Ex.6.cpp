//Ex.6
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 20 случайных чисел в диапазоне от -10 до 30.\n";
	cout << " Определить сумму элементов массива, находящихся в массиве после первого отрицательного элемента.\n\n";
	
	const int size = 20;
	int numbers[size];

	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand() % 41 - 10;
		cout << numbers[i] << " ";	
	}
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] < 0)
		{
			for (int x = i + 1; x < size; x++)
				sum += numbers[x];
			break;
		}
	}
	cout << "\n\n" << " Сумма элементов массива = " << sum << "\n";
}
