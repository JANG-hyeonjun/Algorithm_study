#include <iostream>

using namespace std;

const int MAX = 15;
int N;
int Table[MAX];
int total;

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        if(Table[i] == Table[level] || abs(Table[level] - Table[i]) == level - i)
            return false;
    }
    return true;
}

void N_queen(int level)
{
    if (level == N)
        total++;
    else {
        for (int i = 0; i < N; i++)
        {
            Table[level] = i;
            if (check(level))
            {
                N_queen(level + 1);
            }
        }
    }
}

int main()
{
    cin >> N;
    N_queen(0);
    cout << total << "\n";
}