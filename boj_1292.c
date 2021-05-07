#include<stdio.h>
int arr[1001];
int main()
{
    int input_num = 1;
    int idx = 1;
    int final_idx = 1;
    while(idx <= 1001)
    {
        for(int i = idx; i <= final_idx; i++)
        {
            if(i >= 1001) break;
            arr[i] = input_num;
        }
        idx = final_idx + 1;
        input_num++;
        final_idx = final_idx + input_num;
    }
    int a,b,sum = 0;
    scanf("%d %d",&a,&b);
    for(int i = a; i <= b; i++)
        sum += arr[i];
    printf("%d\n",sum);
    return 0;
}
