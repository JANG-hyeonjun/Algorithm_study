#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>> pq;

class doubleEndedQueue{
public:
    set <int> s;
    int size();
    string is_empty();
    void insert(int x);
    int get_start();
    int get_end();
    void delete_start();
    void delete_end();
};

int doubleEndedQueue::size() {
    return s.size();
}
string doubleEndedQueue::is_empty() {
    return s.size() == 0 ? "True" : "False";
}
void doubleEndedQueue::insert(int x) {
    s.insert(x);
}
int doubleEndedQueue::get_start() {
    return * (s.begin());
}
int doubleEndedQueue::get_end() {
    return * (s.end());
}
void doubleEndedQueue::delete_start() {
    if(s.size() == 0){
        return;
    }
    s.erase(s.begin());
}
void doubleEndedQueue::delete_end() {
    if(s.size() == 0){
        return;
    }
    auto end = s.end();
    end--;
    s.erase(end);
}

int main() {

    doubleEndedQueue dq;
    int Test_case;
    cin >> Test_case;
    for(int i =0; i < Test_case; i++)
    {
        int command;
        cin >> command;
        for(int j =0; j < command; j++)
        {
            string temp;
            cin >> temp;
            if(temp == "I")
            {
                int temp;
                cin >> temp;
                dq.insert(temp);
            }
            else if(temp == "D")
            {
                int temp;
                cin >> temp;
                if(temp == 1)
                {
                    dq.delete_start();
                }
                else{
                    dq.delete_end();
                }
            }
        }
        if(dq.is_empty() == "True"){
            
        }
        else{

        }

    }


    return 0;
}
