#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct box{
    int y;
    int x;
};

const int MAX = 52;
int map[MAX][MAX];
int Test_case;
int check[MAX][MAX];
int n,m,cabbage;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int need_insect;
queue <box> Queue;

void BFS(int y,int x)
{
    Queue.push({y,x});
    check[y][x] = 1;

    while(!Queue.empty())
    {
        box point = Queue.front();
        Queue.pop();
        int cur_y = point.y;
        int cur_x = point.x;
        for(int k =0; k < 4; k++)
        {
            int yy = cur_y + dy[k];
            int xx = cur_x + dx[k];
            if(yy >= 0 && yy < n && xx >= 0 && xx < m)
            {
                if(check[yy][xx] == 0 && map[yy][xx] == 1)
                {
                    Queue.push({yy,xx});
                    check[yy][xx] = 1;
                    map[yy][xx] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> Test_case;
    for(int T = 0; T < Test_case; T++) {
        need_insect = 0;
        memset(map,0,sizeof(map));
        memset(check,0, sizeof(check));
        cin >> n >> m >> cabbage;
        for (int i = 0; i < cabbage; i++) {
            int y, x;
            cin >> y >> x;
            map[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && check[i][j] == 0) {
                    BFS(i,j);
                    need_insect++;
                }
            }
        }
        cout << need_insect;
        cout << endl;
    }
    return 0;
}
