// Ex.1
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "RUS");
	cout << " \n" << "\n";
	int N = 5;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			if (x + y == N - 1 || x - N + 1 == y) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			if (x == y + 1 || x + y + 1 - N + 1 == N - 1) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			if (x + y >= N - 1 && x < N || x - N + 1 <= y && x >= N ) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			if (x >= y + 1 && x < N || x + y + 1 - N + 1 <= N - 1 && x >= N) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}