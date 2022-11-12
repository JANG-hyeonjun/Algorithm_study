#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
const int MAX = 20005;

vector<string> arr;
string temp;
int number;

bool comp(string s1,string s2)
{
        if(s1.size() == s2.size())
            return s1 < s2;
        return s1.size() < s2.size();
}

int main()
{
    scanf("%d",&number);
    for(int i =0 ; i < number; i++)
    {
       cin >> temp;
       //if(find(arr.begin(),arr.end(),temp) == arr.end())
       arr.push_back(temp);
    }


    sort(arr.begin(),arr.end(),comp);
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
   //중복을 제거하는 또다른 방법
    for(int i = 0; i < arr.size(); i++)
       cout << arr[i]<< endl;

    return 0;
}
