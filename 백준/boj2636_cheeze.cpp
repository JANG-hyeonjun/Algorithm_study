#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct box{
    int y;
    int x;
};

const int MAX = 105;
int map[MAX][MAX];
bool check[MAX][MAX];
int n,m;
int Time;
queue <box> Queue;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int sum;
int before;

bool confirm(int yy,int xx)
{
   if(yy >= 0 && yy <= n && xx >= 0 && xx <= m) return true;
   else return false;
}

void get_cheeze()
{
    Queue.push({1,1});
    check[1][1] = true;
    while(!Queue.empty())
    {
        box front = Queue.front();
        int curY = front.y;
        int curX = front.x;
        Queue.pop();
        for(int k =0; k < 4; k++)
        {
            int yy = curY + dy[k];
            int xx = curX + dx[k];
            if(!check[yy][xx] && yy >= 0 && yy <= n && xx >= 0 && xx <= m && map[yy][xx] == 0)
            {
                Queue.push({yy,xx});
                check[yy][xx] = true;
            }
            else if(map[yy][xx] == 1)
            {
                check[yy][xx] = true;
                map[yy][xx] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i= 1; i <= n; i++)
    {
        for(int j =1; j<= m; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    while(1)
    {
        sum = 0;
        memset(check,0,sizeof(check));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j<= m; j++)
            {
                if(map[i][j] == 1)
                    sum += 1;
            }
        }
       // printf("%d\n",sum);
       if(sum ==0) break;
       else if(sum != 0) before = sum;
       get_cheeze();
/*
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= m; j++)
         {
             printf("%d " , map[i][j]);
         }
         printf("\n");
     }
     printf("\n");
     */
       Time++;
    }
    printf("%d\n%d", Time, before);
    return 0;
}




