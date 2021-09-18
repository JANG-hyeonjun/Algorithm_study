#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3000;
int arr[MAX][MAX];
int dp[MAX][MAX];
int result;
int number;
void dp_function()
{
    for(int i = 1; i < number; i++)
    {
        for(int j = 0; j < i * 2; j++)
        {
            dp[i][j] = 9;
            //logic 짜면 됨 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;

    for(int i =0; i < number; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int temp;
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    /*
    cout << '\n';
    for(int i =0; i < number + 2; i++)
    {
        for(int j =0; j < number + 2; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }*/
    // 여기서 부터 함수
    dp_function();
    /*
    cout << '\n';
    for(int i =0; i < number + 5; i++)
    {
        for(int j =0; j < number + 5; j++)
        {
            cout << dp[i][j];
        }
        cout << '\n';
    }
     */
    return 0;
}
