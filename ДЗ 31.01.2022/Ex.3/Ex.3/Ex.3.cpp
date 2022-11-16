// Ex.3
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "RUS");
	cout << " Вывести лестницу из отрезков определённой длины.\n" << "\n";
	cout << " Введите ширину ступеньки:\n" << "\n";
	int width;
	cin >> width;
	cout << " Введите  длину лестницы:\n" << "\n";
	int length;
	cin >> length;
	cout << "\n";

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == y || y < x)
			{
				cout << "*";
			}
			else cout << " ";
		}
		width += 1;
		cout << "\n";
	}
}