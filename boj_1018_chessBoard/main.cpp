#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define value_MAX 9999;

const int MAX = 53;
char map[MAX][MAX];
char board[8][8];

int n,m;
int result = value_MAX;
void crop_board(int y, int x)
{
  for(int i = 0; i < 8; i++)
  {
      for(int j =0; j < 8; j++)
      {
          board[i][j] = map[i+y][j+x];
      }
  }
}
int solve()
{
    int change_black =0;
    int change_white =0;
    for(int i =0; i < 8; i++)
    {
        for(int j =0; j < 8; j++)
        {
            //왼쪽 상단 검은색
            if((i+j) % 2== 0 && board[i][j] == 'W') change_white++;
            if((i+j) % 2== 1 && board[i][j] == 'B') change_white++;
            //왼쪽 상단 흰색
            if((i+j) % 2== 0 && board[i][j] == 'B') change_black++;
            if((i+j) % 2== 1 && board[i][j] == 'W') change_black++;


        }
    }
    return min(change_white,change_black);
}

int main() {
    cin >> n >> m;

    for(int i=0; i < n; i++)
    {
        for(int j =0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    //board판 초기화
    for(int i=0; i <= n -8; i++)
    {
        for(int j=0; j <= m - 8; j++)
        {
            crop_board(i,j);
            result = min(result,solve());
        }
    }
    cout << result;
    return 0;
}
