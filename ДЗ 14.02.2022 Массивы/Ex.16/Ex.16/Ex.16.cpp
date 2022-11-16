//Ex.16
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "rus");
	cout << " Кинотеатр\n\n";
	cout << " Сколько необходимо билетов на соседние места в одном ряду:\n";
	int numb;
	cin >> numb;
	const int rows = 6;
	const int cols = 7;
	int arr[rows][cols] = {};

	cout << " Зал кинотеатра на текущий момент: \n";
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			arr[y][x] = rand() % 2;
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
	int count = 0, y, copycount = 0;
	for (y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (arr[y][x] == 0)
			{
				count++;
			
				if (count >= numb)
				{
					copycount = count;
				}
				if (x == cols) count = 0;
			}
			else if (arr[y][x] == 1) 
			{
				count = 0;
			}
		}		
	}

	if (copycount >= numb)
	{
		cout << " В кинотеатре есть " << numb << " свободных мест!\n";
	}
	else
	{
		cout << " К сожалению, в кинотеатре нет " << numb << " свободных соседних мест!\n";
	}	
}