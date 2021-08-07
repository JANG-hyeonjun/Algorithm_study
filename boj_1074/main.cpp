#include <iostream>
#include <cmath>

using namespace std;

int N,r,c;
int number;

void scan(int x,int y ,int n)
{


    if(x == r && y == c) {
        cout << number;
        return;
    }

    if(n >= 2)
    {
        if(r < x + n && r >= x && c < y + n && c >= y)
        {
            scan(x,y,n/2);
            scan(x,y+ n/2, n/2);
            scan(x+n/2,y,n/2);
            scan(x+n/2,y+n/2,n/2);
        }
        else{
            number += n * n;
        }
    }
    else
        number++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> r >> c;

    scan(0,0,(1 << N));
    return 0;
}
