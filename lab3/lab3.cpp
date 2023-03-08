#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
struct Node 
{
	int data;
	Node* left, * right;
};

void push(int num, Node** tree) 
{
	if ((*tree) == NULL) 
	{
		(*tree) = new Node;
		(*tree)->data = num;
		(*tree)->left = (*tree)->right = NULL;
		return;
	}
	if (num > (*tree)->data) push(num, &(*tree)->right);
	else push(num, &(*tree)->left);
}

void print(Node* tree)
{
	if (tree == NULL) return;
	print(tree->right);
	cout << tree->data << " " << endl;
	print(tree->left);
}

void print2(Node* tree, int level)
{
	if (tree)
	{
		print2(tree->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << tree->data << endl;
		print2(tree->right, level + 1);
	}
}

int main()
{
	srand(time(NULL));
	system("chcp 1251>nul");
	Node* tree = NULL;
	for (int i = 0; i < 5; i++)
	{
		push(rand()%9+1, &tree);
	}
	cout << "Дерево: " << endl;
	print2(tree, 0);
	cout << "Елементи дерева, виведені за зменшенням" << endl;
	print(tree);
	return 0;
}