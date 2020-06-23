#include<iostream>

#include<string>

#include<fstream>

#include<vector>

using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian");

	ifstream file;

	file.open("Vlados.txt");

	if (!file.is_open()) cout << "Error\n";

	else

	{

		vector<string> vector;

		string str; ;

		while (!file.eof())

		{

			str = "";

			getline(file, str);

			vector.push_back(str);

		}

		ofstream file2;

		file2.open("Vlados.txt");

		string s;

		for (int i = 0; i < vector.size(); i++)

		{

			s = vector[i];

			if (s[0] == ' ' && s[1] == ' ' && s[2] == ' ' && i > 0)

				s.insert(s.begin(), '\n');

			file2 << s << endl;

		}

	}

	file.close();

	return 0;

}
