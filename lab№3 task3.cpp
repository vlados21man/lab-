#include<iostream>

#include<string>

#include<fstream>

using namespace std;

int main()

{

	setlocale(0, "ru");

	string S = "String";

	ofstream file;

	file.open("Vlados.txt", ofstream::app);

	file << " ";

	if (!file.is_open()) cout << "Error\n";

	else

		for (int i = 0; i < S.length(); i++) {

			file << S[i];

		}

	file.close();

	return 0;

}