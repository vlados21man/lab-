#include<iostream>

#include<string>

#include<Windows.h>

using namespace std;

int main()

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "rus");

	cout << "Введите строку ";

	string str;

	getline(cin, str);

	cout << "Какой символ удалить из строки ";

	char ch;

	cin >> ch;

	for (int i = 0; i < str.length(); i++)

	{

		if (str[i] == ch)

		{

			str.erase(str.begin() + i);

			i--;

		}

	}

	for (int i = 0; i < str.length(); i++)

		cout << str[i];

	return 0;

}
