#include <iostream>
#include "function.h"

//  функции заполнения массивов рандомными значениями
void FillArrayInt(int* arr, size_t length)
{
	if (!arr) // для борьбы с ошибкой arr = NULL
	{  
		std::cout << "fill_random: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++) 
	{
		arr[i] = rand() % 20 + 1;
	}
}
void FillArrayFloat(float* arr, size_t length)
{
	if (!arr) // для борьбы с ошибкой arr = NULL
	{
		std::cout << "fill_random: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = (rand() % 20 + 1) * 0.1;
	}
}
void FillArrayChar(char* arr, size_t length)
{
	if (!arr) // для борьбы с ошибкой arr = NULL
	{
		std::cout << "fill_random: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = char(rand() % 25 + 97);
	}
}

//  функции вывода массивов в консоль
void ShowArrayInt(int* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++) 
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}
void ShowArrayFloat(float* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}
void ShowArrayChar(char* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}

//  функции вычисления макс. и мин. значения массивов
void MinMaxArrayInt(int* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}

	int min = arr[0];
	int i_min = 0;
	int max = arr[0];
	int i_max = 0;

	for (int i = 1; i < length; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			i_min = i;
		}
		if (max < arr[i])
		{
			max = arr[i];
			i_max = i;
		}
	}
	std::cout << "\n" << " Minimum array element - [" << i_min << "] - " << min << "\n";
	std::cout << "\n" << " Maximum array element - [" << i_max << "] - " << max << "\n\n";
}
void MinMaxArrayFloat(float* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}

	float min = arr[0];
	float i_min = 0;
	float max = arr[0];
	float i_max = 0;

	for (int i = 1; i < length; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			i_min = i;
		}
		if (max < arr[i])
		{
			max = arr[i];
			i_max = i;
		}
	}
	std::cout << "\n" << " Minimum array element - [" << i_min << "] - " << min << "\n";
	std::cout << "\n" << " Maximum array element - [" << i_max << "] - " << max << "\n\n";
}
void MinMaxArrayChar(char* arr, size_t length)
{
	if (!arr)
	{
		std::cout << "print_arr: NULL pointer error" << "\n";
		return;
	}

	int min = int(arr[0]);
	int i_min = 0;
	int max = int(arr[0]);
	int i_max = 0;

	for (int i = 1; i < length; i++)
	{
		if (min > int(arr[i]))
		{
			min = int(arr[i]);
			i_min = i;
		}
		if (max < int(arr[i]))
		{
			max = int(arr[i]);
			i_max = i;
		}
	}

	std::cout << "\n" << " Minimum array element - [" << i_min << "] - " << char(min) << "\n";
	std::cout << "\n" << " Maximum array element - [" << i_max << "] - " << char(max) << "\n\n";
}

//  функции сортировки значений массивов по возрастанию
void SortArrayInt(int* arr, size_t length)
{
	int temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (int i = 0; i < length - 1; i++) 
	{
		for (int j = 0; j < length - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	std::cout << " Array sort: ";
	ShowArrayInt(arr, length);
	std::cout << "\n";
}
void SortArrayFloat(float* arr, size_t length)
{
	float temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	std::cout << " Array sort: ";
	ShowArrayFloat(arr, length);
	std::cout << "\n";
}
void SortArrayChar(char* arr, size_t length)
{
	char tmp;
	bool flag;
	do
	{
		flag = true;
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = false;
			}
		}
	} while (!flag);

	std::cout << " Array sort: ";
	ShowArrayChar(arr, length);
	std::cout << "\n";
}

//  функции редактирования значений массивов
void EditArrayInt(int* arr, size_t length)
{
	int r, n;
	std::cout << " Enter the value to be replaced:\n";
	std::cin >> r;
	std::cout << " Enter a new value:\n";
	std::cin >> n;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == r) 
		{
			arr[i] = n;
		}
	}
	std::cout << " Result with replacement: ";
	ShowArrayInt(arr, length);
	std::cout << "\n";
}
void EditArrayFloat(float* arr, size_t length)
{
	float r, n;
	std::cout << " Enter the value to be replaced:\n";
	std::cin >> r;
	std::cout << " Enter a new value:\n";
	std::cin >> n;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == r)
		{
			arr[i] = n;
		}
	}
	std::cout << " Result with replacement: ";
	ShowArrayFloat(arr, length);
	std::cout << "\n";
}
void EditArrayChar(char* arr, size_t length)
{
	char r, n;
	std::cout << " Enter the value to be replaced:\n";
	std::cin >> r;
	std::cout << " Enter a new value:\n";
	std::cin >> n;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == r)
		{
			arr[i] = n;
		}
	}
	std::cout << " Result with replacement: ";
	ShowArrayChar(arr, length);
	std::cout << "\n";
}

void Integer(int* arr, size_t length)  // функция, сожержащая все функции для Int
{
	FillArrayInt(arr, length);
	ShowArrayInt(arr, length);
	MinMaxArrayInt(arr, length);
	SortArrayInt(arr, length);
	EditArrayInt(arr, length);
}
void Float(float* arr, size_t length)  // функция, сожержащая все функции для Float
{
	FillArrayFloat(arr, length);
	ShowArrayFloat(arr, length);
	MinMaxArrayFloat(arr, length);
	SortArrayFloat(arr, length);
	EditArrayFloat(arr, length);
}
void Char(char* arr, size_t length)  // функция, сожержащая все функции для Char
{
	FillArrayChar(arr, length);
	ShowArrayChar(arr, length);
	MinMaxArrayChar(arr, length);
	SortArrayChar(arr, length);
	EditArrayChar(arr, length);
}
