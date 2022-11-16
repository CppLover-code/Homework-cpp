//Ex.1
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "RUS");
	cout << " Ввести массив из 5 чисел, а затем вывести его в обратном порядке.\n" << "\n";

	const int size = 5;
	int numbers[size] = {5,6,7,8,9};

	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n\n" << " Числа в обратном порядке:\n" << "\n";

	for (int i = size - 1; i >= 0; i--)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";
}