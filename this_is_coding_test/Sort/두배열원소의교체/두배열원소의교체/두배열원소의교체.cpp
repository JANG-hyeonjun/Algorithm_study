// 두배열원소의교체.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

static int number = 0;
static int chance = 0;
static std::vector<int> vecA;
static std::vector<int> vecB;


int main()
{
	std::cin >> number >> chance;
	for (int i = 0; i < number; ++i)
	{
		int vecA_Value = 0;
		std::cin >> vecA_Value;
		vecA.emplace_back(vecA_Value);
	}

	for (int i = 0; i < number; ++i)
	{
		int vecB_Value = 0;
		std::cin >> vecB_Value;
		vecB.emplace_back(vecB_Value);
	}

	std::sort(vecA.begin(), vecA.end());
	std::sort(vecB.begin(), vecB.end(),std::greater<int>());

	for (std::vector<int>::size_type i = 0; i < chance; ++i)
	{
		if (vecA.at(i) < vecB.at(i))
		{
			std::swap(vecA.at(i), vecB.at(i));
		}
		else
			break;
	}

	std::cout << std::accumulate(vecA.begin(), vecA.end(), 0) << std::endl;
	return 0;
}

