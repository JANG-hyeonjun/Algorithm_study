#include <iostream>
using namespace std;
const int MAX = 1005;

class Tile{
private:
    long long int arr[MAX];
public:
    void Tiling(int num);
    void pnt_answer(int num);
};

void Tile::Tiling(int num) {
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i =2; i <= num; i++)
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;

}
void Tile::pnt_answer(int num) {
    cout << arr[num] % 10007;
}

int main() {

    Tile t1;
    int number;
    cin >> number;
    t1.Tiling(number);
    t1.pnt_answer(number);
    return 0;
}
