#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 110;

int N,K;
int W,V;
int Weight[MAX];
int Value[MAX];
int dp[MAX][100010];


void solution()
{
    /*
     - i번째 보석이 배낭의 무게 한도보다 무거우면 넣을 수 없으므로 i번째 보석을 뺀 i-1개의 보석들을 가지고 구한 전 단계의 최적값을 그대로 가져온다

     - 그렇지 않은 경우, i번째 보석을 위해 i번째 보석만큼의 무게를 비웠을 때의 최적값에 i번째 보석의 가격을 더한 값 or i-1개의 보석들을 가지고 구한 전 단계의 최적값 중 큰 것을 선택한다
     */
    for(int i =0; i < N + 1; i++) {
        for (int j = 0; j < K + 1; j++){
            if(i ==0 || j == 0) dp[i][j] = 0;
            else if(Weight[i-1] <= j){
                dp[i][j] = max(Value[i-1] + dp[i-1][j-Weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    for (int i = 0; i < N; i++){
        cin >> W >> V;
        Weight[i] = W;
        Value[i] = V;
    }

    solution();
    /*
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */
    cout << dp[N][K];
    return 0;
}
