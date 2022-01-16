#include<iostream>
#include <map>
using namespace std;

//const int MAX = 100

map<char, pair<char, char>> tree;

void preorder(char node) {
	cout << node;
	if (tree[node].first != '.') {
		preorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		preorder(tree[node].second);
	}
}
void inorder(char node) {
	if (tree[node].first != '.') {
		inorder(tree[node].first);
	}
	cout << node;
	if (tree[node].second != '.') {
		inorder(tree[node].second);
	}
}
void postorder(char node) {
	if (tree[node].first != '.') {
		postorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		postorder(tree[node].second);
	}
	cout << node;
}
int number;

int main()
{
	cin >> number;
	


	for (int i = 0; i < number; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a] = make_pair(b, c);
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}
