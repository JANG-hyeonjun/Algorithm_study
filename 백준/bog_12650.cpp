#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 100005;
struct box{
    int y;
    int x;
};
box arr[MAX];

bool compare(box a,box b)
{
    if(a.y == b.y)
        return a.x < b.x;

    return a.y < b.y;

}

int main()
{
    int number;
    scanf("%d",&number);

    for(int i =0; i < number; i++)
    {
        scanf("%d %d",&arr[i].y,&arr[i].x);
    }
    sort(arr,arr+number,compare);
    for(int i=0; i < number; i++)
    {
        printf("%d %d\n",arr[i].y,arr[i].x);
    }

    return 0;
}
