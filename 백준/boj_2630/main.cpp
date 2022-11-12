#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 129;

int map[MAX][MAX];
int num_size;
int white_paper;
int blue_paper;

void caculate(int x,int y,int n)
{
    int result = 0;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            result += map[i][j];
        }
    }
    if(result == n * n)
    {
        blue_paper++;
    }
    else if(result == 0)
    {
        white_paper++;
    }
    else{
        caculate(x,y, n /2);
        caculate(x, y + n /2 ,n / 2);
        caculate(x + n /2, y, n / 2);
        caculate(x + n /2, y + n /2, n / 2);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num_size;
    memset(map, 0, sizeof(map));
    for(int i =0; i < num_size; i++)
    {
        for(int j=0; j < num_size; j++)
            {
                cin >> map[i][j];
            }
    }
    // 설계 순서
    /*
     size 를 기준으로 범위를  stride 처럼준다.
     줄때 왼쪽 상단과 우측 하단을 준다. 
     그 범위 만큼 합을 계산해주는 함수를 짠다. 
     좌표를 주는 것을 계산해야한다. 
    */
   caculate(0,0,num_size);
    
    cout << white_paper << endl << blue_paper << endl;
    return 0;
}