// boj_1120.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <numeric>
#include <string>
#include <cmath>

int main()
{
	auto minAnswer = std::numeric_limits<int>::max();
	int count = 0;
	std::string A, B;
	std::cin >> A >> B;

	if (A.length() - B.length() == 0)
	{
		for (size_t idx = 0; idx < B.length(); ++idx)
		{
			if (A[idx] != B[idx])
				count++;
		}
		minAnswer = count;
	}
	else
	{
		int difference = std::abs(static_cast<int>(A.length() - B.length()));
		for (int idx = 0; idx <= difference; ++idx)
		{
			count = 0;
			for (int i = 0; i < A.length(); ++i)
			{
				if (A[i] != B[i + idx])
					count++;
			}
			if (minAnswer > count)
				minAnswer = count;
		}	
	}
	std::cout << minAnswer << std::endl;
	return 0;
}

