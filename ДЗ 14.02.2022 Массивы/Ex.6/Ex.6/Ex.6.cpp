//Ex.6
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " В двумерном массиве размерности M x N поменять местами\n";
	cout << " чётные строки с нечётными.\n\n";

	const int rows = 4;
	const int cols = 4;
	int arr[rows][cols] = {};

	cout << " Двумерный массив:\n";
	for (int y = 0; y < rows; y++)
	{
		cout << "[" << y << "] - ";
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 20 + 1;
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "\n Изменённый массив:\n";
	int j = 0;
	for (int y = 0; y < rows; y++)
	{
		cout << "[" << y << "] - ";
		if (y % 2 == 0)
		{
			j = y;
			j += 1;
		}
		else j = y - 1;
		for (int x = 0; x < cols; x++)
		{
			cout << arr[j][x] << " ";
		}
		cout << "\n";
	}
}