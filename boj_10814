#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAX = 15000;

queue <int> arr;
char cmd[10];


int main() {
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++){
        scanf("%s",cmd);

        if(strcmp(cmd,"push") == 0)
        {
            int temp;
            scanf("%d",&temp);
            arr.push(temp);
        }
        if(strcmp(cmd,"front") == 0)
        {
            if(arr.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n",arr.front());
        }
        if(strcmp(cmd,"back") == 0)
        {
            if(arr.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n",arr.back());
        }
        if(strcmp(cmd,"size") == 0)
        {
           int temp = arr.size();
            printf("%d\n",temp);
        }
        if(strcmp(cmd,"empty") == 0)
        {
            if(arr.empty())
                printf("1\n");
            else printf("0\n");
        }
        if(strcmp(cmd,"pop") == 0)
        {
            if(arr.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n",arr.front());
            arr.pop();
        }
    }
    return 0;
}
