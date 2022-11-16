//Ex.14
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Реализовать преобразование двумерного массива в одномерный, и наоборот.\n\n";

	const int a = 4;
	const int b = 5;
	int arr2[a][b] = {};
	int arr1[a * b] = {};
	int ind = 0;

	cout << " Двумерный массив: \n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr2[i][j] = rand() % 50 + 1;
			cout << arr2[i][j] << " ";
			arr1[i * b + j] = arr2[i][j];
		}
		cout << "\n";
	}

	cout << " Одномерный массив: \n";
	for (int i = 0; i < a * b; i++)
	{
		cout << arr1[i] << " ";
	}
	
	cout << "\n Двумерный массив: \n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr2[i][j] = arr1[ind++];
			cout << arr2[i][j] << " ";
		}
		cout << "\n";
	}
}
