#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
bool check[10];

void printArray(int arr[], int count)    // 배열의 포인터와 요소의 개수를 받음
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void permutation(int depth,int cArr[],int NumArr[])
{
    if(depth == M){
        printArray(cArr,M);
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(!check[i]){
            check[i] = true;
            cArr[depth] = NumArr[i];
            permutation(depth + 1,cArr,NumArr);
            check[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    int cArr[M];
    int NumArr[N];
    for(int i =0; i < N; i++)
    {
        int number;
        cin >> number;
        NumArr[i] = number;
    }
    sort(NumArr,NumArr+N);
    permutation(0,cArr,NumArr);
    return 0;
}
