//Ex.4
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Создать символьный массив из 100 случайных элементов.\n";
	cout << " Определить сколько в нём цифр, букв и знаков пунктуации.\n\n";
	const int size = 100;
	char symbols[size];

	int number = 0;
	int letter = 0;
	int punct = 0;

	for (int i = 0; i < size; i++)
	{
		symbols[i] = 32 + rand() % 96;
		//cout << i << " - " << (int)symbols[i] << " - " << symbols[i] << "\n";
		cout << symbols[i] << " ";

		if (symbols[i] >= 48 && symbols[i] <= 57) number++;
		else if ((symbols[i] >= 65 && symbols[i] <= 90) || (symbols[i] >= 97 && symbols[i] <= 122)) letter++;
		else punct++;
	}
	cout << "\n\n Всего цифр - " << number << "\n Всего букв - " << letter << "\n Всего знаков пунктуации - " << punct << "\n";
}
/*if (isdigit(symbols[i])) number++;
if (isalpha(symbols[i])) letter++;
if (ispunct(symbols[i])) punct++;*/

// формула min + rand()% (max - min + 1)