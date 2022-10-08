// 1로만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <numeric>

const int MAX = 30001;
static int number;

void dp(int number, std::vector<int>& vec)
{
	for (int idx = 2; idx <= number; ++idx)
	{
		vec[idx] = vec[idx - 1] + 1;
		
		if (idx % 3 == 0)
			vec[idx] = std::min(vec[idx], vec[idx / 3] + 1);
		if (idx % 2 == 0)
			vec[idx] = std::min(vec[idx], vec[idx / 2] + 1);
		if (idx % 5 == 0)
			vec[idx] = std::min(vec[idx], vec[idx / 5] + 1);
	}
}

int main()
{
	std::vector<int> vec(MAX,0);
	
	std::cin >> number;
	dp(number, vec);
	std::cout << vec[number] << std::endl;

	return EXIT_SUCCESS;
}


