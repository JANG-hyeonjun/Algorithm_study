// 위에서아래로.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

static int numberTotal = 0;
static std::vector<int> vec;

int main()
{
	std::cin >> numberTotal;
	for (int idx = 0; idx < numberTotal; ++idx)
	{
		int restoreValue = 0;
		std::cin >> restoreValue;
		vec.emplace_back(restoreValue);
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());


	for(std::vector<int>::size_type idx = 0; idx < vec.size(); ++idx)
	{
		std::cout << vec.at(idx) << std::endl;
	}
	
	return 0;
}

