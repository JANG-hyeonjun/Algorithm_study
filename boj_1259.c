#include<stdio.h>
#include<string.h>
#include<memory.h>

const int MAX = 5;
char arr[MAX];
int length;
bool flag;
void isPalindrome(char string[],int start,int end)
{
    if(start == end) {
        flag = true;
    }
    else if(start + 1 == end )
    {
        if(string[start] == string[end]) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    else
    {
        if(string[start] == string[end])
            isPalindrome(string,start+1,end-1);
        else {
            flag = false;
        }
    }
}

int main()
{
    while(1){
        //(arr,0,sizeof(char) * MAX);
        flag = false;
        scanf("%s",arr);
        if(strcmp(arr,"0")==0) break;
        length = strlen(arr);
        isPalindrome(arr,0,length-1);
        if(flag == true)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
