#include<stdio.h>
const int MAX = 1000001;
int arr[MAX];

void check(int number)
{
    int cnt = 2;
    while(number * cnt < MAX)
    {
        arr[number*cnt] = 1;
        cnt++;
    }
}
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);

    for(int i = 2; i <=num2; i++)
    {
        check(i);
    }

    for(int i =num1; i <= num2; i++)
    {
        if(i == 1) continue;
        if(arr[i]== 0)
            printf("%d\n",i);
    }
    return 0;
}
