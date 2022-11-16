//Ex.5
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "rus");
	cout << " Заполнить массив M x N двузначными числами так, чтобы первая цифра указывала\n";
	cout << " номер строки, а вторая – номер столбца.\n\n";

	const int rows = 5;
	const int cols = 6;
	int arr[rows][cols] = {};
	string s;
	string s1;
	string s2;

	cout << " Двумерный массив: \n";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			s1 = to_string(y);
			s2 = to_string(x);
			s = s1 + s2;
			int a = stoi(s);
			arr[y][x] = a;
			printf("%02d  ", arr[y][x]);
			//cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
}