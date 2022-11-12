#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

int num_cnt;
int final_sum;
stack <int> Stack;
int temp;
int main()
{
    scanf("%d",&num_cnt);
    for(int i =0; i < num_cnt; i++)
    {
        scanf("%d",&temp);
        if(temp == 0)
        {
            if(Stack.empty()) continue;
            Stack.pop();
        }
        else Stack.push(temp);
    }
    int size = Stack.size();
    for(int i = 0; i < size; i++)
    {
        final_sum += Stack.top();
        Stack.pop();
    }
    printf("%d\n", final_sum);
    return 0;
}
