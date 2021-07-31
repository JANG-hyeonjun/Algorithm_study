#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//priority_queue<int,vector<int>> q;
priority_queue<int,vector<int>,greater<int>> q;
int number;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;
    for(int i =0; i < number; i++)
    {
        int command;
        cin >> command;
        if(command != 0)
        {
            q.push(command);
        }
        else{
           if(q.size() == 0) cout << "0" << '\n';
           else {
               cout << q.top() << '\n';
               q.pop();
           }
        }
    }


    return 0;
}
