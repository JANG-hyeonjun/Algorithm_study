#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N,M;
vector<int> myGraph[50005];
bool check[50005];
int color[50005];
bool flag= false;
queue <int> Queue;

void BFS(int find)
{
    Queue.push(find);
    color[find] = 1;
    check[find] = true;
    color[1] = 1;
    while(!Queue.empty())
    {
        int cur = Queue.front();
        Queue.pop();

        for(int i =0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i];

            if(color[next] != 0 && color[cur] == color[next])
            {
                flag = true;
                break;
            }
            if(check[next] == 0)
            {
                if(color[cur]==1) color[next] = 2;
                else color[next] = 1;

                Queue.push(next);
                check[next] = true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int j=0; j <M; j++)
    {
        int a,b;
        cin >> a >> b;
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
    {
       if(check[i] == 0)
        {
           BFS(i);
        }
       if(flag == true)
            break;
    }
    if(flag == true)
        cout << 0;
    else{
        long long color1 = 0;
        long long color2 = 0;
        for(int i =1; i <= N; i++)
        {
            if(color[i] % 2 == 0)
                color1++;
            else
                color2++;
        }
        long long result = color1 * color2 * 2;
        cout << result;
    }
    return 0;
}
