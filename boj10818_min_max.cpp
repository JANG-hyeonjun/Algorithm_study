#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 1000005;
int arr[MAX];
int main()
{
    int n;
    scanf("%d",&n);

    for(int i = 0; i <n; i++)
    {
        int temp;
        scanf("%d",&temp);
        arr[i] = temp;
    }
    sort(arr,arr+n);
    printf("%d %d\n",arr[0],arr[n-1]);
    return 0;
}
