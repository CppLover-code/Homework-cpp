//Ex.13
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(0, "rus");
	cout << " Заполнить трёхмерный массив N x N x N нулями. В получившийся куб вписать шар,\n";
	cout << " состоящий из единиц. После чего, разрезать куб на N слоёв, и показать каждый слой в \n";
	cout << " виде двумерного массива N x N на экране консоли.\n\n";

	const int a = 3;
	int arr[a][a][a] = {};
	double numb;
	int n = a;
	int arr1[a][a * a] = {};
	int v = 0, v1 = 0;
	cout << " Трёхмерный массив: \n";
	for (int i = 0; i < a; i++) 
	{
		for (int j = 0; j < a; j++) 
		{
			for (int k = 0; k < a; k++)  
			{
				numb = sqrt(pow((i - (a / 2)), 2) + pow((j - (a / 2)), 2) + pow((k - (a / 2)), 2));

				if (numb <= a / 2) 
				{
					arr[i][j][k] = 1;
				}
				else 
{
					arr[i][j][k] = 0;
				}

				cout << arr[i][j][k] << " ";
			}
				cout << "\n";
		}
			cout << "\n";
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			for (int k = 0; k < a; k++)
			{
				if (i < n)
				{
					arr1[v][v1] = arr[i][j][k];
					v1++;
				}
			}
		}
		v++;
		v1 = 0;
	}
	cout << " Куб в разрезе: \n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a * a; j++)
		{
			cout << arr1[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}