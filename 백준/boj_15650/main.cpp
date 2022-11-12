#include <iostream>

using namespace std;

int N,M;


void printArray(int arr[], int count)    // 배열의 포인터와 요소의 개수를 받음
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void combination(int depth,int next,int cArr[])
{
    if(depth == M){
        printArray(cArr,M);
        return;
    }
    for(int i = next; i <= N; i++)
    {
        cArr[depth] = i;
        combination(depth + 1, i+ 1,cArr);
    }
}

int main() {
    cin >> N >> M;
    int cArr[M];
    combination(0,1,cArr);
    return 0;
}
