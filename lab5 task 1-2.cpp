#include "Node.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include "Queue.h"
#include <fstream>
#include "List.h"
#include <random>
#include <string>

int rand_int(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

void create(Node*& root, int value, int max)
{
    if (value > max) return;
    root = new Node();
    root->value = value;

    create(root->left, value + 1, max);
    create(root->right, value + 1, max);
}

void printBT(const std::wstring& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::wcout << prefix;
        std::wcout << (isLeft ? L"├──" : L"└──");
        std::wcout << node->value << std::endl;

        printBT(prefix + (isLeft ? L"│   " : L"    "), node->left, true);
        printBT(prefix + (isLeft ? L"│   " : L"    "), node->right, false);
    }
}
Queue<char> readFile(const char* path)
{
    Queue<char> queue = *new Queue<char>();
    ifstream file(path);

    char temp;
    while (!file.eof())
    {
        file >> temp;
        queue.push(temp);
    }

    return queue;
}

