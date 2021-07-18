#include <iostream>
#include <queue>

using namespace std;

queue <int> Queue;
int Qsize;

int main() {
    cin >> Qsize;

    for(int i=0; i < Qsize; i++)
    {
        Queue.push(i+1);
    }
    while(Queue.size() != 1) {
        Queue.pop();
        int push_number = Queue.front();
        Queue.pop();
        Queue.push(push_number);
    }
    cout << Queue.front() << endl;
    return 0;
}
