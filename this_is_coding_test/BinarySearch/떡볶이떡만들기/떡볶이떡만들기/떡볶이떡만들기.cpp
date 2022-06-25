// 떡볶이떡만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int Parametric_BinarySearch(int start,int end,int targetLength, std::vector<int>& vec)
{
	int result = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int target_sum = 0;

		for (std::vector<int>::size_type idx = 0; idx < vec.size(); ++idx)
		{
			if (vec.at(idx) < mid) continue;
			else target_sum += vec.at(idx) - mid;
		}

		if (target_sum >= targetLength)
		{
			result = mid;
			//이값은 시간이 지날수록 최적화된 값을 찾음
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

	}
	return result;
}

int main()
{
	int rice_cakeCount,targetLength;
	std::vector<int> rice_cakeLengths;
	
	std::cin >> rice_cakeCount >> targetLength;

	for (int i = 0; i < rice_cakeCount; ++i)
	{
		int length = 0;
		std::cin >> length;
		rice_cakeLengths.emplace_back(length);
	}

	int minLength = 0;
	int maxLength = *std::max_element(rice_cakeLengths.begin(), rice_cakeLengths.end());

	std::cout << Parametric_BinarySearch(minLength, maxLength, targetLength, rice_cakeLengths) << std::endl;

	return 0;
}

