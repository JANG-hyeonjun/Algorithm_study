#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr;
vector <int> answer;
int number;


int binary(int find)
{

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;

    for(int i =0; i < number; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        answer.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());

    for(int i=0; i < answer.size(); i++)
    {
        cout << lower_bound(arr.begin(),arr.end(),answer[i]) - arr.begin()<<" ";
    }


    return 0;
}
