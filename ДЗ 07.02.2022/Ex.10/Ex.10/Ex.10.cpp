//Ex.10
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 200 случайных чисел в диапазоне от 0 до 200.\n";
	cout << " Определить количество одноразрядных, двухразрядных и трёхразрядных\n";
	cout << " чисел в процентном отношении.\n\n";
	const int size = 200;
	int value[size];
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		value[i] = 1 + rand() % 200;
		//cout << value[i] << "  ";

		if (value[i] >= 0 && value[i] <= 9)
			count1++;
		else if(value[i] >= 10 && value[i] <= 99)
			count2++;
		else
			count3++;
		/*while (value[i] != 0) {
			n++;
			value[i] /= 10;
		}
		if (n == 1) count1++;
		if (n == 2) count2++;
		if (n == 3) count3++;*/
	}
	cout << "\n";
	cout << " Одноразрядных: " << count1 << " - " << (double)count1 * 100 / size << "%\n";
	cout << " Двухразрядных: " << count2 << " - " << (double)count2 * 100 / size << "%\n";
	cout << " Трёхразрядных: " << count3 << " - " << (double)count3 * 100 / size << "%\n";
}
