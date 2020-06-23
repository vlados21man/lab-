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

		int step = vector.size() / 2;

		while (step > 0)

		{

			for (int i = 0; i < (vector.size() - step); i++)

			{

				int j = i;

				while (j >= 0 && vector[j] > vector[j + step])

				{

					int temp = vector[j];

					vector[j] = vector[j + step];

					vector[j + step] = temp;

					j--;

				}

			}

			step = step / 2;

		}

		cout << "После сортировки: " << endl;

		for (int i = 0; i < vector.size(); i++)

			cout << vector[i] << " ";

		file.close();

		ofstream file2;

		file2.open("Vlados.txt", ofstream::app);

		file2 << endl;

		if (!file2.is_open()) cout << "Error\n";

		for (int i = 0; i < vector.size(); i++) {

			file2 << vector[i] << " ";

		}

		file2.close();

	}

	return 0;

}
