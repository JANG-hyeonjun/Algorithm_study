// boj_1543.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	int answer = 0;
	std::string inputStr,subStr;
	std::getline(std::cin, inputStr);
	std::getline(std::cin, subStr);
	
	while (inputStr.find(subStr) != std::string::npos)
	{
		int pos = inputStr.find(subStr);
		++answer;
		inputStr = inputStr.substr(pos + subStr.length(), inputStr.length());
		//inputStr.erase(pos, subStr.length());
		//erase는 해당부분만 삭제 즉 abcedfg 를하고 cde를 찾으면 abfg가 된다. 
		//그런데 substr을 쓰면 abcdefg를 입력후 cde -> fg가 된다.
		std::cout << inputStr << std::endl;
	}
	std::cout << answer << std::endl;


	return 0;
}

