#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
//std::unordered_map<int,string> map;
vector<string> v1;
vector<pair<string,int>> v2;

int N,M;
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> N >> M;
    for(int i =1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        v1.push_back(temp);
        v2.push_back({temp,i});
    }
    sort(v2.begin(),v2.end());

    for(int i = 1; i <= M; i++)
    {
        string temp2;
        cin >> temp2;
        if(isNumber(temp2) == 1)
        {
            int result = stoi(temp2);
            cout << v1[result-1] << '\n';
        }
        else{
            int start,end;
            start = 0;
            end = N - 1;
            while(start <= end){
                int mid = (start + end) / 2;

                if(v2[mid].first == temp2){
                    cout << v2[mid].second << '\n';
                    break;
                }
                else if(v2[mid].first < temp2)
                {
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
    }



    return 0;
}
