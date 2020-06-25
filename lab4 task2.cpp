#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int k, l, n, m, N, M;
	cout << "Количество матриц k в первом файле: ";
	cin >> k;
	vector<int> arr(k);
	vector<int> arr1(k);
	ofstream binfile("binfile.txt", ios::app);
	vector<int> matrix_vector;
	for (int i = 0; i < k; i++)
	{
		N = (rand() % 9) + 2;
		int** matrix = new int* [N];
		arr[i] = N;
		M = (rand() % 9) + 2;
		arr1[i] = M;
		for (int j = 0; j < N; j++)
		{
			matrix[j] = new int[M];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				matrix[i][j] = rand() % 100;
				binfile << matrix[i][j] << " ";
				cout << matrix[i][j] << " ";
				matrix_vector.push_back(matrix[i][j]);
			}
			binfile << "\n";
			cout << "\n";
		}
		binfile << "\n\n";
		cout << "\n\n";
		for (int j = 0; j < N; j++)
		{
			delete[] matrix[j];
		}
		delete[] matrix;
	}
	binfile.close();
	cout << "Количество матриц l во втором файле: ";
	cin >> l;
	cout << "Количество строк в матрицах: ";
	cin >> n;
	cout << "Количество столбцов в матрицах: ";
	cin >> m;
	ofstream binfile1("binfile1.txt", ios::app);
	for (int i = 0; i < l; i++)
	{
		int** matrix1 = new int* [n];
		for (int j = 0; j < n; j++)
		{
			matrix1[j] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix1[i][j] = rand() % 100;
				binfile1 << matrix1[i][j] << " ";
				cout << matrix1[i][j] << " ";
			}
			binfile1 << "\n";
			cout << "\n";
		}
		binfile1 << "\n\n";
		cout << "\n\n";

		for (int j = 0; j < n; j++)
		{
			delete[] matrix1[j];
		}
		delete[] matrix1;
	}
	binfile1.close();
	int a = 0;
	ofstream binfile2("binfile1.txt", ios::app);
	for (int i = 0; i < k; i++)
	{
		if (arr[i] != n && arr1[i] != m)
		{
			for (int j = 1; j < (arr[i] * arr1[i]) + 1; j++)
			{
				binfile2 << matrix_vector[j - 1] << " ";
				if (j == arr1[i] + a && j != 0)
				{
					binfile2 << "\n";

					a += arr1[i];
				}
			}
			binfile2 << "\n\n";
			a = 0;
			if (i != k - 1)
			{
				for (int y = 0; y < arr[i] * arr1[i]; y++)
					matrix_vector.erase(matrix_vector.begin());
			}
		}
		else
		{
			if (i != k - 1)
			{
				for (int x = 0; x < arr[i] * arr1[i]; x++)
					matrix_vector.erase(matrix_vector.begin());
			}
		}
	}
	binfile2.close();
	cout << "\b\b\b";
	string str;
	ifstream binfile3("binfile.txt");
	ifstream binfile4("binfile1.txt");
	cout << "\nПервый файл:\n";
	while (getline(binfile3, str))
	{
		cout << str << endl;
	}
	cout << "\n\nВторой файл:\n";
	while (getline(binfile4, str))
	{
		cout << str << endl;
	}
	return 0;
}
