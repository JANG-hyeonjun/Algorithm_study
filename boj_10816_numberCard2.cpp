#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 500005;
int arr[MAX];
int answer[MAX];
int number,find_number;
int temp;

int getStart_Point(int value)
{
    //start는 항상 value보다 작은값
    //end는 항상 value보다 크거나 같은값
    int start,end;
    if(arr[0] > value) return -1;
    else{
        if(arr[0] < value) start = 0;
        else return 0;
    }
    if(arr[number-1] < value) return -1;
    else end = number-1;
    while(start + 1 < end)
    {
        int mid = (start+ end) / 2;
        if(arr[mid] < value) start = mid;
        else end = mid;
    }
    if(arr[start + 1] == value) return end;
    else return -1;
}
int getEnd_Point(int value)
{
    //start는 항상 value 보다 작거나 같은값
    //end는 항상 value보다 큰값
    int start,end;
    if(arr[0] > value) return -1;
    else start = 0;

    if(arr[number-1] < value) return -1;
    else{
        if(arr[number-1] > value) end = number-1;
        else return number-1;
    }
    while(start + 1 < end)
    {
        int mid = (start+ end) / 2;
        if(arr[mid] > value) end = mid;
        else start = mid;
    }
    if(arr[start] == value) return start;
    else return -1;
}

int main()
{
    scanf("%d",&number);
    for(int i =0; i < number; i++)
    {
        scanf("%d",&temp);
        arr[i] = temp;
    }
    sort(arr,arr+number);
    //for(int i =0; i < number; i++)
      //  printf("%d ",arr[i]);
    //printf("\n");
    scanf("%d",&find_number);
    for(int i =0; i < find_number; i++)
    {
        scanf("%d",&temp);
        int front = getStart_Point(temp);
        int rear = getEnd_Point(temp);
        if(front == -1) {
           answer[i] = 0;
            continue;
        }
       answer[i] =  rear - front + 1;
    }
    for(int i =0; i < find_number; i++)
        printf("%d ",answer[i]);

    return 0;
}
