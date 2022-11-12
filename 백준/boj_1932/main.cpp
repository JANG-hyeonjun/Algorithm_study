#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 502;
int arr[MAX][MAX];
int dp[MAX][MAX];
int result;
int number;
void dp_function()
{
    for(int i = 1; i < number; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            //dp[i][j] = 9;
            //logic 짜면 됨
            if(j == 0) arr[i][j] += arr[i-1][j];
            else if(j == i) arr[i][j] += arr[i-1][j-1];
            else arr[i][j] += max(arr[i-1][j],arr[i-1][j-1]);
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
    //dp[0][0] = arr[0][0];
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
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
     */
    int Max = -1;
    for(int i = 0; i < number; i++)
    {
        Max = max(Max,arr[number-1][i]);
    }
    cout << Max << '\n';
    return 0;
}
