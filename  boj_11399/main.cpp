#include <iostream>
#include <algorithm>

using namespace std;


const int MAX = 1005;
int arr[MAX];
int number;
int answer;
int result[MAX];
int main() {

    cin >> number;
    for(int i =0; i < number; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+number);
    result[0]  = arr[0];
    for(int i =1; i < number; i++)
    {
        result[i] = result[i-1] + arr[i];
    }

    for(int i =0; i < number; i++)
    {
        answer += result[i];
    }
    cout << answer << '\n';

    return 0;
}
