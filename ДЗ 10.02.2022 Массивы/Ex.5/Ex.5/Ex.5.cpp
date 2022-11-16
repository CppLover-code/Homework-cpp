//Ex.5
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать массив из 20 случайных чисел в диапазоне от -10 до 20.\n";
	cout << " Определить максимальное количество подряд идущих положительных элементов,\n";
	cout << " не прерываемых ни нулями, ни отрицательными числами. Вывести найденный фрагмент.\n\n";

	const int k = 20;
	int A[k] = {};
	int B[k] = {};
	int max = 0, h = 0, ib = 0, last = 0;
	
	cout << " Массив случайных чисел: \n";
	for (int i = 0; i < k; i++)
	{
		A[i] = rand() % 31 - 10;
		cout << A[i] << " ";
	}
	
	for (int i = 0; i < k; i++)
	{
		if (A[i] > 0) h++;
		else h = 0;

		if (h > max) max = h;
		if (h == max) last = i;	
	}
	int first = last - max; // определяем индекс начала наибольшего фрагмента
	for (int i = first + 1; i <= last; i++)
	{	
		B[ib] = A[i];
		ib++;
	}
	cout << "\n\n" << " Наибольший фрагмент искомых элементов массива: ";
	for (int i = 0; i < ib; i++)
	{
		cout << B[i] << " ";
	}
	cout << "\n\n" << " Количество: " << max << "\n";	
}
