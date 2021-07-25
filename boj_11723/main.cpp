#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
string command;
int temp;
int * command_num = new int;
vector <int> V_list;
std::vector<int>::iterator it;

struct Command
{
public:
    void add(int number);
    void remove(int number);
    void check(int number);
    void toggle(int number);
    void all();
    void empty();
};

void Command::add(int number) {
    if(V_list.size() == 0) {
        V_list.push_back(number);
        return;
    }

    it = find(V_list.begin(),V_list.end(),number);

    if(it == V_list.end())
        V_list.push_back(number);
    else return;
}
void Command::remove(int number) {
    it = find(V_list.begin(),V_list.end(),number);

    if(it != V_list.end())
        V_list.erase(it);
    else return;
}

void Command::check(int number) {
    it = find(V_list.begin(),V_list.end(),number);

    if(it != V_list.end())
        cout << "1" << '\n';
    else
        cout << "0" << '\n';
}
void Command::toggle(int number) {
    it = find(V_list.begin(),V_list.end(),number);
    if (it != V_list.end())
        V_list.erase(it);
    else V_list.push_back(number);
}
void Command::all() {
    V_list.clear();
    for(int i = 1; i <= 20; i++)
        V_list.push_back(i);
}
void Command::empty() {
     V_list.clear();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> *command_num;
    Command com;

    for(int i=0; i < *command_num; i++)
    {
        cin >> command;
        if(command == "add") {
            cin >> temp;
            com.add(temp);
        }
        if(command == "remove")
        {
            cin >> temp;
            com.remove(temp);
        }
        if(command == "check")
        {
            cin >> temp;
            com.check(temp);
        }
        if(command == "toggle")
        {
            cin >> temp;
            com.toggle(temp);
        }
        if(command == "all")
        {
            com.all();
        }
        if(command == "empty")
        {
            com.empty();
        }
    }
    return 0;
}
