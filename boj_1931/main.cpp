#include <iostream>
#include <algorithm>

using namespace std;


const int MAX = 100005;

struct meeting{
    int start;
    int end;
};

meeting arr[MAX];
int number;
int answer;

bool compare(meeting m1,meeting m2)
{
    if(m1.end == m2.end)
        return m1.start < m2.start;
    else
        return m1.end < m2.end;
}
void find_answer()
{
    int end = 0;
    end = arr[0].end;
    answer++;
    for(int i = 1; i < number; i++)
    {
        if(arr[i].start >= end)
        {
            end = arr[i].end;
            answer++;
        }
        else continue;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;
    for(int i =0; i < number; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }

    sort(arr,arr+number,compare);
/*
    for(int i =0; i < number; i++)
    {
        cout << arr[i].start <<" "<< arr[i].end << '\n';
    }
    */
    find_answer();
    return 0;
}
