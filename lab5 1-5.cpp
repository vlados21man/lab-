
#include <iostream>

using namespace std;

struct bstree {

	char* key;

	int value;

	bstree* left, * right;

};

struct bstree* bstree_create(char*, int);


void bstree_add(struct bstree*, char*, int);


struct bstree* bstree_lookup(struct bstree*, char*);


struct bstree* bstree_min(struct bstree*);


struct bstree* bstree_max(struct bstree*);


void show(bstree*&); 

void del(bstree*&);

bstree* bstree_create(char* key, int value) {

	bstree* node;

	node = new bstree;

	if (node) {

		node->key = _strdup(key);

		node->value = value;

		node->left = 0;

		node->right = 0;

	}

	return node;

}

void bstree_add(bstree* tree, char* key, int value) {

	bstree* root;

	bstree* node;

	if (!tree) return;

	root = tree;

	while (tree) {

		root = tree;

		if (strcmp(key, tree->key) < 0)

			tree = tree->left;

		else if (strcmp(key, tree->key) > 0)

			tree = tree->right;

		else return;

	}

	node = bstree_create(key, value);

	if ((strcmp(key, root->key) < 0))

		root->left = node;

	else

		root->right = node;

}

bstree* bstree_lookup(bstree* tree, char* key) {

	if (!tree)return 0;

	if (strcmp(tree->key, key) == 0)

		return tree;

	if (strcmp(key, tree->key) < 0) {

		if (tree->left)

			bstree_lookup(tree->left, key);

		else return 0;

	}

	else if (strcmp(key, tree->key) > 0) {

		if (tree->right)

			bstree_lookup(tree->right, key);

		else return 0;

	}

}

bstree* bstree_min(bstree* tree) {

	if (tree->left)

		bstree_min(tree->left);

	else return tree;

}

bstree* bstree_max(bstree* tree) {

	if (tree->right)

		bstree_max(tree->right);

	else return tree;

}

void show(bstree*& tree) {

	if (tree) {

		show(tree->left);

		cout << tree->key << " - " << tree->value << endl;

		show(tree->right);

	}

}

void del(bstree*& tree) {

	if (tree) {

		del(tree->left);

		del(tree->right);

		delete tree;

		tree = 0;

	}

}

int main() {

	char key[30] = "root";

	bstree* tree = bstree_create(key, strlen(key));

	for (int i = 0; i < 5; i++) {

		cout << "input >>> ";

		cin.getline(key, 30);

		bstree_add(tree, key, strlen(key));

	}

	cout << "TREE:\n\n";

	show(tree);

	cout << endl;

	bstree* temp;

	temp = bstree_min(tree);

	cout << "Min element >>> " << temp->key << " - " << temp->value << endl;

	temp = bstree_max(tree);

	cout << "Max element >>> " << temp->key << " - " << temp->value << endl;

	cout << "Search for >>> ";

	char find[30];

	cin.getline(find, 30);

	temp = bstree_lookup(temp, find);

	cout << "Searched element >>> " << temp->key << " - " << temp->value << endl;

	del(tree);

}


#include<iostream>

#include<list>

#include<queue>

#include<Windows.h>

using namespace std;

enum num

{

	Front,

	Back

};

int main()

{

	queue<int, list<int>> q;

	while (true)

	{

		cout << "Enter 1 to add an item\nEnter 2 to access the item.\n";

		cout << "Enter any other number to exit\n";

		int number;

		cin >> number;

		if (number <= 0 || number > 2)

			return 0;

		if (number == 1)

			q.push(rand() % 15);

		if (number == 2)

		{

			cout << "Enter 1 to access the first item\nEnter 2 to access the last item\n";

			int num;

			cin >> num;

			num--;

			switch (num)

			{

			case Front:

			{

				if (q.empty())

				{

					cout << "No items\n";

					break;

				}

				cout << q.front() << endl;

				q.pop();

				break;

			}

			case Back:

			{

				if (q.empty())

				{

					cout << "No items\n";

					break;

				}

				cout << q.back();

				q.pop();

				break;

			}

			default:

				return 0;

				break;

			}

		}

		Sleep(1000);

		system("cls");

	}

}


