#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 20001;
#define INF 987654321
//vector <int> graph[MAX];
vector<pair<int, int>> Vertex[MAX];
//vector <int> cost[MAX];
int Table[MAX];
bool Check[MAX];
int V, E;
int start;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		Vertex[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= V; i++) Table[i] = INF;

	//그래프를 만든다.


	//다익스트라를 완료한다. 
	//설계 1) 최솟값을 구한다. 단 , 지금까지 최단거리로  확장되지 않았던 정점에 대해서 
	//        2) 그 최솟값을 갖는 노드로 부터 뻗어 간다. 
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start));
	Table[start] = 0;

	while (PQ.empty() == 0)
	{
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Vertex[Cur].size(); i++)
		{
			int Next = Vertex[Cur][i].first;
			int nCost = Vertex[Cur][i].second;

			if (Table[Next] > Cost + nCost)
			{
				Table[Next] = Cost + nCost;
				PQ.push(make_pair(-Table[Next], Next));
			}
		}
	}

	
	//완성 

	//정답 출력 부분 
	for (int i = 1; i <= V; i++)
	{
		if (Table[i] == INF)	cout << "INF" << '\n';
		else cout << Table[i] << '\n';
	}
	return 0;
}
