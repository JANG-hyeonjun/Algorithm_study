// 효율적인화폐구성.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <vector>
int main()
{
	int N = 0, M = 0;
	std::cin >> N >> M;

	std::vector<int> coinVec;
	for (int idx = 0; idx < N; ++idx)
	{
		int number;
		std::cin >> number;
		coinVec.emplace_back(number);
	}

	std::array<int, 10001> dp;

	dp[0] = 0;

	for (int idx = 1; idx <= M; ++idx)
	{
		dp[idx] = 10001;
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = coinVec[i]; j <= M; ++j)
		{
			dp[j] = std::min(dp[j], dp[j - coinVec[i]] + 1);
		}
	}

	if (dp[M] == 10001)
		std::cout << "-1" << std::endl;
	else
		std::cout << dp[M] << std::endl;
	
	return EXIT_SUCCESS;
}

