#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 100005;
int arr[MAX];
int cnt;
int flag;
int find_number_cnt;
int find_number;

void binary(int start,int end,int find)
{
    start = -1;
    int mid = 0;
    while(start + 1 < end )
    {
        mid = (start + end)/2;
        if(arr[mid] ==  find) {
            flag = true;
            return;
        }
        else if(arr[mid] < find)start = mid;
        else end = mid;
    }
    return;
}

int main()
{
    scanf("%d",&cnt);

    for(int i =0; i < cnt; i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+cnt);
    scanf("%d",&find_number_cnt);

    for(int i = 0; i < find_number_cnt; i++)
    {
        scanf("%d",&find_number);
        flag = false;
        binary(0,cnt,find_number);
        if(flag == true) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
