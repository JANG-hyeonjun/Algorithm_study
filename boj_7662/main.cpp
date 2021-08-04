#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

class doubleEndedQueue{
public:
    multiset <int> s;
    int size();
    string is_empty();
    void insert(int x);
    int get_start();
    int get_end();
    void delete_start();
    void delete_end();
    void clear();
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
    return * (s.rbegin());
}
void doubleEndedQueue::clear() {
    s.clear();
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int command;
        cin >> command;
        dq.clear();
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
                    dq.delete_end();
                }
                else{
                    dq.delete_start();
                }
            }
        }
        if(dq.is_empty() == "True"){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << dq.get_end() << " " << dq.get_start() << '\n';
        }

    }
    return 0;
}
