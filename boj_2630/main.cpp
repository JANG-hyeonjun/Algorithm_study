#include<iostream>

using namespace std;

const int MAX = 130;

int map[MAX][MAX];
int size;
int result;
int white_paper;
int blue_paper;
int final_i,final_j;

void caculate()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> size;

    for(int i =1; i <= size; i++)
    {
        for(int j=1; j <= size; j++)
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
   int stride = size;
    while(size != 1)
    {
        for(int i=1; i < size;)
        {
            for(int j = 1; j < size;)
            {
                cout << i << ", " << j << endl;
                final_i = i + stride-1;
                final_j = j + stride-1;
                cout << final_i << ", " << final_j << endl;
                j = j + stride - 1;
                //caculate(i,j,stride);
            }
            i = i +stride - 1;
        }
        stride /= 2;
    }
    
    //printf("hello\n");

    return 0;
}