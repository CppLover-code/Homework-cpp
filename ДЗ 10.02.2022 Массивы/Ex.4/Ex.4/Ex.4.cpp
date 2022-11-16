//Ex.4
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
	srand(time(0));
    setlocale(0, "rus");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор окна консоли
    cout << " Лотерея\n\n";

    const int k = 5;
    int wincomb[k] = {};

	int randomA;
	bool arrA;

	for (int i = 0; i < k;) { //цикл создания случайных чисел
		randomA = 1 + rand() % 20;
		arrA = true;
		for (int j = 0; j < k; j++) //цикл проверки массива на совпадение
		{
			if (randomA == wincomb[j]) //условие совпадения
			{
				arrA = false;//Найдено хотя бы одно совпадение
				break;
			}
			else continue; //если повтора нет, переходим к следующей итерации
		}
		if (arrA)
		{
			wincomb[i] = randomA;
			i++;
		}
	}
	cout << " Выигрышная комбинация ";
	for (int i = 0; i < k; i++)
	{
		cout << wincomb[i] << " ";
	}
	cout << "\n" << " Попытайте удачу в лотерее!";
	cout << " Вам необходимо угадать 5 чисел.\n" << " Награды за верные комбинации:\n\n";
	cout << " 5 чисел - 2500 грн.\n" << " 4 числа - 500 грн.\n" << " 3 числа - 100 грн.\n\n";
	cout << " Введите 5 цифр поочерёдно (1-42):\n";
	int n;
	int comb[k] = {};
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		comb[i] = n;
	}
	cout << " Комбинация пользователя ";
	for (int i = 0; i < k; i++)
	{
		cout << comb[i] << " ";
	}
	cout << "\n";

	int same = 0;
	for (int i = 0; i < k; i++) // wincomb
	{
		for (int y = 0; y < k; y++) // comb
		{
			if (comb[y] == wincomb[i]) same++; // проверка одинаковых элементов в массивах
		}
	}
	if (same < 3)
	{
		SetConsoleTextAttribute(h, 4);
		cout << " Увы! Попытайте удачу в следующее воскресенье!\n";
		SetConsoleTextAttribute(h, 15);
	}
	if (same == 3)
	{
		SetConsoleTextAttribute(h, 11);
		cout << " Поздравляем! Вы угадали 3 цифры выигрышной комбинации!\n";
		cout << " Ваш выигрышь - 100 грн.\n";
		SetConsoleTextAttribute(h, 15);
	}
	if (same == 4)
	{
		SetConsoleTextAttribute(h, 11);
		cout << " Поздравляем! Вы угадали 4 цифры выигрышной комбинации!\n";
		cout << " Ваш выигрышь - 500 грн.\n";
		SetConsoleTextAttribute(h, 15);
	}
	if (same == 5)
	{
		SetConsoleTextAttribute(h, 10);
		cout << " Поздравляем! Вы угадали 5 цифр выигрышной комбинации!\n";
		cout << " Ваш выигрышь - 2500 грн.\n";
		SetConsoleTextAttribute(h, 15);
	}
}