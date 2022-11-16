//Ex.7
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Дан двумерный массив размерностью M x N, заполненный случайными числами.\n";
	cout << " Определить сумму элементов массива, расположенных между мин. и макс. элементами.\n\n";

	const int rows = 4;
	const int cols = 4;
	int arr[rows][cols] = {};
	int count = 0;
	int arr1[rows * cols] = {};
	int sum = 0;

	cout << " Двумерный массив: ";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = arr1[count] = rand() % 201 - 100;
			cout << arr[y][x] << " ";
			count++;
		}
	}	
	/*for (int y = 0; y < count; y++)
	{
		cout << arr1[y] << " ";
	}*/

	int min = arr1[0];
	int i_min = 0;
	int max = arr1[0];
	int i_max = 0;

	for (int i = 1; i < count; i++)
	{
		if (min > arr1[i])
		{
			min = arr1[i];
			i_min = i;
		}
		if (max < arr1[i])
		{
			max = arr1[i];
			i_max = i;
		}
	}
	cout << "\n\n" << " Минимальный элемент массива: "  << min << "\n";
	cout << "\n" << " Максимальный элемент массива: " << max << "\n";

	if (i_min > i_max) swap(i_min, i_max);	
	for (int i = i_min + 1; i < i_max; i++)
	{
		sum += arr1[i];
	}
	cout << "\n Сумма: " << sum << "\n";
}