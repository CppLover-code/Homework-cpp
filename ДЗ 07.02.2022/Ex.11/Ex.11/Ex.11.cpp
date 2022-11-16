//Ex.11
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 10 целых случайных чисел.\n";
	cout << " Изменить порядок следования элементов массива на противоположный\n\n";
	const int size = 10;
	int number[size];

	for (int i = 0; i < size; i++)
	{
		number[i] = 1 + rand() % 10;
		cout << number[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < size / 2; i++)
	{
		number[i] += number[size - i - 1]; // сумма двух элементов, которые будем менять местами
		number[size - i - 1] = number[i] - number[size - i - 1]; // больший меняем на меньший (индекс с элементом)
		number[i] = number[i] - number[size - i - 1]; // меньший меняем на больший (индекс с элементом)
	}
	for (int i = 0; i < size; i++)
	{
		cout << number[i] << " ";
	}
	cout << "\n";
}
