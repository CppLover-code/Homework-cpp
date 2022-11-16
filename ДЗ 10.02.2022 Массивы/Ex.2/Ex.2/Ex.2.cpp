//Ex.2
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Даны 2 массива размерности M и N соответственно.\n";
	cout << " Необходимо переписать в третий массив общие элементы первых двух массивов, без повторений.\n\n";
	
	const int k = 10;
	int A[k] = {};
	int B[k] = {};
	int C[k] = {};

	int randomA;
	int randomB;
	bool arrA;
	bool arrB;

	for (int i = 0; i < k;) { //цикл создания случайных чисел
		randomA = 1 + rand() % 20;
		arrA = true;
		for (int j = 0; j < k; j++) //цикл проверки массива на совпадение
		{
			if (randomA == A[j]) //условие совпадения
			{
				arrA = false;//Найдено хотя бы одно совпадение
				break;
			}
			else continue; //если повтора нет, переходим к следующей итерации
		}
		if (arrA)
		{
			A[i] = randomA;
			i++;
		}
	}
	for (int i = 0; i < k;)
	{
		randomB = 1 + rand() % 20;
		arrB = true;
		for (int j = 0; j < k; j++)
		{
			if (randomB == B[j])
			{
				arrB = false;
				break;
			}
			else continue;
		}
		if (arrB)
		{
			B[i] = randomB;
			i++;
		}
	}
	cout << " Массив А: ";
	for (int i = 0; i < k; i++)
	{
		cout << A[i] << " ";
	}

	cout << "\n" << " Массив B: ";
	for (int i = 0; i < k; i++)
	{
		cout << B[i] << " ";
	}
	cout << "\n";

	int ic = 0;
	for (int i = 0; i < k; i++)
	{
		for (int x = 0; x < k; x++)
		{
			if (A[i] == B[x])
			{
				C[ic] = A[i];
				ic++;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (i == 0 && C[i] == 0)
		{
			cout << " Общих элементов не найдено!!!\n";
			return 0;
		}
	}

	cout << "\n" << " Массив C: ";
	for (int i = 0; i < ic; i++)
	{
		cout << C[i] << " ";
	}
	cout << "\n";
}
