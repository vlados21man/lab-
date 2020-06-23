#include<iostream>

using namespace std;

void Foo(double* arr, int size, int k);

double randfrom(double min, double max);

void FillArray(double* const arr, const int size);

void ShowArray(double* const arr, const int size);

int main()

{

	cout << "enter array size ";

	int size;

	cin >> size;

	double* arr = new double[size];

	FillArray(arr, size);

	ShowArray(arr, size);

	cout << "enter the number of element ";

	int k1;

	cin >> k1;

	Foo(arr, size, k1);

	for (int i = 0; i < size; i++)

		cout << arr[i] << "\t";

	cout << endl;

	cout << "enter the number of element ";

	int k2;

	cin >> k2;

	Foo(arr, size, k2);

	for (int i = 0; i < size; i++)

		cout << arr[i] << "\t";

	cout << endl;

	cout << "enter the number of element ";

	int k3;

	cin >> k3;

	Foo(arr, size, k3);

	for (int i = 0; i < size; i++)

		cout << arr[i] << "\t";

	cout << endl;

	delete[] arr;

	return 0;

}

void Foo(double* arr, int size, int k)

{

	k--;

	int n = k + 1;

	double sum = 0;

	for (int i = 0; i < size; i++)

	{

		if (i == k)

		{

			for (int j = 0; j <= k; j++)

			{

				sum += (arr[j] / n);

			}

			arr[k] = sum;

			break;

		}

	}

}

double randfrom(double min, double max)

{

	double range = (max - min);

	double div = RAND_MAX / range;

	return round((min + (rand() / div)) * 10) / 10;

}

void FillArray(double* const arr, const int size)

{

	for (int i = 0; i < size; i++) {

		arr[i] = randfrom(1, 15);

	}

}

void ShowArray(double* const arr, const int size)

{

	for (int i = 0; i < size; i++)

		cout << arr[i] << "\t";

	cout << endl;

}
