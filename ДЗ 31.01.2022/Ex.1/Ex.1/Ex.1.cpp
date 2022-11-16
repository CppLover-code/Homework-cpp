// Ex.1
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "RUS");
	cout << " Вывести на экран ромб\n" << "\n";
	cout << " Введите длину диагоналей ромба:\n" << "\n";
	int l;
	cin >> l;

	char symb = '*';

	int spaces = l - 1; // пропуски
	int stars = 1; // символы 

	for (int y = 0; y < l; y++) // линии
	{
		for (int s = 0; s < spaces; s++)
		{
			cout << " ";
		}
		for (int x = 0; x < stars; x++)
		{
			cout << symb;
		}
		spaces--;
		stars += 2;
		cout << "\n";
	}
	stars -= 4;

	for (int y = 1; y < l; y++) // линии
	{
		for (int s = 0; s < spaces + 2; s++)
		{
			cout << " ";
		}
		for (int x = 0; x < stars; x++)
		{
			cout << symb;
		}
		spaces++;
		stars -= 2;
		cout << "\n";
	}
	cout << "\n";
	for (int y = 0; y < l; y++)
	{
		for (int x = 0; x < l * 2 - 1; x++)
		{
			if (y == l * 2 - 2 || y == l || x + y == l - 1 || x - y == l - 1)
				cout << symb;
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int y = 1; y < l; y++)
	{
		for (int x = 0; x < l * 2 - 2; x++)
		{
			if (x == y || x + y == l * 2 - 2)
				cout << symb;
			else
				cout << " ";
		}

		cout << "\n";
	}
}