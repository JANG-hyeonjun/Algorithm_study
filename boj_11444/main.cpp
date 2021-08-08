#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;
typedef vector<vector< ll >> matrix;


matrix operator * (const matrix &a, const matrix &b)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for(ll i =0; i < size; i++)
    {
        for(ll j = 0; j < size; j++)
        {
            for(ll k =0; k < size; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000000007;
        }
    }
    return res;
}



matrix power(matrix a,ll n)
{
    ll size = a.size();
    //cout << a.size() << "\n";
    matrix res(size,vector<ll>(size));
    //초기 컨디션 설정 해주고 홀수를 뺴주기 위한 방법이다.
    for(ll i =0; i < size; i++)
    {
        res[i][i] = 1;
    }

    while(n > 0){
        if(n % 2 == 1){
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    matrix a = {{1,1},{1,0}};
    matrix res = (power(a,n-1));
    cout << (res[1][0] + res[1][1]) % 1000000007;
    return 0;
}
