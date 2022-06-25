// 성적이 낮은순으로 학생출력하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <map>

static int numberOfStudent;
std::map<std::string, int> studentMap;
//문제조건에 학생수가 겹칠수 있다는 조건이 없어 unordered map이 아닌 map을 진행 

int main()
{
	std::cin >> numberOfStudent;
	for (int i = 0; i < numberOfStudent; ++i)
	{
		std::string name = "";
		int score = 0;
		std::cin >> name >> score;
		studentMap[name] = score;
	}
	
	for (auto idx = studentMap.begin(); idx != studentMap.end(); ++idx)
	{
		std::cout << idx->first << std::endl;
	}

	return 0;
}

