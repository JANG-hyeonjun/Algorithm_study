#include <iostream>
#include <queue>

using namespace std;
#define MAX 1002

struct box{
    int y;
    int x;
};

int M,N;
int day_MAX = -99999999;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int map[MAX][MAX];
int check[MAX][MAX];
int check_day[MAX][MAX];
queue <box> find_num;

void conclusion()
{
    for(int i = 0 ; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 0) {
                cout << "-1" << endl;
                return;
            }
            if(day_MAX < map[i][j])
                day_MAX = map[i][j];
        }
    }
    cout << day_MAX -1;
}

void print_map()
{
    for(int i =0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
          cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}


void BFS()
{
    box temp = find_num.front();
    check[temp.y][temp.x] = 1;

    while(!find_num.empty())
    {
        box cur = find_num.front();
        int cur_y = cur.y;
        int cur_x = cur.x;
        find_num.pop();
        for(int k=0; k < 4; k++)
        {
            int yy = dy[k] + cur_y;
            int xx = dx[k] + cur_x;
            if(map[yy][xx] == -1) continue;
            if(yy >= 0 && yy < M && xx >=0 && xx < N && check[yy][xx] == 0 && map[yy][xx] != 1)
            {
                check[yy][xx] = 1;
                map[yy][xx] = map[cur_y][cur_x] + 1;
                find_num.push({yy,xx});
            }
        }
    }
}


int main() {

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        for(int j =0; j < N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1) find_num.push({i,j});
        }
    }

    BFS();

    //print_map();
   conclusion();

    return 0;
}
