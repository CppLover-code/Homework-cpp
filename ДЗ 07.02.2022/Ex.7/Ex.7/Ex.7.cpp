//Ex.7
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 20 случайных чисел в диапазоне от -30 до 10.\n";
	cout << " Определить сумму элементов массива, находящихся в массиве до первого положительного элемента.\n\n";

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
		if (numbers[i] > 0) break;
		sum += numbers[i];	
	}
	cout << "\n\n" << " Сумма элементов массива = " << sum << "\n";
}
