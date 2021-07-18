#include <iostream>

using namespace std;

int gcd(int num1,int  num2)
{
    int temp;
    while(num2 != 0)
    {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main() {

    int num1,num2;
    int gcd_answer,lcm_answer;

    cin >> num1 >> num2;

    gcd_answer = gcd(num1,num2);
    lcm_answer = (num1 * num2) / gcd_answer;

    cout << gcd_answer << '\n' << lcm_answer;

    return 0;
}
