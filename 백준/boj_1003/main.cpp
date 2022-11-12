#include <iostream>

using namespace std;

const int MAX = 42;

struct box{
    int zero;
    int one;
};

box *arr = new box[MAX];
int *number = new int;
int Test_case;

int main() {

    arr[0].zero = 1;
    arr[1].zero = 0;
    arr[0].one = 0;
    arr[1].one = 1;

    for(int i =2; i < MAX; i++)
    {
        arr[i].zero = arr[i-2].zero + arr[i-1].zero;
        arr[i].one = arr[i-2].one + arr[i-1].one;
    }


    cin >> Test_case;
    for(int t =0; t < Test_case; t++)
    {
        cin >> *number;
        cout << arr[(*number)].zero <<' '<<arr[(*number)].one << '\n';

    }



    delete number;
    delete []arr;
    return 0;
}
