//Ex.6
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 10 вещественных чисел. Преобразовать массив так,\n";
	cout << " чтобы сначала шли все элементы с вещественной частью, а потом без нее.\n\n";
	const int l = 10;
	double numb[l] = {};
	double arr[l] = {};
	int n1 = 0;

	cout << " Массив: ";
	for (int i = 0; i < l; i++)
	{
		numb[i] = (1 + rand() % 100) * 0.1;
		cout << numb[i] << "   ";
	}
	for (int i = 0; i < l; i++)
	{
		if (numb[i] - floor(numb[i]) > 0)
		{
			arr[n1] = numb[i];
			n1++;
		}
	}
	for (int i = 0; i < l; i++)
	{
		if (numb[i] - floor(numb[i]) == 0)
		{
			arr[n1] = numb[i];
			n1++;
		}
	}
	cout << "\n\n" << " Изменённый массив: ";
	for (int i = 0; i < l; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << "\n";
}
