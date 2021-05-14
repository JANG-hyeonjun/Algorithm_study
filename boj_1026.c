#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

struct memory{
    int value;
    int index;
};

int sum;
const int MAX = 100;
int arr[MAX]; //원본은 여기에 있다.

int final_score;
int A[MAX];
int new_A[MAX];
memory B[MAX];
int num;
bool compare(memory a,memory b)
{
    return a.value > b.value;
}

int main()
{
    scanf("%d",&num);

    for(int j = 0; j < num; j++)
    {
        scanf("%d",&A[j]);
    }
    for(int k=0; k < num; k++)
    {
        scanf("%d",&B[k].value);
        B[k].index = k;
        arr[k] = B[k].value; //원본을 저장한다.
    }
    sort(A,A+num); //0 1 1 1 6
    sort(B,B+num,compare);

    /*
    for(int i =0 ; i < num; i++)
    {
        printf("%d:%d\n",B[i].index,B[i].value);
    }*/

    for(int i=0; i < num; i++)
    {
        int temp_idx = B[i].index;
        new_A[temp_idx] = A[i];
    }

    for(int i =0; i < num; i++)
    {
       sum += new_A[i]*arr[i];
    }
    printf("%d\n",sum);
    return 0;
}

