//Ex.9
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив на 100 вещественных чисел.\n";
	cout << " Определить, сколько элементов массива не имеют вещественной части.\n\n";
	const int size = 100;
	double numb[size];
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		numb[i] = (1 + rand() % 100) * 0.1;  //numb[i] = (rand()) * 0.1; для больших чисел
		cout << numb[i] << "  ";
		if (numb[i] - floor(numb[i]) == 0)
			count++;
	}
	cout << "\n Ответ: " << count << "\n";
}
