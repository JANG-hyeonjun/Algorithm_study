#include<stdio.h>

int main()
{
    int h;
    scanf("%d",&h);
    for(int i =0;i < h; i++)
    {
        for(int j =0; j <= i; j++)
            printf("*");
        
        printf("\n");
    }
   
    
    
    return 0;
}
