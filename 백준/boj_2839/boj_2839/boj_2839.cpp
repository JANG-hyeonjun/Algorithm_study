// boj_2839.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int dp[50001];

int main()
{
	int N;
	std::cin >> N;

	dp[3] = 1;
	dp[5] = 1;


	for (int n = 6; n <= 5000; ++n)
	{
		if (dp[n - 3]) 
			dp[n] = dp[n - 3] + 1;
	
		if (dp[n - 5]) dp[n] = dp[n]? std::min(dp[n], dp[n - 5] + 1) : dp[n - 5] + 1;
	}

	if (dp[N]) std::cout << dp[N] << std::endl;
	else std::cout << "-1" << std::endl;

	return EXIT_SUCCESS;
}

