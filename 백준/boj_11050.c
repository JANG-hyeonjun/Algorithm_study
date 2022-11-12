#include<stdio.h>

const int MAX = 100;
int arr[MAX][MAX];
int n,k;
int answer;
int min(int a,int b)
{
    if (a >= b) return b;
    else return a;
}
int bin(int n, int k)
{
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j <= min(i,k); j++)
        {
            if (j==0 || j==i) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    return arr[n][k];
}

int main()
{
    scanf("%d %d",&n,&k);

    answer = bin(n,k);
   /* for(int i = 0; i < 6; i++)
    {
        for(int j=0; j < 5; j++)
        {
            printf("%d",arr[i][j]);

        }
        printf("\n");
    }
    */
    printf("%d\n",arr[n-1][k-1] + arr[n-1][k]);

    return 0;
}
