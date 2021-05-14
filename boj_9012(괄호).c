#include<stdio.h>
#include<string.h>
#include<memory.h>
const int MAX = 100;
char arr[MAX];
int test_case;
int length;
int count;
int flag;
int main()
{
    scanf("%d",&test_case);
    for(int i =0; i < test_case; i++)
    {
        memset(arr,0,sizeof(char) * MAX);
        count = 0;
        flag = 0;
        scanf("%s",arr);
        length = strlen(arr);
       for(int j = 0 ; j < length; j++)
       {
           if(count < 0){
               printf("NO\n");
               flag = 1;
               break;
           }
           if(arr[j] == '(') count++;
           else count--;
       }
       if(flag == 1) continue;
       if(count == 0) printf("YES\n");
       else printf("NO\n");
    }
    return 0;
}
