//Ex.12
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "rus");
	cout << " Создать два массива A и B по 5 элементов. Создать третий массив C\n";
	cout << " на 10 элементов, в который копируются элементы из первого и второго массива поочередно.\n\n";

	const int size = 5;
	int A[size] = {6, 1, 14, 9, 4};
	int B[size] = {15, 7, 3, 10, 8};
	int C[size * 2];

	cout << " Массив А: ";
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}

	cout << "\n" << " Массив B: ";
	for (int i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}

	cout << "\n" << " Массив C: ";
	int i_a = 0;
	int i_b = 0;
	for (int i = 0; i < size * 2;)
	{
		if (i_a < size)
		{
			C[i] = A[i_a];
			i_a++;
			i++;
		}
		if (i_b < size)
		{
			C[i] = B[i_b];
			i_b++;
			i++;
		}
	}
	for (int i = 0; i < size * 2; i++)
	{
		cout << C[i] << " ";
	}
	cout << "\n";
}
