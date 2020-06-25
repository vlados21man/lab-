#include<iostream>

#include<Windows.h>

using namespace std;

const int NotName = system("color f0");

struct Information

{

	char nos[20];

	char ob[20];

	char av[20];

	char naz[20];

	union {

		int cs_int;

		double cs_double;

	}a;

	int num;

};

void output_serv(Information crsrv) {

	setlocale(0, "rus");

	cout << "Носитель: " << crsrv.nos << endl;

	cout << "Объем: " << crsrv.ob << endl;

	cout << "Название: " << crsrv.naz << endl;

	cout << "Автор: " << crsrv.av << endl;

	cout << endl << endl;

}

int main()

{

	int numinform;

	Information* inform = new Information[1];

	setlocale(LC_ALL, "rus");

	bool exit = false;

	while (1)

	{

		system("cls");

		int vibor;

		cout << "Выберите раздел\n";

		cout << "1. Ввод массива структур\n";

		cout << "2. Вывод массива структур\n";

		cout << "3. Сортировка массива структур\n";

		cout << "4. Поиск заданного массива по заданному параметру\n";

		cout << "5. Изменение заданной структуры\n";

		cout << "6. Удаление структуры из массива\n";

		cout << "7. Выход\n";

		cout << ">>> ";

		cin >> vibor;

		if (vibor == 1) {

			exit = true;

			cout << "Введите кол-во информации: "; cin >> numinform;

			delete[]inform;

			inform = new Information[numinform];

			for (int i = 0; i < numinform; i++)

			{

				system("cls");

				inform[i].num = i + 1;

				cout << inform[i].num << " Информация\n\n";

				cout << "Носитель "; cin >> inform[i].nos;

				cout << "Объем "; cin >> inform[i].ob;

				cout << "Название "; cin >> inform[i].naz;

				cout << "Автор "; cin >> inform[i].av;

			}

		}

		else if (vibor == 2) {

			if (!exit) {

				cout << "Ошибка! " << endl;

				Sleep(1000);

				continue;

			}

			for (int i = 0; i < numinform; i++) {

				output_serv(inform[i]);

			}

			system("pause");

		}

		else if (vibor == 3) {

			if (!exit) {

				cout << "Ошибка! " << endl;

				Sleep(1000);

				continue;

			}

			cout << "Сортировка по:\n1- Названию;\n2- Автору;\n";

			int a;

			cin >> a;

			Information inform_copy;

			if (a == 1) {

				for (int i = 0; i < (numinform - 1); i++) {

					if (inform[i].naz[0] > inform[i + 1].naz[0]) {

						int informnum = inform[i].num;

						inform[i].num = inform[i + 1].num;

						inform[i + 1].num = informnum;

						inform_copy = inform[i];

						inform[i] = inform[i + 1];

						inform[i + 1] = inform_copy;

					}

				}

			}

			else if (a == 2) {

				for (int i = 0; i < (numinform - 1); i++) {

					if (inform[i].av[0] > inform[i + 1].av[0]) {

						int informnum = inform[i].num;

						inform[i].num = inform[i + 1].num;

						inform[i + 1].num = informnum;

						inform_copy = inform[i];

						inform[i] = inform[i + 1];

						inform[i + 1] = inform_copy;

					}

				}

			}

			else

				cout << "Ошибка! ";

			continue;

		}

		else if (vibor == 4) {

			if (!exit) {

				cout << "Ошибка! " << endl;

				Sleep(1000);

				continue;

			}

			char search[20];

			cout << "Поиск по:\n1- Название;\n2- Автор;\n";

			int a;

			cin >> a;

			if (a == 1) {

				cout << "Поиск ";

				cin >> search;

				cout << endl << endl;

				for (int i = 0; i < numinform; i++) {

					if (strcmp(search, inform[i].naz) == 0) {

						output_serv(inform[i]);

					}

				}

				system("pause");

			}

			else if (a == 2) {

				cout << "Поиск ";

				cin >> search;

				cout << endl << endl;

				for (int i = 0; i < numinform; i++) {

					if (strcmp(search, inform[i].av) == 0) {

						output_serv(inform[i]);

					}

				}

				system("pause");

			}

			else

				cout << "Ошибка! ";

			Sleep(1000);

			continue;

		}

		else if (vibor == 5) {

			if (!exit) {

				cout << "Ошибка! " << endl;

				Sleep(1000);

				continue;

			}

			for (int i = 0; i < numinform; i++) {

				output_serv(inform[i]);

			}

			int a;

			cout << "\n\nВыберите что хотите изменить:\t"; cin >> a;

			a = a - 1;

			system("cls");

			cout << "Введите носителя: "; cin >> inform[a].nos;

			cout << "Введите объем: "; cin >> inform[a].ob;

			cout << "Введите название:"; cin >> inform[a].naz;

			cout << "Введите автор:"; cin >> inform[a].av;

		}

		else if (vibor == 6) {

			if (!exit) {

				cout << "Ошибка!" << endl;

				Sleep(1000);

				continue;

			}

			for (int i = 0; i < numinform; i++) {

				output_serv(inform[i]);

			}

			cout << "Выберите какую информацию удалить\n";

			int a;

			cin >> a;

			if (a > numinform || a == 0) {

				cout << "Ошибка!";

				Sleep(1000);

				continue;

			}

			int i = 0;

			numinform = numinform - 1;

			for (i = (a - 1); i < numinform; i++) {

				int informnum = inform[i].num;

				inform[i].num = inform[i + 1].num;

				inform[i + 1].num = informnum;

				inform[i] = inform[i + 1];

			}

			Information* inform_copy = new Information[numinform];

			for (int i = 0; i < numinform; i++) {

				inform_copy[i] = inform[i];

			}

		}

		else if (vibor == 7)break;

		else {

			cout << "Ошибка!" << endl;

			Sleep(1000);

			continue;

		}

	}

}
