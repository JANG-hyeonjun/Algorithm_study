// 개미전사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

static int number;
static std::vector<int> vec;
static std::vector<int> ansVec;

int main()
{
	vec.assign(100, 0);
	ansVec.assign(100, 0);

	//이렇게하면 배열처럼쓸수는 있지만 애초에 vector의 장점은 들어오는 크기의 개수를 모을 때 좋기 때문에 
	//배열을 사용하는것이 좋은 판단 왜냐면 이미 문제에서 개수를 주어 주었기 때문이다. 

	std::cin >> number;

	for (int idx = 0; idx < number; ++idx)
	{
		int temp;
		std::cin >> temp;
		vec.at(idx) = temp;
	}

	ansVec.at(0) = vec.at(0);
	ansVec.at(1) = std::max(vec.at(0), vec.at(1));

	for (int ansIdx = 2; ansIdx < number; ++ansIdx)
	{
		ansVec.at(ansIdx) = std::max(ansVec.at(ansIdx - 1), ansVec.at(ansIdx - 2) + vec.at(ansIdx));
		//이미 여기서 arr[i-3] 에 대한 최적의해는 arr[i -1] 과 arr[i - 2]를 구하는 과정해서 이미 계산 되었다
	}

	std::cout << ansVec[number - 1] << std::endl;

	return EXIT_SUCCESS;
}

