// Simple_Dijkstra.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<bool> visited;
std::vector<int> distance;
std::vector<std::vector<std::pair<int,int>>> myGraph;
constexpr int INF = std::numeric_limits<int>::max();
int N ,  M;

int get_smallestNode()
{
	int min_value = INF;
	int smallestIdx = 0;
	for (int idx = 1; idx < distance.size(); ++idx)
	{
		if (distance[idx] < min_value && visited[idx] == false)
		{
			min_value = distance[idx];
			smallestIdx = idx;
		}
	}
	return smallestIdx;
}

void dijkstra(int startNode)
{
	distance[startNode] = 0;
	visited[startNode] = true;
	
	for (int idx = 0; idx < myGraph[startNode].size(); ++idx)
	{
		distance[myGraph[startNode][idx].first] = myGraph[startNode][idx].second;
	}

	for (int idx = 1; idx <= N; ++idx)
	{
		auto now = get_smallestNode();
		visited[now] = true;
		
		for (int j = 0; j < myGraph[now].size(); ++j)
		{
			auto cost = distance[now] + myGraph[now][j].second;
			//거쳐가는 경로가 현재 경로보다 적을 경우
			if (cost < distance[myGraph[now][j].first])
			{
				distance[myGraph[now][j].first] = cost;
			}
		}
	}
}

int main()
{
	int startNode = 0;
	
	std::cin >> N >> M;

	std::cin >> startNode;

	myGraph.resize(N + 1, std::vector<std::pair<int, int>>());
	
	for (int i = 0; i <= N; ++i)
	{
		visited.emplace_back(false);
		distance.emplace_back(INF);
	}

	for (int i = 0; i < M; i++)
	{
		int from = 0, to = 0, value = 0;
		std::cin >> from >> to >> value; 
		myGraph[from].emplace_back(std::make_pair(to, value));
	}

	dijkstra(startNode);

	for (int idx  = 1; idx < distance.size(); ++idx)
	{
		std::cout << distance[idx] << std::endl;
	}

	return EXIT_SUCCESS;
}

/*해당 알고리즘의 시간 복잡도는 O(V)번에 걸쳐서 최단거리가 가장 짧은 노드를 탐색해야 하며
  현재 노드와 연결된 노드를 매번 일일히 확인해야 한다. 결국 이중 반복문 
  따라서 코딩 테스트를 볼때 노드의개수가 5000개 이하라면 일반적으로 이알고리즘을 응용해서 풀수 있으나
  노드의개수가 10000개가 넘어간다면 사용할수 없다. 
*/
