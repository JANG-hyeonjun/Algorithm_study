#include <iostream>
#include <vector>
#include<cstring>

using namespace std;
string command;
int temp;
int * command_num = new int;


class Command
{
private:
    vector <int> V_list;
public:
    void add(int number);
    void remove(int number);
    void check(int number);
    void toggle(int number);
    void all();
    void empty();
};

void Command::add(int number) {
    
    V_list.push_back(number);
}
void Command::remove(int number) {

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
