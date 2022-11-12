#include <iostream>

using namespace std;

const int MAX = 13;

int test_case;

int arr[MAX];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4; i <= MAX; i++)
    {
        for (int j = i-1; j >= i-3; j--)
        {
            arr[i] += arr[j];
        }
    }
    cin >> test_case;
    for(int i = 0; i < test_case; i++)
    {
        int number;
        cin >> number;
        cout << arr[number] << '\n';
    }


    return 0;
}
