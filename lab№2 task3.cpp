#include<iostream>

using namespace std;

int Fib(int number)

{

	if (number < 1)

		return 0;

	if (number == 1)

		return 1;

	if (number > 20)

	{

		cout << "Число слишком большое ";

		return 0;

	}

	else

		return Fib(number - 1) + Fib(number - 2);

}

int main()

{

	setlocale(0, "ru");

	int result1 = Fib(21);

	cout << "Fib(21) " << result1 << endl;

	int result2 = Fib(1);

	cout << "Fib(1) " << result2 << endl;

	int result3 = Fib(8);

	cout << "Fib(8) " << result3 << endl;

	int result4 = Fib(0);

	cout << "Fib(0) " << result4 << endl;

	int result5 = Fib(5);

	cout << "Fib(5) " << result5 << endl;

	return 0;
