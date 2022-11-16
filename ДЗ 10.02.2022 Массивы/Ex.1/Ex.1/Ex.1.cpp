//Ex.1
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
    setlocale(0, "rus");
	cout << " Программа, копирующая один массив в другой: элементы больше нуля, равные нулю, меньше нуля.\n\n";
	// Как вариант, можно сделать сортировку по убыванию и просто скопировать один массив в другой.
	const int k = 20;
	int arr1[k] = {};
	int arr2[k] = {};

	cout << " Массив 1: ";
	for (int i = 0; i < k; i++)
	{
		arr1[i] = rand() % 61 - 30;
		cout << arr1[i] << " ";
	}
	cout << "\n\n";

	int i1 = 0;
	for (int i = 0; i < k; i++)
	{
		if (arr1[i] > 0)
		{
			arr2[i1] = arr1[i];
			i1++;
		}
	}

	int i2 = 0;
	i2 += i1;
	for (int i = 0; i < k; i++)
	{
		if (arr1[i] == 0)
		{
			arr2[i2] = arr1[i];
			i2++;
		}
	}

	int i3 = 0;
	i3 += i2;
	for (int i = 0; i < k; i++)
	{
		if (arr1[i] < 0)
		{
			arr2[i3] = arr1[i];
			i3++;
		}
	}
	cout << " Массив 2: ";
	for (int i = 0; i < k; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "\n";
}