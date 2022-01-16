#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100005;

int arr[2][MAX];
int dp[2][MAX + 1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 0;
    cin >> test_case;
    for(int t =0; t < test_case; t++)
    {
        int size = 0;
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        cin >> size;
        for(int i =0; i < 2; i++)
        {
            for(int j = 0; j < size; j++)
            {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = arr[0][0];
        dp[1][1] = arr[1][0];
            for(int j = 2; j <= size; j++)
            {
                dp[0][j] = max(dp[1][j-1],dp[1][j-2]) + arr[0][j-1];
                dp[1][j] = max(dp[0][j-1],dp[0][j-2]) + arr[1][j-1];
            }

    cout << max(dp[0][size],dp[1][size]) << '\n';
    }

    return 0;
}