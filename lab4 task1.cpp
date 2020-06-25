#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h.>
#include <windows.h>
#include <stdlib.h>

using namespace std;

class Buyer
{
public:
	string surname;
	string name;
	string patronymic;
	string gender;
	string nationality;
	int height = 0;
	string weight;
	string year_of_birth;
	string month_of_birth;
	string day_of_birth;
	string telephon_num;
	string postcode;
	string country;
	string region;
	string district;
	string town;
	string street;
	string house;
	string appartment;
	string credit_card_num;
	string bank_account_num;
};

ostream& operator << (ostream& os, const Buyer& buyer)
{
	os << buyer.name << "\n"
		<< buyer.surname << "\n"
		<< buyer.patronymic << "\n"
		<< buyer.gender << "\n"
		<< buyer.nationality << "\n"
		<< buyer.height << "\n"
		<< buyer.weight << "\n"
		<< buyer.year_of_birth << "\n"
		<< buyer.month_of_birth << "\n"
		<< buyer.day_of_birth << "\n"
		<< buyer.telephon_num << "\n"
		<< buyer.postcode << "\n"
		<< buyer.country << "\n"
		<< buyer.region << "\n"
		<< buyer.district << "\n"
		<< buyer.town << "\n"
		<< buyer.street << "\n"
		<< buyer.house << "\n"
		<< buyer.appartment << "\n"
		<< buyer.credit_card_num << "\n"
		<< buyer.bank_account_num << "\n";
	return os;
}
istream& operator >> (istream& is, Buyer& buyer)
{
	is >> buyer.name
		>> buyer.surname
		>> buyer.patronymic
		>> buyer.gender
		>> buyer.nationality
		>> buyer.height
		>> buyer.weight
		>> buyer.year_of_birth
		>> buyer.month_of_birth
		>> buyer.day_of_birth
		>> buyer.telephon_num
		>> buyer.postcode
		>> buyer.country
		>> buyer.region
		>> buyer.district
		>> buyer.town
		>> buyer.street
		>> buyer.house
		>> buyer.appartment
		>> buyer.credit_card_num
		>> buyer.bank_account_num;
	return is;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Buyer* buyer_ = new Buyer[3];
	int choice = 0;
	int number_of_buyers = 0;
	while (choice != 7)
	{
		cout << "\n\n1. Создание файла\n"
			<< "2. Добавление элемента в конец файла\n"
			<< "3. Вывод содержимого файла на экран\n"
			<< "4. Удаление элемента из файла\n"
			<< "5. Сортировка подсчетом\n"
			<< "6. Выход\n\n";
		cout << "Выберите пункт меню(1-6): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			ofstream binfile("binfile.txt");
			if (binfile.is_open())
				cout << "\nФайл успешно создан";
			binfile.close();
			break;
		}
		case 2:
		{
			ofstream binfile("binfile.txt");
			cout << "\nКоличество покупателей: ";
			cin >> number_of_buyers;
			buyer_ = new Buyer[number_of_buyers];
			for (int i = 0; i < number_of_buyers; i++)
			{
				cout << "\n\nПокупатель №" << i + 1;
				cout << "\nВведите имя: ";
				cin >> buyer_[i].name;
				cout << "Введите фамилию: ";
				cin >> buyer_[i].surname;
				cout << "Введите отчество: ";
				cin >> buyer_[i].patronymic;
				cout << "Введите пол: ";
				cin >> buyer_[i].gender;
				cout << "Введите национальность: ";
				cin >> buyer_[i].nationality;
				cout << "Введите рост: ";
				cin >> buyer_[i].height;
				cout << "Введите вес: ";
				cin >> buyer_[i].weight;
				cout << "Введите год рождения: ";
				cin >> buyer_[i].year_of_birth;
				cout << "Введите месяц рождения: ";
				cin >> buyer_[i].month_of_birth;
				cout << "Введите день рождения: ";
				cin >> buyer_[i].day_of_birth;
				cout << "Введите телефонный номер: ";
				cin >> buyer_[i].telephon_num;
				cout << "Введите почтовый индекс: ";
				cin >> buyer_[i].postcode;
				cout << "Введите страна: ";
				cin >> buyer_[i].country;
				cout << "Введите область: ";
				cin >> buyer_[i].region;
				cout << "Введите район: ";
				cin >> buyer_[i].district;
				cout << "Введите город: ";
				cin >> buyer_[i].town;
				cout << "Введите улица: ";
				cin >> buyer_[i].street;
				cout << "Введите дом: ";
				cin >> buyer_[i].house;
				cout << "Введите квартира: ";
				cin >> buyer_[i].appartment;
				cout << "Введите номер кредитной карты: ";
				cin >> buyer_[i].credit_card_num;
				cout << "Введите номер банковского счета: ";
				cin >> buyer_[i].bank_account_num;
				binfile << buyer_[i];
			}
			binfile.close();
			break;
		}
		case 3:
		{
			ifstream binfile("binfile.txt");
			for (int i = 0; i < number_of_buyers; i++)
			{
				cout << "\nПокупатель №" << i + 1 << "\n";
				binfile >> buyer_[i];
				cout << buyer_[i];
			}
			binfile.close();
			break;
		}
		case 4:
		{
			cout << "\nУдалить по номеру(0) или по ключу(1): ";
			int delete_type;
			cin >> delete_type;
			if (delete_type == 0)
			{
				vector<Buyer> buyerVector;
				ifstream binfile("binfile.txt");
				for (int i = 0; i < number_of_buyers; i++)
				{
					binfile >> buyer_[i];
					buyerVector.push_back(buyer_[i]);
				}
				cout << "\nНомер покупателя для удаления: ";
				int num = 0;
				cin >> num;
				buyerVector.erase(buyerVector.begin() + num - 1);
				number_of_buyers--;
				ofstream binfile1("binfile.txt");
				for (int i = 0; i < buyerVector.size(); i++)
					binfile1 << buyerVector[i];
				cout << "\nУдалено";
				binfile1.close();
				break;
			}
			if (delete_type == 1)
			{
				ifstream binfile("binfile.txt");
				vector<Buyer> buyerVector;
				for (int i = 0; i < number_of_buyers; i++)
				{
					binfile >> buyer_[i];
					buyerVector.push_back(buyer_[i]);
				}
				cout << "\nРост покупателя для удаления: ";
				int height_to_delete = 0;
				cin >> height_to_delete;
				for (int i = 0; i < buyerVector.size(); i++)
				{
					if (buyer_[i].height == height_to_delete)
					{
						buyerVector.erase(buyerVector.begin() + i);
						number_of_buyers--;
					}
				}
				binfile.close();
				ofstream binfile1("binfile.txt");
				for (int i = 0; i < buyerVector.size(); i++)
					binfile1 << buyerVector[i];
				cout << "\nУдалено";
				binfile1.close();
				break;
			}
		}
		case 5:
		{
			ifstream binfile("binfile.txt");
			vector<Buyer>buyerVector;
			for (int i = 0; i < number_of_buyers; i++)
			{
				binfile >> buyer_[i];
				buyerVector.push_back(buyer_[i]);
			}
			vector <int> buyer_vector(1024);
			for (int i = 0; i < number_of_buyers; i++)
			{
				buyer_vector[buyer_[i].height] = buyer_vector[buyer_[i].height] + 1;
			}
			int b = 0;
			for (int i = 0; i < buyer_vector.size(); i++)
			{
				for (int j = 0; j < buyer_vector[i]; j++)
				{
					buyer_[b].height = i;
					b = b + 1;
				}
			}
			ofstream binfile1("binfile.txt");
			for (int i = 0; i < number_of_buyers; i++)
				binfile1 << buyer_[i];
			cout << "\nОтсортировано";
			binfile1.close();
			break;
		}
		case 6:
		{
			break;
		}
		}
	}
	return 0;
}

