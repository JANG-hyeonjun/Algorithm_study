#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<queue>
using namespace std;
struct box
{
	int y;
	int x;
	int d;
};
const int MAX = 100;
//각각의 맵에 각각의 방향의 명령횟수에 찍혀있어야한다. 
queue <box> Queue;
int n, m;
int y, x, dir;
int cnt = 0; //명령횟수를 담당한다.
int final_y, final_x, final_dir;
int dy[5] = { 0,0,0,1,-1 };
int dx[5] = { 0,1,-1,0,0 };
int count_map[5][110][110];
bool flag = false;
bool ispossible(int yy, int xx)
{
	if (yy >= 1 && yy <= n && xx >= 1 && xx <= m &&count_map[0][yy][xx] != 1)
		return false;
	else
	{
		flag = true;
		return true;
	}
}
void BFS(int y, int x, int dir)
{
	Queue.push({ y,x,dir });
	count_map[dir][y][x] = 1;
	while (!Queue.empty())
	{
		box cur = Queue.front();
		int cur_y = cur.y; // 4
		int cur_x = cur.x; // 2
		int cur_d = cur.d; // 3
		Queue.pop();
		if (cur_d == 1 || cur_d == 2) 
		{
			if (!count_map[3][cur_y][cur_x]) {
				count_map[3][cur_y][cur_x] = count_map[cur_d][cur_y][cur_x] + 1;
				Queue.push({cur_y,cur_x,3 });
			}
			if (!count_map[4][cur_y][cur_x]) {
				count_map[4][cur_y][cur_x] = count_map[cur_d][cur_y][cur_x] + 1;
				Queue.push({ cur_y,cur_x,4});
			}
		}
		if (cur_d == 3 || cur_d == 4)
		{
			if (!count_map[1][cur_y][cur_x]) {
				count_map[1][cur_y][cur_x] = count_map[cur_d][cur_y][cur_x] + 1;
				Queue.push({ cur_y,cur_x,1});
			}
			if (!count_map[2][cur_y][cur_x]) {
				count_map[2][cur_y][cur_x] = count_map[cur_d][cur_y][cur_x] + 1;
				Queue.push({ cur_y,cur_x,2});
			}
		}
		//직진을 넣는다 .
		flag = false;
		for (int i = 1; i <= 3; i++)
		{
			
			int yy = cur_y + dy[cur_d] * i;
			int xx = cur_x + dx[cur_d] * i;

			if (ispossible(yy, xx)) continue;

			if (!count_map[cur_d][yy][xx] && flag == false)
			{
				count_map[cur_d][yy][xx] = count_map[cur_d][cur_y][cur_x] + 1;
				Queue.push({ yy,xx,cur_d });
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &count_map[0][i][j]);
			//for (int k = 1; k <= 4; k++)
				//count_map[k][i][j] = count_map[0][i][j];
		}
	}
	
		scanf("%d %d %d", &y, &x, &dir);
		scanf("%d %d %d", &final_y, &final_x, &final_dir); //일단 저장해 둔다.
	
	BFS(y, x, dir); //처음 지점 부터 각각의 맵에 대해 모든 경우의 수를 집어 넣는다 .
	//printf("______\n");
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", count_map[1][i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", count_map[final_dir][final_y][final_x]-1);

	return 0;
}
