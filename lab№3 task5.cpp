#include<iostream>

#include<string>

#include<fstream>

#include<vector>

using namespace std;

int main()

{

	setlocale(0, "ru");

	ifstream file;

	file.open("Vlados.txt");

	if (!file.is_open()) cout << "Error\n";

	else

	{

		vector<int> vector;

		int number;

		while (!file.eof()) {

			file >> number;

			vector.push_back(number);

		}

		vector.pop_back();

		for (int i = 0; i < vector.size(); i++)

			cout << vector[i] << " ";

		cout << endl;

		cout << "Количество чисел в файле: " << vector.size();

	}

	return 0;

}
