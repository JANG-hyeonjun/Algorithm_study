#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX = 500005;

class Find_person{
private:
    vector<string>listen_arr;
    //vector<string> saw_arr;
    vector<string> answer;
public:
    int n,m;
    void make_answer();
    void Init_person(int n,int m);
};

void Find_person::Init_person(int n,int m) {
    string temp;
    for(int i =0; i < n + m; i++)
    {
      cin >>temp;
      listen_arr.push_back(temp);
    }
    sort(listen_arr.begin(),listen_arr.end());
}

void Find_person::make_answer() {
    for(int i = 1; i < n +m; i++) {
        if(listen_arr[i].compare(listen_arr[i-1]) == 0)
            answer.push_back(listen_arr[i]);
    }
    sort(answer.begin(),answer.end());
    cout << answer.size() << endl;
    for(int i=0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    Find_person f1;
    cin >> f1.n >> f1.m;
    f1.Init_person(f1.n,f1.m);
    f1.make_answer();
    return 0;
}
