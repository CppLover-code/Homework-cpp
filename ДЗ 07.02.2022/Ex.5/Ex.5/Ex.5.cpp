//Ex.5
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Подсчитать, сколько раз введённое пользователем число\n";
	cout << " встречается в массиве на 100 случайных элементов.\n\n";
	cout << " Введите число от 1 до 100:\n";
	int n;
	cin >> n;

	const int size = 100;
	int numbers[size];

	int count = 0;
	
	for (int i = 0; i < size; i++)
	{
		numbers[i] = 1 + rand() % 100;
		cout << numbers[i] << " ";

		if (numbers[i] == n) count++;
	}
	cout << "\n\n" << " Число встречается " << count << " раз\n";
}
