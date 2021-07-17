#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100005;
struct information
{
    string name;
    int age;
    int sequence;
};

information person[MAX];

bool compare(information x,information y)
{
    if(x.age == y.age)
    {
        return x.sequence < y.sequence;
    }
    else return x.age < y.age;
}


int main() {
   int number;
    cin >> number;

    for(int i = 0; i < number; i++)
    {
        cin >> person[i].age >> person[i].name;
        person[i].sequence = i;
    }

    sort(person,person+number,compare);

    for(int i =0; i < number; i++)
    {
        cout << person[i].age <<' '<<person[i].name << '\n';
    }

    return 0;
}
