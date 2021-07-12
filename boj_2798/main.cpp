#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100;
int value_MAX =  -1;
int n,m;
int arr[MAX];
int result;
int final;
int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr,arr+n);
    for(int i =0; i < n; i++)
    {
        for(int j = 1+i; j < n; j++)
        {
            for(int k =1+j; k < n; k++)
            {
                result = 0;
                result = arr[i] + arr[j] + arr[k];
                //cout << result << endl;
                //cout << "!!!!!" << endl;
                //cout << m << endl;
                if(result <= m)
                    final = max(result,final);
                else
                    continue;


            }
            if(result <= m)
                final = max(result,final);
            else
                continue;
        }
        if(result <= m)
            final = max(result,final);
        else
            continue;
    }
    cout << final << endl;
    return 0;
}
