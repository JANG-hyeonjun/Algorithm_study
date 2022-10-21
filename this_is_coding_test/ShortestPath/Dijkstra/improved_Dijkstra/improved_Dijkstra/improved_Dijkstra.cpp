// improved_Dijkstra.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

int N, M;
int startNumber;

constexpr int INF = std::numeric_limits<int>::max();

std::vector<std::vector<std::pair<int, int>>> myGraph;
std::vector<int> distance;

void dijkstra(int startNode)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>> Pq;
	Pq.push(std::make_pair(0, startNode));
	distance[startNode] = 0;

	while (!Pq.empty())
	{
		int dist = Pq.top().first;
		int curNode = Pq.top().second;
		Pq.pop();

		//최소라고 해서 꺼냈는데 이미 더 적은 비용의 경로를 안다면 찾을 필요도 없다.
		if (distance[curNode] < dist)
		{
			continue;
		}

		for (int idx = 0; idx < myGraph[curNode].size(); ++idx)
		{
			int cost = dist + myGraph[curNode][idx].second;
			
			if (cost < distance[myGraph[curNode][idx].first])
			{
				distance[myGraph[curNode][idx].first] = cost;
				Pq.push(std::make_pair(cost, myGraph[curNode][idx].first));
			}
		}
	}

	for (int idx = 1; idx <= N; ++idx)
	{
		std::cout << distance[idx] << std::endl;
	}
}

int main()
{
	std::cin >> N >> M;
	std::cin >> startNumber;

	myGraph.resize(N + 1, std::vector<std::pair<int, int>>());
	
	for (int cnt = 0; cnt < M; ++cnt)
	{
		int from = 0, to = 0, value = 0;
		std::cin >> from >> to >> value;
		myGraph[from].emplace_back(std::make_pair(to, value));
	}

	for (int cnt = 0; cnt <= N; ++cnt)
	{
		distance.emplace_back(INF);
	}

	dijkstra(startNumber);

	return 0;
}

