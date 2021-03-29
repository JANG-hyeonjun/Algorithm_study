#include<cstdio>
#include<vector>
#include<queue>

const int MAX = 105;
int cnt;
using namespace std;

vector <int> mygraph[MAX];
queue <int> Queue;
bool check[MAX];
void BFS()
{
    Queue.push(1);
    check[1] = true;
    while(!Queue.empty())
    {
        int cur = Queue.front();
        Queue.pop();
        for(int i = 0; i < mygraph[cur].size(); i++)
        {
            int next = mygraph[cur][i];
            if(check[next] == false)
            {
                cnt++;
                check[next] = true;
                Queue.push(next);
            }
        }
    }
}
int main()
{
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    
    for(int i=0; i < edge; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        mygraph[a].push_back(b);
        mygraph[b].push_back(a);
    }
    BFS();
    printf("%d\n",cnt);
    return 0;
}
