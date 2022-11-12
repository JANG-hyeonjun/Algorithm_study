#include<stdio.h>
#include<algorithm>

using namespace std;

int input,maxVal;
int *arr = new int[3];

int main()
{
    while(1)
    {
        for(int i=0; i < 3; i++) {
            scanf("%d", &input);
            arr[i] = input;
        }
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        sort(arr,arr+3);
        if((arr[0] * arr[0]) + (arr[1] * arr[1]) == arr[2] * arr[2])
            printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
