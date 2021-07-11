#include <iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 1000;
queue<int>Queue;
vector<int>VList;
//list<int>::iterator it;


int main() {
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        Queue.push(i+1);
    }
    while(!Queue.empty())
    {
        for(int i =1; i < k; i++){
            int find_number = Queue.front();
            Queue.pop();
            Queue.push(find_number);
        }
        int List_number = Queue.front();
        Queue.pop();
        VList.push_back(List_number);
    }
    cout << "<";
    for(int i =0; i < VList.size()-1; i++){
        printf("%d, ", VList[i]);
    }
    int final = VList.size()-1;
    printf("%d>\n",VList[final]);

    return 0;
}
