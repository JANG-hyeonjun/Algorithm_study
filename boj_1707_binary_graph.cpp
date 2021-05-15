#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 20001;
vector <int> mygraph[MAX];
queue <int> Queue;
int color[20001];
bool check[20001];
bool flag = false;
int answer[5];
int vertex,edge;
void BFS(int start)
{
    Queue.push(start);
    check[start] = true;
    color[start] = 1;
    while(!Queue.empty())
    {
        int cur = Queue.front();
        Queue.pop();
        for(int i =0; i < mygraph[cur].size(); i++)
        {
            int next = mygraph[cur][i];
            if(check[next] != 0 && color[next] == color[cur])
            {
                flag = true;
                break;
            }
            if(check[next] == 0)
            {
                if(color[cur] == 1) color[next] = 2;
                else color[next] = 1;
                Queue.push(next);
                check[next] = true;
            }
        }
    }
}
int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int i =0; i < test_case; i++)
    {
        scanf("%d %d",&vertex,&edge);
        for(int j =0; j < edge; j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            mygraph[a].push_back(b);
            mygraph[b].push_back(a);
        }
       // printf("들어가기전%d\n",flag);
        flag = false;
       for(int k = 1; k <= vertex; k++)
        {
            if(check[k] == 0)
            BFS(k);
        }
        //printf("나온후%d\n",flag);
        if(flag == true) answer[i] = 0;
        else answer[i] = 1;

        for(int i =0; i <= vertex; i++) mygraph[i].clear();
        memset(color,0,sizeof(color));
        memset(check,0,sizeof(check));
    }
    for(int i = 0; i < test_case; i++)
        if(!answer[i]) printf("NO\n");
        else printf("YES\n");

    return 0;
}}
