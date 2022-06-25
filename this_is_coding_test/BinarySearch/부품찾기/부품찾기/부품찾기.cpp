// 부품찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool Binary_Search(std::vector<int>& vec,int target)
{
	int start = 0, end = vec.size() -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (vec.at(mid) == target)
		{
			return true;
		}
		else if (vec.at(mid) < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return false;
}

int main()
{
	int N, M = 0;
	std::vector<int> vec,findvec;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int value = 0;
		std::cin >> value;
		vec.emplace_back(value);
	}

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int value = 0;
		std::cin >> value;
		findvec.emplace_back(value);
	}

	std::sort(vec.begin(), vec.end());

	for (std::vector<int>::size_type idx = 0; idx < findvec.size(); ++idx)
	{
		if (Binary_Search(vec, findvec.at(idx)))
		{
			std::cout << "yes" << std::endl;
		}
		else
		{
			std::cout << "no" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}