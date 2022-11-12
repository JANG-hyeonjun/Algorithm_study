#include <iostream>

using namespace std;

const int MAX = 1000005;

int arr[MAX];
int num_count ;
int * number = new int;

int main() {

    arr[1] = 0;
    cin >> num_count;

    for (int i = 2; i <= num_count; i++) {
        int num = i;
        arr[num] = arr[num - 1] + 1;

       // arr[num] = arr[num - 1] + 1;
        if(num % 2 == 0)
        {
              arr[num] = min(arr[i],arr[num / 2] + 1);
           // arr[num] = arr[num / 2] + 1;
        }
        if(num % 3 ==0)
        {
            arr[num] = min(arr[i],arr[num / 3] + 1);
        }
    }

  //  for(int i = 1; i <= 10; i++)
    //    cout << arr[i] << " ";

  //1284
  // cout << endl;

    cout << arr[num_count] << endl;
    delete number;
    return 0;
}
