// boj_2805.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int N, M;
std::vector<int> treeHeight;

long long cutTree(int cutHeightValue)
{
	long long returnVal = 0;
	
	for(int idx = 0; idx < treeHeight.size(); ++idx)
	{
		if (cutHeightValue < treeHeight[idx])
			returnVal += std::abs(cutHeightValue - treeHeight[idx]);
	}
	return returnVal;
}

void solution()
{
	int answer = 0;

	int start = 1;
	int end = 2000000001;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long getTreeHeightValue = cutTree(mid);
	
		if (getTreeHeightValue < M)
		{
			end = mid - 1;
		}
		else if (getTreeHeightValue >= M)
		{
			start = mid + 1;
			answer = std::max(answer, mid);
		}
	}
	std::cout << answer << std::endl;
}

int main()
{
	std::cin >> N >> M;

	for (int count = 0; count < N; ++count)
	{
		int height;
		std::cin >> height;
		treeHeight.emplace_back(height);
	}

	solution();
	return EXIT_SUCCESS;
}

