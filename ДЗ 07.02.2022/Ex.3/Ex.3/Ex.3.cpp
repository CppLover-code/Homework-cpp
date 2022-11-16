//Ex.3
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "RUS");
	cout << " Создать массив из 10 случайных чисел в диапазоне от -20 до 20.\n";
	cout << " Определить количество, сумму  и среднее арифметическое положительных элементов массива.\n\n";

	const int size = 10;
	int numbers[size];
	int counter = 0;
	int sum = 0;
	cout << " Массив из 20 случайных чисел:\n\n";
	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand() % 41 - 20;
		cout << numbers[i] << " ";
		if (numbers[i] > 0)
		{
			counter++;
			sum += numbers[i];
		}
	}
	cout << "\n\n";
	cout << "\t\t\tПоложительные элементы массива\n\n";
	cout << "\t Количество - " << counter << "\t\t Сумма - " << sum << "\t\t Среднее арифметическое - " << sum / counter << "\n";
}  