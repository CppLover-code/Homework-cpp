// Ex.4
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "RUS");
	cout << " Показать на экране лесенку.\n" << "\n";
	cout << " Введите количество ступенек:\n";
	int count;
	cin >> count;

	int height = (count * 2) + 1;
	int spaces = 0;

	for (int y = 0; y < height; y++)
	{
		int stars = 3;

		for (int s = 0; s < spaces; s++)
		{
			cout << " ";
		}
		
		for (int x = 0; x < stars; x++)
		{
			if (y % 2 == 0 && x < stars) // вывод 3 звёзд
			{
				cout << "*";
			}

			else if (y % 2 != 0 && x % 2 == 0) // вывод 1 звёзд
			{
				stars -= 2;
				spaces -= 2;
				cout << "*";
			}	
			else
				cout << " ";
		}
		cout << "\n";
		spaces += 2;
	}
}