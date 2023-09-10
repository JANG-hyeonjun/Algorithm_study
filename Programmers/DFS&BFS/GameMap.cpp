#include<vector>
#include<queue>
#include<iostream>
#include <limits>

using namespace std;

struct Point
{
    int y;
    int x;
    int count;
};

int BFS(std::vector<std::vector<int>>& maps, int& answer)
{
    //BFS로 전체를 탐색하는것은 좋으나
    //각각의 요소에서 Cnt를 가지고 있어야하는데
    
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,1,-1};
    
    bool checkMap[101][101];
    
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            checkMap[i][j] = false;   
        }
    }
    
    checkMap[0][0] = true;
    queue<Point>Queue;
    Queue.push({0,0,1});

    int distance = std::numeric_limits<int>::max();
        
    while(!Queue.empty())
    {
        Point point = Queue.front();
        Queue.pop();
        
        int curY = point.y;
        int curX = point.x;
        
        if(curY == maps.size() - 1 && curX == maps[0].size() - 1)
        {
            if(distance > point.count)
               distance = point.count;
            
        }
        
        for(int k = 0; k < 4; k++)
        {
            int nextY = curY + dy[k];
            int nextX = curX + dx[k];
            
            if(nextY < 0 || nextY >= maps.size() || nextX < 0 || nextX >= maps[0].size())
                continue;
            
            if(!maps[nextY][nextX])
                continue;
                
            if(!checkMap[nextY][nextX])
            {
                Queue.push({nextY, nextX, point.count + 1});
                checkMap[nextY][nextX] = true;    
            }
            
        }
    }
    
    if(distance ==  std::numeric_limits<int>::max())
        return -1;
    else 
        return distance;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = BFS(maps,answer);
    
    return answer;
}