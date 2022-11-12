#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100001;

int N;
//bool check[MAX];
vector <int> Mygraph[MAX];
queue <int> Queue;
int parent[MAX];

void BFS()
{
	Queue.push(1);
	//check[1] = true;
	while (!Queue.empty())
	{
		int current = Queue.front();
		Queue.pop();
		for (int i = 0; i < Mygraph[current].size(); i++)
		{
			int next = Mygraph[current][i];
			if (parent[current] == next) {
				continue;
			}
			else {
				Queue.push(next);
				parent[next] = current;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		Mygraph[a].push_back(b);
		Mygraph[b].push_back(a);
	}
	BFS();
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}
