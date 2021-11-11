#include <iostream>
#include <iomanip>

using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Q, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);
void Sort(int** a, const int rowCount, const int colCount);
void Calculation(int** a, const int colCount, const int rowCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));
	int S = 0, k = 0;
	int Low = 7;
	int High = 62;

	int rowCount = 7;
	int colCount = 6;

	int** Q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Q[i] = new int[colCount];

	Create(Q, rowCount, colCount, Low, High);
	Print(Q, rowCount, colCount);
	Sort(Q, rowCount, colCount);
	Print(Q, rowCount, colCount);

	Calculation(Q, colCount ,rowCount ,S, k);
	cout << "S=" << S << endl;
	cout << "k=" << k << endl;
	Print(Q, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] Q[i];
	delete [] Q;

	return 0;
}
void Create(int** Q, const int rowCount, const int colCount, const int Low,const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			Q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Q, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Q[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j=0; j<rowCount;j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}

void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
	for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
		if ((a[0][i1] < a[0][i1 + 1])
			||
			(a[0][i1] == a[0][i1 + 1] &&
			 a[1][i1] > a[1][i1 + 1])
			||
			(a[0][i1] == a[0][i1 + 1] &&
			 a[1][i1] == a[1][i1 + 1] &&
		   	a[2][i1] > a[2][i1 + 1]))
			Change(a, i1, i1 + 1, rowCount);
}

void Calculation(int** a, const int colCount, const int rowCount, int& S, int& k)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 2 == 0 && !((i + j) & 8 == 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}