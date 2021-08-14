#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1005;
int arr[MAX];
int number;
int memory;
int idx;
int answer[MAX];
int temp_answer = 1;
int min_sub = 99999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;
    for(int i =0; i < number; i++)
    {
        cin >> arr[i];
    }


    for(int i = 0; i < number; i++)
    {
        temp_answer = 1;
        memory = arr[i];
        for(int j = i+1; j < number; j++)
        {
           if(arr[j] > memory &&  arr[j] > arr[i])
           {
               temp_answer++;
               memory = arr[j];
           }
           else if(arr[j] < memory && arr[j] > arr[i])
           {
               answer[i] = max(answer[i],temp_answer);
               temp_answer = answer[i];
               memory= arr[j];
           }

           else continue;
        }
        answer[i] = max(answer[i],temp_answer);
    }

    /*
        for(int i =0; i < number; i++)
            cout << answer[i] << " ";
        cout << '\n';
        */

    sort(answer,answer + number);

    cout << answer[number-1];

    return 0;
}
