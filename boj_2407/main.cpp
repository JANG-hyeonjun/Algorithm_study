#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
const int MAX = 102;
string arr[MAX][MAX];


string bigNumAdd(string num1,string num2)
{

    long long int sum = 0;
    string result;

    while(!num1.empty() || !num2.empty() || sum)
    {
        if(!num1.empty()){
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if(!num2.empty()){
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(),result.end());
    return result;
}

void contain()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j =0; j < i; j++) {
            if (j == 0)
                arr[i][j] = "1";
        }
    }


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 0)
                arr[i][j] = "1";
            if(j == 1)
                arr[i][j] = to_string(i);
            else if(j == i)
                arr[i][j] = "1";
            else arr[i][j] = bigNumAdd(arr[i-1][j],arr[i-1][j-1]);
        }
    }
}

int main() {

    cin >> n >> m;

    contain();

    /*
    for(int i =0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
*/
    cout << arr[n][m] << '\n';

    return 0;
}
