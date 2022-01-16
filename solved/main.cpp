#include <iostream>
#include <vector>

using namespace std;

int n;
int val_left,val_right;
vector<int> answer;
int main() {

    cin >> n >> val_left >> val_right;

    for (int i = 0; i < n; i++) {
        answer.push_back(i + 1);
    }
    int group = 1;
    for (int i = n; i < n * n; i++)
    {
        for(int j = 0; j < group; j++)
        {
            answer.push_back(answer[i - n] + 1);
            i++;
        }
        for(int k = 0; k < n- group; k++)
        {
            answer.push_back((answer[i - n]));
            i++;
        }
        i = i - 1;
        group++;
    }

    for(int i =0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";





    return 0;
}
