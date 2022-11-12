#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100005;
int arr[MAX];
int brother,sister;
queue <int> Queue;
int check[MAX];

void BFS(int num)
{
    int finish = sister;
    Queue.push(num);
    arr[num] = 1;
    check[num] = 1;
    while(!Queue.empty())
    {

        int front = Queue.front();
        Queue.pop();
        if(front == finish) return;
        if(front)
        if(front % 2 == 0 && check[front / 2] == 0)
        {
            if(arr[front / 2] == 0)
            {
                arr[front / 2] = arr[front] + 1;
                Queue.push(front / 2);
                check[front / 2] = 1;
            }
            else{
                arr[front / 2] = min(arr[front / 2],arr[front] + 1);
                Queue.push(front / 2);
                check[front / 2] = 1;
            }
        }
        if(arr[front + 1] == 0 && check[front + 1] == 0 && front + 1 <= 1000001)
        {
            arr[front + 1] = arr[front] + 1;
            Queue.push(front + 1);
            check[front + 1] = 1;
        }
        else if(arr[front + 1] != 0 && check[front + 1] == 0 && front + 1 <= 1000001)
        {
            arr[front + 1] = min(arr[front + 1],arr[front] + 1);
            Queue.push(front + 1);
            check[front + 1] = 1;
        }
        if (arr[front -1] == 0 && check[front -1] == 0 && front - 1 >= 0)
        {
            arr[front - 1] = arr[front] + 1;
            Queue.push(front - 1);
            check[front - 1] = 1;
        }
        else if (arr[front - 1] != 0 && check[front -1] == 0 && front - 1 >= 0)
        {
            arr[front - 1] = min(arr[front - 1], arr[front] + 1);
            Queue.push(front - 1);
            check[front - 1] = 1;
        }
    }
}

int main()
{
    cin >> sister >> brother;
    BFS(brother);
    cout << arr[sister] - 1;
}