#include <iostream>

#include <ctime>

using namespace std;

template<typename T>

class List

{

public:

	List();

	~List();

	void pop_front();

	void push_back(T data);

	void clear();

	int GetSize()

	{

		return Size;

	}

	void push_Front(T data);

	void insert(T value, int index);

	void remove(int index);

	void pop_back();

	T& operator[](const int index);

private:

	template<typename T>

	class Node

	{

	public:

		Node* pNext;

		T data;

		Node(T data = T(), Node* pNext = nullptr)

		{

			this->data = data;

			this->pNext = pNext;

		}

	};

	int Size;

	Node<T>* head;

};

template<typename T>

List<T>::List()

{

	Size = 0;

	head = nullptr;

}

template<typename T>

List<T>::~List()

{

	clear();

}

template<typename T>

void List<T>::pop_front()

{

	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>

void List<T>::push_back(T data)

{

	if (head == nullptr)

	{

		head = new Node<T>(data);

	}

	else

	{

		Node<T>* current = this->head;

		while (current->pNext != nullptr)

		{

			current = current->pNext;

		}

		current->pNext = new Node<T>(data);

	}

	Size++;

}

template<typename T>

void List<T>::clear()

{

	while (Size)

	{

		pop_front();

	}

}

template<typename T>

void List<T>::push_Front(T data)

{

	head = new Node<T>(data, head);

	Size++;

}

template<typename T>

void List<T>::insert(T value, int index)

{

	if (index == 0)

	{

		push_Front(value);

	}

	else

	{

		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++) { previous = previous->pNext; }

		Node<T>* newNode = new Node<T>(value, previous->pNext);

		previous->pNext = newNode;

		Size++;

	}

}

template<typename T>

void List<T>::remove(int index)

{

	if (index == 0)

	{

		pop_front();

	}

	else

	{

		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++) { previous = previous->pNext; }

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;

	}

}

template<typename T>

void List<T>::pop_back()

{

	remove(Size - 1);

}

template<typename T>

T& List<T>::operator[](const int index)

{

	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)

	{

		if (counter == index)

		{

			return current->data;

		}

		current = current->pNext;

		counter++;

	}

}

int main()

{

	setlocale(0, "ru");

	srand(time(NULL));

	List<int> lst;

	lst.push_back(-5);

	lst.push_back(-9);

	lst.push_back(-3);

	lst.push_back(6);

	lst.push_back(-1);

	lst.push_back(0);

	lst.push_back(5);

	for (int i = 0; i < lst.GetSize(); i++)

	{

		cout << lst[i] << "\t";

	}

	for (int i = 0; i < lst.GetSize(); i++)

	{

		if (lst[i] < 0)

		{

			lst.remove(i);

			i--;

		}

	}

	cout << endl;

	for (int i = 0; i < lst.GetSize(); i++)

	{

		cout << lst[i] << "\t";

	}

	return 0;

}


#include<iostream>

#include<list>

using namespace std;

template<typename T>

void PrintList(const list<T>& lst)

{

	for (auto i = lst.cbegin(); i != lst.cend(); ++i)

	{

		cout << *i << "\t";

	}

	cout << endl;

}

int main()

{

	list<int>List1 = { 1,2,3,4,5 };

	list<int>List2;

	auto it = List1.begin();

	advance(it, List1.size() - 1);

	List2.push_back(*it);

	List1.pop_back();

	auto it2 = List2.begin();

	List1.push_front(*it2);

	PrintList(List1);

	return 0;

}

#include<iostream>

#include<list>

using namespace std;

template<typename T>

void PrintList(const list<T>& lst)

{

	for (auto i = lst.cbegin(); i != lst.cend(); ++i)

	{

		cout << *i << "\t";

	}

	cout << endl;

}

int main()

{

	setlocale(0, "ru");

	list<int>myList;

	list<int>List1 = { 1,2,3,4,5 };

	list<int>List2 = { 3,4,5,6,7 };

	myList.merge(List1);

	myList.merge(List2);

	myList.sort();

	myList.unique();

	PrintList(myList);

	return 0;

}
