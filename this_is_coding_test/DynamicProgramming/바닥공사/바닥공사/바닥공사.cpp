// 바닥공사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>

int main()
{
	int width;
	std::cin >> width;

	std::array<int,1001> nTiling;

	nTiling[1] = 1;
	nTiling[2] = 3;

	for (int i = 3; i < nTiling.size(); i++)
	{
		nTiling[i] = (nTiling[i - 1] + nTiling[i - 2] * 2) % 796796;
	}

	std::cout << nTiling[width] << std::endl;

	return EXIT_SUCCESS;
}

