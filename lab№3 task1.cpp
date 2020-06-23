#include <iostream>

using namespace std;

void hundreds(float);

void dozens(float);

void units(float);

int main()

{

	setlocale(LC_ALL, "ru");

	void (*array[3])(float) = { hundreds,dozens,units };

	cout << "1.Выводит количество сотен числа\n";

	cout << "2.Выводит количество десятков числа\n";

	cout << "3.Выводит количество единиц числа \n\n";

	cout << "Что выбрать?\n ";

	int number;

	cin >> number;

	if (number > 3)

		cout << "Ошибка";

	else {

		number--;

		(*array[number])(number);

	}

	return 0;

}

void hundreds(float)

{

	cout << "Введите трехзначное число: \n";

	int a;

	cin >> a;

	if (a < 100 || a>999)

		cout << "Ошибка";

	else

		cout << "Результат равен: " << a / 100;

}

void dozens(float)

{

	cout << "Введите трехзначное число: \n";

	int a;

	cin >> a;

	if (a < 100 || a>999)

		cout << "Ошибка";

	else

		cout << "Результат равен: " << (a / 10) % 10;

}

void units(float)

{

	cout << "Введите трехзначное число: \n";

	int a;

	cin >> a;

	if (a < 100 || a>999)

		cout << "Ошибка";

	else

		cout << "Результат равен: " << a % 100;

}
