#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int n,m;
vector <int> myGraph[MAX];
queue<int> Queue;
int sequential_check[MAX];
int check_number;
void BFS(int num)
{
    sequential_check[num] = 1;
    Queue.push(num);
    while(!Queue.empty())
    {
        int front = Queue.front();
        Queue.pop();
        for(int i =0; i < myGraph[front].size(); i++)
        {
            int next = myGraph[front][i];
            if(sequential_check[next] == 0)
            {
                sequential_check[next] = 1;
                Queue.push(next);
            }
        }
    }
}


int main() {

    cin >> n >> m;
    for(int i =1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    for(int i =1; i <= n; i++) {
        if(sequential_check[i] == 0) {
            check_number++;
            BFS(i);
        }
    }

    cout << check_number << endl;
    return 0;
}
