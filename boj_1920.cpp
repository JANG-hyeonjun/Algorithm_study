#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 100005;
int arr[MAX];
int cnt;
int flag;
int find_number_cnt;

void binary(int start,int end,int find)
{
    start = -1;
    int mid = (start + end) / 2;
    while(start + 1 < end )
    {
        mid = (start + end)/2;
        if(arr[mid] ==  find) {
            flag = true;
            return;
        }
        else if(arr[mid] < find){
            start = mid;
        }
        else{ //arr[mid] > find
            end = mid;
        }
    }
    flag = false;
    return;
}

int main()
{
    scanf("%d",&cnt);

    for(int i =0; i < cnt; i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+cnt);
    printf("\n");
    scanf("%d",&find_number_cnt);
    for(int i = 0; i < find_number_cnt; i++)
    {
        int find_number;
        scanf("%d",&find_number);
        flag = false;
        binary(0,cnt,find_number);
        if(flag == true) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
