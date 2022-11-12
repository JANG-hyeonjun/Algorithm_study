#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100005;
int arr[MAX];
int brother,sister;
queue<int> Queue;

void BFS(int num)
{
    int finish = brother;
    Queue.push(num);

    while(!Queue.empty())
    {
        
        int front = Queue.front();
        Queue.pop();
        if(front == finish) return;
        if(front % 2 == 0)
        {
            if(arr[front / 2] == 0)
            {
                arr[front / 2] = arr[front] + 1;
                Queue.push(front / 2);
            }
            else{
                arr[front / 2] = min(arr[front / 2],arr[front] + 1);
                Queue.push(front / 2);
            }
        }
        if(arr[front + 1] == 0)
        {
            arr[front + 1] = arr[front] + 1;
            Queue.push(front + 1);
        }
        if(arr[front + 1] != 0)
        {
            arr[front + 1] = min(arr[front + 1],arr[front] + 1);
            Queue.push(front + 1);
        }
        if (arr[front -1] == 0)
        {
            arr[front - 1] = arr[front] + 1;
            Queue.push(front - 1);
        }
        if (arr[front - 1] != 0)
        {
            arr[front - 1] = min(arr[front - 1], arr[front] + 1);
            Queue.push(front - 1);
        }
    }
}

int main()
{
    cin >> sister >> brother;
    BFS(brother);
}